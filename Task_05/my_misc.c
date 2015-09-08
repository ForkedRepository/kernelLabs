#include <linux/module.h>	/*module*/
#include <linux/miscdevice.h>	/*misc_devices*/
#include <linux/string.h>	/*strlen, ctrcmp*/
#include <linux/fs.h>		/*struct file_operations*/
#include <linux/uaccess.h>	/*copy_*_user*/

static const char *password = "fogale\n";

static ssize_t misc_read(struct file *file, char __user *buf,
			 size_t count, loff_t *ppos)
{
	ssize_t retval = 0;
	size_t id_len = strlen(password);

	if (*ppos >= id_len)
		goto out;
	if (*ppos + count > id_len)
		count = id_len - *ppos;
	if (copy_to_user(buf, password + *ppos, count)) {
		retval = -EFAULT;
		goto out;
	}
	*ppos += count;
	retval = count;
out:
	return retval;
}

static ssize_t misc_write(struct file *file, const char __user *buf,
			  size_t count, loff_t *ppos)
{
	ssize_t retval = 0;
	size_t id_len = strlen(password);
	char kbuf[id_len + 1];

	if (count > id_len) {
		retval = -EINVAL;
		goto out;
	}

	if (copy_from_user(kbuf, buf, count)) {
		retval = -EFAULT;
		goto out;
	}

	kbuf[id_len] = '\0';

	if (!strcmp(kbuf, password))
		retval = count;
	else
		retval = -EINVAL;
out:
	return retval;
}

static const struct file_operations misc_fops = {
	.owner = THIS_MODULE,
	.read = misc_read,
	.write = misc_write
};

static struct miscdevice misc_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "fogale",
	.fops = &misc_fops,
};

static int __init misc_init(void)
{
	int retval;

	retval = misc_register(&misc_dev);

	if (retval)
		return retval;
	pr_info("My Misc minor number : %i\n", misc_dev.minor);
	return 0;
}

static void __exit misc_cleanup(void)
{
	int retval;

	retval = misc_deregister(&misc_dev);
	if (retval)
		pr_err("Fail to deregister my Misc Driver\n");
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("TASK 05");

module_init(misc_init);
module_exit(misc_cleanup);
