#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
/*to hold file ops*/
int eg6_open (struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return 0;
}
ssize_t eg6_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return 0;
}
ssize_t eg6_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return length;
}
int eg6_close (struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return 0;
}


struct  file_operations eg6_file_operations={
	.owner   =THIS_MODULE,
	.open    = eg6_open,
	.read    = eg6_read,
	.write   = eg6_write,
	.release = eg6_close,
	
};


int my_init(void){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	
	//register a character device
	register_chrdev(240/*major No*/,"simple char drv"/*Name of driver*/,&eg6_file_operations/*file op*/);

	return 0;
}


void my_exit(void){
	printk(KERN_ALERT "Insidethe %s function\n",__FUNCTION__);	
	/*unregister the char device driver*/
	unregister_chrdev(240,"simple char drv");	
}


module_init(my_init);
module_exit(my_exit);