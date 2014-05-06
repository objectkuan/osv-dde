#ifndef __LINUX_CPUMASK_H__
#define __LINUX_CPUMASK_H__

/*9*/ #include <linux/kernel.h>
/*27*/ extern int nr_cpu_ids;
/*78*/ extern const struct cpumask *const cpu_possible_mask;
/*175*/ unsigned int cpumask_next(int a, const struct cpumask * b);
/*202*/ #define for_each_cpu(cpu,mask) for ((cpu) = -1; (cpu) = cpumask_next((cpu), (mask)), (cpu) < nr_cpu_ids;)
/*694*/ #define for_each_possible_cpu(cpu) for_each_cpu((cpu), cpu_possible_mask)

#endif
