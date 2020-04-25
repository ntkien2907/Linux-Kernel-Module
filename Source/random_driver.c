#include <linux/module.h> 	/* thu vien dinh nghia cac macro nhu module_init va module_exit */
#include <linux/fs.h> 		/* thu vien dinh nghia cac ham cap phat/giai phong device number */
#include <linux/random.h>
#include <linux/init.h>

#define DRIVER_AUTHOR "Kien-Thanh-Phap <j13daian@gmail.com>"
#define DRIVER_DESC   "Character device driver creates numbers randomly"
#define DRIVER_VERSION "1"

static int random_driver_open(struct inode*, struct file*);
static int random_driver_release(struct inode*, struct file*);
static ssize_t random_driver_read(struct file*, char*, size_t, loff_t*); 

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = random_driver_open,
	.release = random_driver_release,
	.read = random_driver_read,
};
static int major;

/******************************** OS specific - START *******************************/

/* cac ham entry points */
static int random_driver_open(struct inode *inode, struct file *flip) {
	printk("Random device is opening\n");
	return 0;
}

static int random_driver_release(struct inode *inode, struct file *flip) {
	printk("Closing device successfully\n");
	return 0;
}

static ssize_t random_driver_read(struct file *flip, char *user_buf, size_t len, loff_t *off) {	
	int rand;
	get_random_bytes(&rand, sizeof(rand));
	return rand;
}

/* ham khoi tao driver */
static int __init random_driver_init(void) 
{	
	/* cap phat device number */
	major = register_chrdev(0, "random_device", &fops);
	if (major < 0)
		printk("Fail to register device number dynamically\n");	
	else 
		printk("Allocated device number (%d,0)\n", major);
	
	return 0;
}

/* ham ket thuc driver */
static void __exit random_driver_exit(void) {	
	unregister_chrdev(major, "random_device"); 
	printk("~ Exit random driver ~\n");
}
/********************************* OS specific - END ********************************/

module_init(random_driver_init);
module_exit(random_driver_exit);

MODULE_LICENSE("GPL"); /* giay phep su dung cua module */
MODULE_AUTHOR(DRIVER_AUTHOR); /* tac gia cua module */
MODULE_DESCRIPTION(DRIVER_DESC); /* mo ta chuc nang cua module */
MODULE_VERSION(DRIVER_VERSION); /* mo ta phien ban cua module */
MODULE_SUPPORTED_DEVICE("testdevice"); /* kieu device ma module ho tro */
