#include <linux/err.h>
#include <linux/ctype.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/input.h>
#include <linux/module.h>
#include <linux/export.h>
#include <linux/kernel.h> 

/* Macro to handle Errors */
#define ERRGOTO(label, ...)                     \
  {                                             \
  printk (__VA_ARGS__);                         \
  goto label;                                   \
  } while(0)

int PSOC_MAJOR = 65;

/* Char Driver Globals */
static struct cdev *psocDev;
static int devno;

/* Sysfs class and device */
struct class *sysfs_class;
struct device *sysfs_device;

/* Variable to hold the data */
u16 speed = 0;
u16 battery = 0;


/* Sysfs "read" method */
static ssize_t speed_show(struct device *dev, struct device_attribute *attr, char *buf)
{
  return sprintf(buf, "%d\0", speed);
}

/* Sysfs "write" method */
static ssize_t speed_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t size)
{
  long temp_speed;
  kstrtol(buf, 10, &temp_speed);

  speed = (int)temp_speed;

  return size;
}

/* Sysfs "read" method */
static ssize_t battery_show(struct device *dev, struct device_attribute *attr, char *buf)
{
  return sprintf(buf, "%d\0", battery);
}

/* Sysfs "write" method */
static ssize_t battery_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t size)
{
  long temp_battery;
  kstrtol(buf, 10, &temp_battery);

  battery = (int)temp_battery;

  return size;
}

/* Macro to create attributes */
static struct device_attribute led_class_attrs[] = {
    __ATTR(speed, 0666, speed_show, speed_store),
    __ATTR(battery, 0666, battery_show, battery_store),
    __ATTR_NULL,
};


static int __init psoc_cdrv_init(void)
{
  int err;

  devno = MKDEV(PSOC_MAJOR, 0);
  //alloc_chrdev_region (&devno, minornumber, number_of_minors, "name")
  if((err=alloc_chrdev_region(&devno, 0, 1, "fake_psoc_driver"))<0){
  ERRGOTO(err_dev_init, "Failed registering char region (%d), error %d\n", PSOC_MAJOR, err);
  }

  psocDev = cdev_alloc(  );

  cdev_init(psocDev, psocDev->ops); // Cdev Init
  err = cdev_add(psocDev, 1, 1);  // Add Cdev
  if (err)
    ERRGOTO(err_register, "Error %d adding Fake PSOC device\n", err);
  
  
  //sysfs
  sysfs_class = class_create(THIS_MODULE, "fake_psoc");
  
  sysfs_class->dev_attrs = led_class_attrs;
  sysfs_device = device_create(sysfs_class, NULL, devno, NULL, "fake_psoc1");
  
  printk("Finish initialize\n");

  return 0;

  err_register:
  unregister_chrdev(PSOC_MAJOR, "sys_led"); // Unregister Device
  
  err_dev_init:
  
  return err;
}

static void __exit psoc_cdrv_exit(void)
{
  cdev_del(psocDev); // Delete Cdev
  unregister_chrdev(PSOC_MAJOR, "sys_led"); // Unregister Device
  
  device_destroy(sysfs_class, devno);
  class_destroy(sysfs_class);
  
  printk(KERN_INFO "Success fully unloaded.\n");
}





module_init(psoc_cdrv_init);
module_exit(psoc_cdrv_exit);

MODULE_AUTHOR("Gruppe 1");
MODULE_LICENSE("GPL");

