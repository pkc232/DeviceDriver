#include <linux/init.h>
#include <linux/module.h>

int video2_init(void){
	printk(KERN_ALERT, "Inside the %s function\n",__FUNCTION__);
	return 0;
}

module_init(video2_init);