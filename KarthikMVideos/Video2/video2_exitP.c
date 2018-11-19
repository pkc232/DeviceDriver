#include <linux/init.h>
#include <linux/module.h>

void video2_exit(void){
	printk(KERN_ALERT, "Inside the %s function\n",__FUNCTION__);
	
}

module_exit(video2_exit);