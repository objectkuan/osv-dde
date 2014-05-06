#include "dde-pci.h"

#include <map>
#include <list>
#include <interrupt.hh>
#include <osv/debug.h>
#include "drivers/pci-device.hh"

std::map<pci::device*, std::pair<interrupt_manager *, int> > msix_managers;
extern std::map<int, struct msix_detail > msix_vectors;

struct msix_entry {
	u32 vector;
	u16 entry;
};

void *dde_map_bar(void *dev, int bar_id) {
    void *base;

    // Bar IDs in Linux start from 0, while those in OSv start from 1.
    // Adjust the bar to be mapped here
    bar_id += 1;

    pci::device *pci_dev = (pci::device *)(dev);
    pci::bar *bar = pci_dev->get_bar(bar_id);
    if (bar == nullptr)
        return 0;

    if (bar->is_pio()) {
        base = (void *)(PIO_OFFSET + bar->get_addr64());
    } else {
        bar->map();
        base = (void *)bar->get_mmio();
    }

    return base;
}

void dde_set_master(void *dev) {
    pci::device *pci_dev = (pci::device *)(dev);
    pci_dev->set_bus_master(true);
}

void dde_enable_msix(void *dev, struct msix_entry *entries, int nr_entry) {
    pci::device *pci_dev = (pci::device *)(dev);
    interrupt_manager *intr_mgr = msix_managers[pci_dev].first;

    if (intr_mgr == 0) {
        msix_managers[pci_dev].first = intr_mgr = new interrupt_manager(pci_dev);
        msix_managers[pci_dev].second = 0;
        pci_dev->msix_enable();
    }

    int idx = msix_managers[pci_dev].second;
    /* Workaround the bug in std::vector which may contain invalid values */
    for (; nr_entry > 0; nr_entry --) {
        std::vector<msix_vector*> new_vectors = intr_mgr->request_vectors(1);
        for (auto vec : new_vectors) {
            entries[idx].entry = idx;
            entries[idx].vector = vec->get_vector() | 0x80000000;
            msix_vectors[vec->get_vector()].mgr = intr_mgr;
            msix_vectors[vec->get_vector()].entry = idx;
            msix_vectors[vec->get_vector()].vec = vec;
            idx ++;
        }
    }
    msix_managers[pci_dev].second = idx;
}
