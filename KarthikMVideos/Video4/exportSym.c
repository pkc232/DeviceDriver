#include <linux/init.h>
#include <linux/module.h>

int vid4_module_func(void){
	printk(KERN_ALERT "DOing the %s function ",__FUNCTION__);
	return 0;
}

EXPORT_SYMBOL(vid4_module_func);
int my_init(void){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	vid4_module_func();
	return 0;
}


void my_exit(void){
	printk(KERN_ALERT "Insidethe %s function\n",__FUNCTION__);	
}


module_init(my_init);
module_exit(my_exit);