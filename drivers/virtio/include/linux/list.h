#ifndef __LINUX_LIST_H__
#define __LINUX_LIST_H__

/*4*/ #include <linux/types.h>
/*5*/ #include <linux/stddef.h>
/*7*/ #include <linux/const.h>
/*19*/ #define LIST_HEAD_INIT(name) { &(name), &(name) }
/*21*/ #define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)
/*28*/ void INIT_LIST_HEAD(struct list_head * a);
/*63*/ void list_add(struct list_head * a, struct list_head * b);
/*77*/ void list_add_tail(struct list_head * a, struct list_head * b);
/*109*/ void list_del(struct list_head * a);
/*189*/ int list_empty(const struct list_head * a);
/*350*/ #define list_entry(ptr,type,member) container_of(ptr, type, member)
/*361*/ #define list_first_entry(ptr,type,member) list_entry((ptr)->next, type, member)
/*418*/ #define list_for_each_entry(pos,head,member) for (pos = list_entry((head)->next, typeof(*pos), member); &pos->member != (head); pos = list_entry(pos->member.next, typeof(*pos), member))
/*492*/ #define list_for_each_entry_safe(pos,n,head,member) for (pos = list_entry((head)->next, typeof(*pos), member), n = list_entry(pos->member.next, typeof(*pos), member); &pos->member != (head); pos = n, n = list_entry(n->member.next, typeof(*n), member))

#endif
