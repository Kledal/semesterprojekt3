#ifndef PSOC_SPI_H
#define PSOC_SPI_H
#include <linux/spi/spi.h>

struct spi_device* psoc_get_device(void);

int psoc_spi_write_reg8(struct spi_device *spi, u8 addr, u8 data);
int psoc_spi_read_reg16(struct spi_device *spi, u8 addr, u16* value);
int psoc_spi_init(void);
void psoc_spi_exit(void);

#endif

