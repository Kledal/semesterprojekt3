#include <project.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gps.h"
#include "util.h"

/******** SPI ***************/
CY_ISR_PROTO(isr_spi_rx);
/********* /SPI *************/

int counter = 0;
int battery = 100;

int main()
{
    CyGlobalIntEnable;
    
    SPIS_1_SetCustomInterruptHandler(isr_spi_rx);
	SPIS_1_SpiUartClearTxBuffer();
    SPIS_1_Start();

    UART_PC_Start();
    UART_GPS_Start();
    for(;;)
    {
        readGPSData();
    }
}

CY_ISR(isr_spi_rx) {

	uint32 addr = SPIS_1_SpiUartReadRxData();
    SPIS_1_SpiUartClearTxBuffer();
	switch (addr) {
        case 0x0: // Batteri
			SPIS_1_SpiUartWriteTxData( (int16)battery );
            counter++;
            if (counter == 5)
            {
                counter = 0;
                battery--;
            }
        break;
        case 0x1: // Hastighed
            SPIS_1_SpiUartWriteTxData( (int16)getGPSSpeed() );
        break;
		default:
			break;
	}
	SPIS_1_ClearRxInterruptSource(SPIS_1_GetRxInterruptSource());
}