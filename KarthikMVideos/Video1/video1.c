#include <linux/init.h>
#include <linux/module.h>


int video1_init(void){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return 0;
}


void video1_exit(void){
	printk(KERN_ALERT "Insidethe %s function\n",__FUNCTION__);	
}


module_init(video1_init);
module_exit(video1_exit);