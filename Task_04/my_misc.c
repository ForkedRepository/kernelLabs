#include <linux/init.h>
#include <linux/module.h>

/* Add your code here */

static const struct file_operations misc_fops = {
        /* Add your code here */
	.owner = THIS_MODULE,
};

static struct miscdevice misc_dev = {
        /* Add your code here */
};

static int __init misc_init(void)
{
        /* Add your code here */
	return 0;
}

static void __exit misc_cleanup(void)
{
        /* Add your code here */
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("TASK 04");

module_init(misc_init);
module_exit(misc_cleanup);
