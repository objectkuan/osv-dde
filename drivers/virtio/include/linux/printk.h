#ifndef __LINUX_PRINTK_H__
#define __LINUX_PRINTK_H__

/*12*/ #define KERN_ERR "<3>"
/*13*/ #define KERN_WARNING "<4>"
/*15*/ #define KERN_INFO "<6>"
/*16*/ #define KERN_DEBUG "<7>"
/*89*/ int no_printk(const char * a, ...);
/*101*/ int printk(const char * a, ...);
/*108*/ int __printk_ratelimit(const char * a);
/*109*/ #define printk_ratelimit() __printk_ratelimit(__func__)
/*152*/ #ifndef pr_fmt
#define pr_fmt(fmt) fmt
#endif
/*191*/ #define pr_debug(fmt,...) no_printk(KERN_DEBUG pr_fmt(fmt), ##__VA_ARGS__)

#endif
