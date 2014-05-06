#include "dde-thread.h"
#include "dde-pci.h"

#include <map>
#include <sched.hh>
#include <interrupt.hh>
#include <osv/mutex.h>
#include <api/time.h>

struct work_struct;

struct work {
    struct timespec fire;
    void (*func)(struct work_struct *);
    struct work *next;
};

struct workqueue {
    sched::thread *thread;
    mutex _mtx;

    struct timespec next_work_time;
    struct work *worklist;
} global_wq = { 0 };

static void timespec_sub(struct timespec &lhs, const struct timespec &rhs) {
    if (lhs.tv_nsec < rhs.tv_nsec) {
        lhs.tv_sec -= 1;
        lhs.tv_nsec += 1000000000;
    }
    lhs.tv_sec -= rhs.tv_sec;
    lhs.tv_nsec -= rhs.tv_nsec;
}

static int timespec_compare(const struct timespec &lhs, const struct timespec &rhs) {
    if (lhs.tv_sec < rhs.tv_sec)
        return -1;
    if (lhs.tv_sec > rhs.tv_sec)
        return 1;
    return lhs.tv_nsec - rhs.tv_nsec;
}

void worker() {
    struct timespec current, req;
    struct work *current_work;
    for (;;) {
        clock_gettime(CLOCK_REALTIME, &current);
        while (global_wq.worklist) {
            current_work = global_wq.worklist;
            if (timespec_compare(current_work->fire, current) > 0)
                break;

            global_wq.worklist = current_work->next;
            current_work->func(0);
        }
        // TODO Determine when to wake up next time based on current works
        global_wq.next_work_time = current;
        global_wq.next_work_time.tv_sec += 1;

        req = global_wq.next_work_time;
        timespec_sub(req, current);
        nanosleep(&req, 0);
    }
}

void dde_init_workqueue(void) {
    if (global_wq.thread != 0)
        return;

    global_wq.thread = new sched::thread([&] { worker(); });
    global_wq.thread->start();
    global_wq.worklist = 0;
}

std::map<int, gsi_edge_interrupt* > gsi_vectors;
std::map<int, struct msix_detail > msix_vectors;

void dde_gsi_request_irq(unsigned int irq, irq_handler_t handler, void *dev) {
    gsi_vectors[irq] = new gsi_edge_interrupt(irq, [&] { handler(irq, dev); });
}

void dde_msix_request_irq(unsigned int irq, irq_handler_t handler, void *dev) {
    irq &= ~IRQ_MSIX_FLAG;
    struct msix_detail &d = msix_vectors[irq];
    interrupt_manager *mgr = d.mgr;
    int entry = d.entry;
    msix_vector *vec = d.vec;

    mgr->assign_isr(vec, [=] { handler(irq, dev); });
    mgr->setup_entry(entry, vec);
    vec->msix_unmask_entries();
}
