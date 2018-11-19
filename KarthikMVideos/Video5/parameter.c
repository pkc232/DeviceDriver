#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>


int count=2;
module_param(count,int,0);

int my_init(void){
	int index=0;

	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	for(index=0;index<count;index++)
		printk(KERN_ALERT " jaa index =%d\n",index);
	return 0;		
}

void my_exit(void){
	printk(KERN_ALERT "inside the %s function\n",__FUNCTION__);

}

module_init(my_init);
module_exit(my_exit);