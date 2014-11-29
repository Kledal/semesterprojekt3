#include <linux/err.h>
#include <linux/ctype.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/input.h>
#include <linux/module.h>
#include "psoc-spi.h"
/*
#define PSOC_MAJOR       64
#define PSOC_MINOR        0
#define MAXLEN              16
#define NBR_PSOC_CH           4		//Number of psoc channels (minor number)
#define COMPLIMENTARY_BIT   11

#define MODULE_DEBUG 0
*/

/* Sysfs class and device */
struct class *sysfs_class;
struct device *sysfs_device;

int PSOC_MAJOR = 64;

/* Macro to handle Errors */
#define ERRGOTO(label, ...)                     \
  {                                             \
  printk (__VA_ARGS__);                         \
  goto label;                                   \
  } while(0)

/* Char Driver Globals */
static struct cdev *psocDev;
//struct file_operations psoc_fops;
static int devno;

/* Pointer to SPI Device */
static struct spi_device *psoc_spi_device = NULL;



/* Sysfs "read" method */
static ssize_t speed_show(struct device *dev, struct device_attribute *attr, char *buf)
{
  u16 result;
  printk(KERN_ALERT "Reading speed from psoc\n");
   
  //Read speed has the address 0
  int err = psoc_spi_read_reg16(psoc_spi_device, 0, &result);
  if (err)
    return -EFAULT;

  printk(KERN_ALERT "result: %d", result);

  return sprintf(buf, "%d\n", result);
}


/* Sysfs "read" method */
static ssize_t battery_show(struct device *dev, struct device_attribute *attr, char *buf)
{
  u16 result;

  printk(KERN_ALERT "Reading battery from psoc\n");
   
  //Read battery has the address 1
  int err = psoc_spi_read_reg16(psoc_spi_device, 1, &result);
  if (err)
    return -EFAULT;

  printk(KERN_ALERT "result: %d", result);

  return sprintf(buf, "%d\n", result);
}


/* Macro to create attributes */
static struct device_attribute led_class_attrs[] = {
    __ATTR(speed, 0606, speed_show, NULL),
    __ATTR(battery, 0606, battery_show, NULL),
    __ATTR_NULL,
};


static int __init psoc_cdrv_init(void)
{
  int err; 
  
  printk("PSoC driver initializing\n");  
  /*	REGISTER SPI DRIVER	*/
  err = psoc_spi_init();
  if(err)
    ERRGOTO(error, "Failed to initialize spi psoc");
  
  /* Allocate chrdev region */
  devno = MKDEV(PSOC_MAJOR, 0);
   //alloc_chrdev_region (&devno, minornumber, number_of_minors, "name")
  if((err=alloc_chrdev_region(&devno, 0, 1, "psoc_driver"))<0){
    ERRGOTO(err_dev_init, "Failed registering char region (%d), error %d\n", PSOC_MAJOR, err);
  }


  psocDev = cdev_alloc();

  cdev_init(psocDev, psocDev->ops); // Cdev Init
  err = cdev_add(psocDev, 1, 1);  // Add Cdev
  if (err)
    ERRGOTO(err_register, "Error %d adding Fake PSOC device\n", err);
  
  //sysfs
  sysfs_class = class_create(THIS_MODULE, "psoc");
  
  sysfs_class->dev_attrs = led_class_attrs;
  sysfs_device = device_create(sysfs_class, NULL, devno, NULL, "psoc1");

  return 0;
  
  /* ERROR HANDLING */
  err_register:
  unregister_chrdev_region(devno, 1);

  err_dev_init:
  psoc_spi_exit();
 
  error:
  return err;
}

static void __exit psoc_cdrv_exit(void)
{
  cdev_del(psocDev); // Delete Cdev
  unregister_chrdev_region(devno, 1); // Unregister Device
  
  device_destroy(sysfs_class, devno);
  class_destroy(sysfs_class);

  psoc_spi_exit();

  printk(KERN_INFO "Success fully unloaded psoc driver.\n");
}

module_init(psoc_cdrv_init);
module_exit(psoc_cdrv_exit);

MODULE_AUTHOR("GRUPPE 1");
MODULE_LICENSE("GPL");

