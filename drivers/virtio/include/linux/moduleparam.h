#ifndef __LINUX_MODULEPARAM_H__
#define __LINUX_MODULEPARAM_H__

/*5*/ #include <linux/stringify.h>
/*6*/ #include <linux/kernel.h>
/*17*/ #define MAX_PARAM_PREFIX_LEN (64 - sizeof(unsigned long))
/*19*/ #define ___module_cat(a,b) __mod_ ## a ## b
/*20*/ #define __module_cat(a,b) ___module_cat(a,b)
/*28*/ #define __MODULE_INFO(tag,name,info) struct __module_cat(name,__LINE__) {}
/*31*/ #define __MODULE_PARM_TYPE(name,_type) __MODULE_INFO(parmtype, name##type, #name ":" _type)
/*36*/ #define MODULE_PARM_DESC(_parm,desc) __MODULE_INFO(parm, _parm, #_parm ":" desc)
/*51*/ #define KPARAM_ISBOOL 2
/**63**/ struct kernel_param {
	union { void * arg; const struct kparam_string * str; const struct kparam_array * arr; };
};
/*106*/ #define module_param(name,type,perm) 
/*120*/ #define module_param_named(name,value,type,perm) 
/*133*/ #define module_param_cb(name,ops,arg,perm) 
/*144*/ #define __moduleparam_const const
/*149*/ #define __module_param_call(prefix,name,ops,arg,isbool,perm) static int __param_perm_check_##name __attribute__((unused)) = BUILD_BUG_ON_ZERO((perm) < 0 || (perm) > 0777 || ((perm) & 2)) + BUILD_BUG_ON_ZERO(sizeof(""prefix) > MAX_PARAM_PREFIX_LEN); static const char __param_str_##name[] = prefix #name; static struct kernel_param __moduleparam_const __param_##name __used __attribute__ ((unused,__section__ ("__param"),aligned(sizeof(void *)))) = { __param_str_##name, ops, perm, isbool ? KPARAM_ISBOOL : 0, { arg } }
/*162*/ #define module_param_call(name,set,get,arg,perm) 
/*246*/ #define core_param(name,var,type,perm)
/*262*/ #define module_param_string(name,string,len,perm) 
/*397*/ #define module_param_array_named(name,array,type,nump,perm) 

#endif
