#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/kernel.h>
#include<asm/uaccess.h>

MODULE_LICENSE("GPL");

#define buflen 1024

static int nc;
static char data[buflen];

ssize_t ex_read_fn (struct file *fptr, char __user *buffer, size_t length, loff_t *offset)
{
	printk("Inside reading part of device with function : %s \n",__FUNCTION__);
	copy_to_user(buffer,&data,1024);
	*offset += 1024; nc++;
	if(nc<=1) { return 1024; }
	else { return 0; }
}

ssize_t ex_write_fn (struct file *fptr, const char __user *buffer, size_t length, loff_t *offset)
{
	printk("Inside writinging part of device with function : %s \n",__FUNCTION__);
	copy_from_user(data,buffer,length);
        return length;
}

int ex_open_fn (struct inode *pinode, struct file *pfile)
{
	nc=0;
	printk("Opening the device with function : %s \n",__FUNCTION__);
        return 0;
}

int ex_close_fn (struct inode *pinode, struct file *pfile)
{
	printk("Closing the device with function : %s \n",__FUNCTION__);
        return 0;
}

struct file_operations ex_file_ops = {
        .owner = THIS_MODULE,
        .open = ex_open_fn,
        .read = ex_read_fn,
        .write = ex_write_fn,
        .release = ex_close_fn,
};


__init int ex_driver_init_function(void)
{
	printk(KERN_ALERT "This is inside the : %s \n",__FUNCTION__);
	register_chrdev(250,"Priyam's Char Device Driver",&ex_file_ops);
	return 0;
}

void ex_driver_exit_function(void)
{
	printk(KERN_ALERT "This is inside the : %s \n",__FUNCTION__);
	unregister_chrdev(250,"Priyam's Char Device Driver");
}

module_init(ex_driver_init_function);
module_exit(ex_driver_exit_function);
