#include <linux/err.h>
#include <plat/mcspi.h>
#include <linux/spi/spi.h>
#include <linux/module.h>
//#include "psoc.h"

#define MODULE_DEBUG 0

/* We are only using ONE SPI device so far, so we save the device pointer (*spi) in psoc_spi_device */
static struct spi_device *psoc_spi_device = NULL;


/* Method to retrieve SPI device pointer */
struct spi_device* psoc_get_device(void){
  return psoc_spi_device;
}

int psoc_spi_read_reg16(struct spi_device *spi, u8 addr, u16* value)
{
	struct spi_transfer t[1];
	struct spi_message m;
	u16 cmd;
	u16 data = 0;

    /* Check for valid spi device */
    if(!spi)
      return -ENODEV;

	/* Create Cmd byte:
	 *
	 * | Cmd   |         ADDR         |       EMTY         |
	 *   15  14  13  12  11  10  9  8  7  6  5  4  3  2  1
     */
	cmd = addr;
	/* Init Message */
	memset(t, 0, sizeof(t));
	spi_message_init(&m);
	m.spi = spi;

	/* Configure tx/rx buffers */
	t[0].tx_buf = &cmd;
	t[0].rx_buf = &data;
	t[0].len = 2;
	t[0].delay_usecs = 250;

	printk(KERN_ALERT "Requesting data from addr 0x%x\n", cmd);

	spi_message_add_tail(&t[0], &m);
	/*
	t[1].tx_buf = NULL;
	t[1].rx_buf = &data;
	t[1].len = 2;
	t[1].delay_usecs = 250;
	spi_message_add_tail(&t[1], &m);
	*/
	/* Transmit SPI Data (blocking) */
	spi_sync(m.spi, &m);

	printk(KERN_ALERT "PSOC: Read Reg16 Addr 0x%x Data: 0x%x\n", cmd, data);

	*value = data;
	return 0;
}


/*
 * PSoC Probe
 * Used by the SPI Master to probe the device
 * when an SPI device is registered.
 */
static int __devinit psoc_spi_probe(struct spi_device *spi)
{
  int err;

  spi->bits_per_word = 16;
  err = spi_setup(spi);

  printk(KERN_DEBUG "Probing done");

  psoc_spi_device = spi;	//Saving the spi device pointer in our own static variable

  return err;
}


/*
 * PSoC Remove
 * Called when the SPI device is removed
 */
static int __devexit psoc_remove(struct spi_device *spi)
{

  printk(KERN_DEBUG "Removed SPI-device");

  return 0;
}


/*
 * PSoC SPI Driver Struct
 * Holds function pointers to probe/release
 * methods and the name under which it is registered
 *
 */
static struct spi_driver psoc_spi_driver = {
  .driver = {
    .name = "psoc",
    .bus = &spi_bus_type,
    .owner = THIS_MODULE,
  },
  .probe = psoc_spi_probe,
  .remove = __devexit_p(psoc_remove),
};

int psoc_spi_init(void)
{
  int err;

  err = spi_register_driver(&psoc_spi_driver);

  if(err<0)
    printk (KERN_ALERT "Error %d registering the PSoC SPI driver\n", err);

  return err;
}


/*
 * PSoC SPI Exit
 * Exit routine called from character driver.
 * Unregisters the driver from the SPI host
 */
void psoc_spi_exit(void)
{
  spi_unregister_driver(&psoc_spi_driver);
}



/*
 * Spørgsmål til Peter:
 * Hvor skal routing initialiseres?



*/
