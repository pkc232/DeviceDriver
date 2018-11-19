#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>


int myopen (struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Someone opened me\n");
	return 0;
}
ssize_t myread (struct file *pfile, char __user *buffer, size_t length, loff_t *offset){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return 0;
}
ssize_t mywrite (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset){
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	return length;
}
int myclose (struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "SOmeone closed me\n");
	return 0;
}


struct fileoperations my_file_operations ={
	.owner = THIS_MODULE,
	.open = myopen,
	.release = myclose,
	.read = myread,
	.write = mywrite,
};

int my_init(void){
	printk(KERN_ALERT "lets begin the clock\n");
	
	//register a character device
	register_chrdev(240,"MyClock",&my_file_operations);

	return 0;
}


void my_exit(void){
	printk(KERN_ALERT "and the clock goes off\n");	
	/*unregister the char device driver*/
	unregister_chrdev(240,"MyClock");	
}

MODULE_LICENSE("GPL");

module_init(my_init);
module_exit(my_exit);


