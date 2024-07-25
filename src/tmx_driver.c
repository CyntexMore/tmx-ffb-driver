#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
#include <linux/hid.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CyntexMore");
MODULE_DESCRIPTION("Linux kernel modules for the Thrustmaster TMX Force Feedback racing wheel.");
MODULE_VERSION("0.1");

static const struct usb_device_id tmx_id_table[] = {
    { USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT, USB_INTERFACE_PROTOCOL_MOUSE) },
    { }
};
MODULE_DEVICE_TABLE(usb, tmx_id_table);

static int tmx_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "TMX Force Feedback Wheel connected\n");
    // To be implemented
    // TODO: -
    return 0;
}

static void tmx_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "TMX Force Feedback Wheel disconnected\n");
    // To be implemented
    // TODO: -
}

static struct usb_driver tmx_driver = {
    .name = "tmx_driver",
    .id_table = tmx_id_table,
    .probe = tmx_probe,
    .disconnect = tmx_disconnect,
};

static int __init tmx_init(void)
{
    return usb_register(&tmx_driver);
}

static void __exit tmx_exit(void)
{
    usb_deregister(&tmx_driver);
}

module_init(tmx_init);
module_exit(tmx_exit);
