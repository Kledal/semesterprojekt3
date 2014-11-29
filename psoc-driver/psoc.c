#include <linux/err.h>
#include <linux/ctype.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/input.h>
#include <linux/module.h>
#include "psoc-spi.h"

#define PSOC_MAJOR       64
#define PSOC_MINOR        0
#define MAXLEN              16
#define NBR_PSOC_CH           4		//Number of psoc channels (minor number)
#define COMPLIMENTARY_BIT   11

#define MODULE_DEBUG 0

/* Macro to handle Errors */
#define ERRGOTO(label, ...)                     \
  {                                             \
  printk (__VA_ARGS__);                         \
  goto label;                                   \
  } while(0)

/* Char Driver Globals */
static struct cdev psocDev;
struct file_operations psoc_fops;
static int devno;

/* Pointer to SPI Device */
static struct spi_device *psoc_spi_device = NULL;

/* 
 * LOCAL METHODS
 */


/*
 * PUBLIC METHODS
 */

static int __init psoc_cdrv_init(void)
{
  int err; 
  
  printk("PSoC driver initializing\n");  
  /*	REGISTER SPI DRIVER	*/
  err = psoc_spi_init();
  if(err)
    ERRGOTO(error, "Failed to initialize spi psoc");
  
  /* Allocate chrdev region */
  devno = MKDEV(PSOC_MAJOR, PSOC_MINOR);
  err = register_chrdev_region(devno, NBR_PSOC_CH, "psoc");  
  if(err)
    ERRGOTO(err_spi_init, "Failed registering char region (%d,%d) +%d, error %d\n", PSOC_MAJOR, PSOC_MINOR, NBR_PSOC_CH, err);
  
  /* Register Char Device */
  cdev_init(&psocDev, &psoc_fops);
  err = cdev_add(&psocDev, devno, NBR_PSOC_CH);
  if (err)
    ERRGOTO(err_register, "Error %d adding PSOC device\n", err);
  
  return 0;
  
  /* ERROR HANDLING */
  err_register:
  unregister_chrdev_region(devno, NBR_PSOC_CH);

  err_spi_init:
  psoc_spi_exit();
 
  error:
  return err;
}

static void __exit psoc_cdrv_exit(void)
{
  printk("psoc driver Exit\n");

  cdev_del(&psocDev);	//Freeing the device
  
  unregister_chrdev_region(devno, NBR_PSOC_CH);		//Unregister device numbers

  psoc_spi_exit();
}

int psoc_cdrv_open(struct inode *inode, struct file *filep)
{  
  int major = imajor(inode);
  int minor = iminor(inode);

  printk("Opening PSoC Device [major], [minor]: %i, %i\n", major, minor);

  /* Check if minor number is within range */
  if (minor > NBR_PSOC_CH-1)
  {
    printk("Minor no out of range (0-%i): %i\n", NBR_PSOC_CH, minor);
    return -ENODEV;
  }

  /* Check if a psoc device is registered */
  if(!(psoc_spi_device=psoc_get_device()))
    return -ENODEV;
  
  return 0;
}

int psoc_cdrv_release(struct inode *inode, struct file *filep)
{
  int major = imajor(inode);
  int minor = iminor(inode);

  printk("Closing PSoC Device [major], [minor]: %i, %i\n", major, minor);

  if ((minor > NBR_PSOC_CH-1) || !(psoc_spi_device=psoc_get_device()))
    return -ENODEV;
    
  return 0;
}

ssize_t psoc_cdrv_write(struct file *filep, const char __user *ubuf, 
                           size_t count, loff_t *f_pos)
{
  int minor, len, value;
  char kbuf[MAXLEN];    
  
  minor = MINOR(filep->f_dentry->d_inode->i_rdev);	//Finding minor number
  
  
  /* Limit copy length to MAXLEN allocated andCopy from user */
  len = count < MAXLEN ? count : MAXLEN;
  if(copy_from_user(kbuf, ubuf, len))	//copy_from_user(to, from, number_of_bytes)
    return -EFAULT;
  
  /* Pad null termination to string, inserting \0 at the end so kbuf is now a string */
  kbuf[len] = '\0';  
  
  /* Convert sting to int, so we can transfer it over SPI as bits representation */
  sscanf(kbuf,"%i", &value);	// sscanf(from, format(int), to)
  if(MODULE_DEBUG)
    printk("value %i\n", value);
  

  printk(KERN_ALERT "Writing [Data] %i to psoc [Minor] %i \n", value, minor);
  
  psoc_spi_write_reg8(psoc_spi_device, minor + 1, value);	//Function in psoc-spi.c, (device, address, data)
  
  /* Legacy file ptr f_pos. Used to support 
   * random access but in char drv we dont! 
   * Move it the length actually  written 
   * for compability */
  *f_pos += len;

  /* return length actually written */
  return len;
}

ssize_t psoc_cdrv_read(struct file *filep, char __user *ubuf, 
                          size_t count, loff_t *f_pos)
{
  
  char resultBuf[MAXLEN];
  u16 result;
  int minor, len; 
  
  minor = MINOR(filep->f_dentry->d_inode->i_rdev);

  
  printk(KERN_ALERT "Reading from psoc [Minor] %i \n", minor);
   
  
  int err = psoc_spi_read_reg16(psoc_spi_device, (u8)(minor + 1), &result);
  if (err)
    return -EFAULT;
  /* Convert to string and copy to user space */
  //  len = snprintf(resultBuf, sizeof resultBuf, "%d\n", result);
  /* Convert integer to string limited to "count" size. Returns
   * length excluding NULL termination */
  
  len = snprintf(resultBuf, count, "%d\n", result);
  len++;

  printk(KERN_ALERT "len: %d, result: %d", len, result);
  /* Copy data to user space */
  if(copy_to_user(ubuf, resultBuf, len))
    return -EFAULT;

  /* Move fileptr */
  *f_pos += len;

  return len;

}



struct file_operations psoc_fops = 
{
  .owner   = THIS_MODULE,
  .open    = psoc_cdrv_open,
  .release = psoc_cdrv_release,
  .write   = psoc_cdrv_write,
  .read    = psoc_cdrv_read,
};

module_init(psoc_cdrv_init);
module_exit(psoc_cdrv_exit);

MODULE_AUTHOR("Peter Hoegh Mikkelsen <phm@iha.dk>");
MODULE_LICENSE("GPL");

