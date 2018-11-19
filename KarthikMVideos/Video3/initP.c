#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
int my_init(void){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return 0;
}

module_init(my_init);
