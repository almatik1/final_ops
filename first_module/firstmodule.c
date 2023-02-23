#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ALMAT, ASYLKHAN, BEKZAT, ARTEM, SHYNGYS");
MODULE_DESCRIPTION("HELLO ARAILYM TLEUBAYEVA <3");


static int __init first_init(void){
	printk("Hello, kernel!");
	return 0;
}

static void __exit first_exit (void){
	printk("GOODBYE");
}

module_init(first_init);
module_exit(first_exit);




