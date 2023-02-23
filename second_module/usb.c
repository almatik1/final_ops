#include <linux/module.h>
#include <linux/init.h>
#include <linux/usb.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("ALMAT, BEKZAT, ARTEM, SHYNGYS, ASYLKHAN");
MODULE_DESCRIPTION("USB");


static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	printk(KERN_INFO "[*] LOGITECH MOUSE HAVE BEEN PLUGGED\n", id->idVendor, id->idProduct);
	return 0;
}

static void pen_disconnect(struct usb_interface *interface){
	printk(KERN_INFO "[*] LOGITECH MOUSE REMOVED \n");
}


static struct usb_device_id pen_table[] = {
	{USB_DEVICE(0x046d, 0xc084)},
	{}
};

MODULE_DEVICE_TABLE(usb, pen_table);

static struct usb_driver pen_driver = 
{
	.name = "USB-DRIVER",
	.id_table = pen_table,
	.probe = pen_probe,
	.disconnect = pen_disconnect,
};


static int __init mouse_init(void){
	int ret = -1;
	printk(KERN_INFO "CONSTRUCTOR OF DRIVER" );
	printk(KERN_INFO "\tREGISTERING DRIVER WITH KERNEL");
	ret = usb_register(&pen_driver);
	printk(KERN_INFO "REGISTRATION IS COMPLETE");
	return ret;
}


static void __exit mouse_exit(void){
        printk(KERN_INFO "DESTRUCTOR OF DRIVER" );
        usb_deregister(&pen_driver);
        printk(KERN_INFO "UNREGISTRATION COMPLETE!");

}


module_init(mouse_init);
module_exit(mouse_exit);
