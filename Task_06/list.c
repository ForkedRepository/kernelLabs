#include <linux/module.h>	/*module*/
#include <linux/string.h>	/*strlen, ctrcmp*/
#include <linux/fs.h>		/*struct file_operations*/
#include <linux/list.h>		/*list*/

struct identity {
	char name[20];
	int id;
};

static LIST_HEAD(identity_list);

static int identity_create(char *name, int id)
{
	return 0;
}

static void identity_destroy(int id)
{
}

struct identity *identity_find(int id)
{
	return NULL;
}

static int __init list_init(void)
{
	struct identity *temp;

	identity_create("Alice", 1);
	identity_create("Bob", 2);
	identity_create("Dave", 3);
	identity_create("Gena", 10);

	temp = identity_find(3);
	if (!temp)
		pr_err("Ooops: id 3 not found\n");
	else
		pr_info("id 3 = %s\n", temp->name);

	temp = identity_find(42);
	if (!temp)
		pr_info("id 42 not found\n");
	else
		pr_err("Ooops: id 42 found\n");

	return 0;
}

static void __exit list_cleanup(void)
{
	identity_destroy(2);
	identity_destroy(1);
	identity_destroy(10);
	identity_destroy(42);
	identity_destroy(3);
}

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("TASK 06");

module_init(list_init);
module_exit(list_cleanup);
