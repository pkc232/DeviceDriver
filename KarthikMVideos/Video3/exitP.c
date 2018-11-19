#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
void my_exit(void){
	printk(KERN_ALERT "Insidethe %s function\n",__FUNCTION__);	
}

module_exit(my_exit);