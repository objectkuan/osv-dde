#ifndef __LINUX_VMSTAT_H__
#define __LINUX_VMSTAT_H__

/*4*/ #include <linux/types.h>
/*5*/ #include <linux/percpu.h>
/*6*/ #include <linux/mm.h>
/*8*/ #include <linux/vm_event_item.h>
/*50*/ void all_vm_events(unsigned long * a);

#endif
