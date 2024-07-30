#include <linux/hid.h>
#include <linux/input.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>

// Define the VID and PID for the USB device (check with lsusb)
#define VENDOR_ID 0x044f
#define PRODUCT_ID 0xb67f

// Kernel module information
MODULE_LICENSE("GPL");
MODULE_AUTHOR("CyntexMore");
MODULE_DESCRIPTION("Linux kernel module for the Thrustmaster TMX Force "
                   "Feedback racing wheel.");
MODULE_VERSION("0.1");

static const struct usb_device_id tmx_id_table[] = {
    {USB_DEVICE(VENDOR_ID, PRODUCT_ID)}, {}};
MODULE_DEVICE_TABLE(usb, tmx_id_table);

// Probe function
static int tmx_probe(struct usb_interface *interface,
                     const struct usb_device_id *id) {
  printk(KERN_INFO "TMX Force Feedback Wheel connected\n");

  int value = 1;

  struct usb_ctrlrequest packet = {.bRequestType = 0x41,
                                   .bRequest = 83,
                                   .wValue = cpu_to_le16(value),
                                   .wIndex = 0,
                                   .wLength = 0};

  struct usb_device *device = interface_to_usbdev(iface);
  struct urb *tmxurb = usb_alloc_urb(0, GFP_KERNEL);

  usb_fill_control_urb(tmxurb, device, usb_sndctrlpipe(device, 0),
                       (unsigned char *)&packet, 0, 0, tmx_control_handler, 0);

  usb_submit_urb(tmxurb, GFP_KERNEL);

  usb_free_urb(tmxurb);

  return 0;
}

// Disconnect function
static void tmx_disconnect(struct usb_interface *interface) {
  printk(KERN_INFO "TMX Force Feedback Wheel disconnected\n");
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
