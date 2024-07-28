#include <linux/hid.h>
#include <linux/input.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>

#define VENDOR_ID 0x044f
#define PRODUCT_ID 0xb67f

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CyntexMore");
MODULE_DESCRIPTION("Linux kernel module for the Thrustmaster TMX Force "
                   "Feedback racing wheel.");
MODULE_VERSION("0.1");

static const struct usb_device_id tmx_id_table[] = {
    {USB_DEVICE(VENDOR_ID, PRODUCT_ID)}, {}};
MODULE_DEVICE_TABLE(usb, tmx_id_table);

static int tmx_probe(struct usb_interface *interface,
                     const struct usb_device_id *id) {
  printk(KERN_INFO "TMX Force Feedback Wheel connected\n");
  // To be implemented
  // TODO: -
  return 0;
}

static void tmx_disconnect(struct usb_interface *interface) {
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

static int __init tmx_init(void) { return usb_register(&tmx_driver); }

static void __exit tmx_exit(void) { usb_deregister(&tmx_driver); }

module_init(tmx_init);
module_exit(tmx_exit);
