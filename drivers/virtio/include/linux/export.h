#ifndef __LINUX_EXPORT_H__
#define __LINUX_EXPORT_H__

/*16*/ #define MODULE_SYMBOL_PREFIX ""
/**23**/ struct kernel_symbol {
};
/*29*/ #define THIS_MODULE ((struct module *)0)
/*60*/ #define EXPORT_SYMBOL(sym) __EXPORT_SYMBOL(sym, "")
/*63*/ #define EXPORT_SYMBOL_GPL(sym) 

#endif
