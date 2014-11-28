 #include <project.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gps.h"
#include "util.h"

/* I2C slave address to communicate with */
#define I2C_SLAVE_ADDR  (0x52u)

/* Initiate Uart */
void processUSBUart();

/* SPI (Kan den flyttes til initGPSandSPI) */
CY_ISR_PROTO(isr_spi_rx);

int main()
{   
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    initGPSandSPI();
    for(;;)
    {
        readGPSData();
        //UART_PC_UartPutString("Sats: ");
        //UART_PC_UartPutString(getGPSUartNumberOfSate());
    }
}

CY_ISR(isr_spi_rx) {
	uint16 rxvalue;
	uint8 cmd, rddata, addr;
	rxvalue = SPIS_1_SpiUartReadRxData();
	cmd = (rxvalue >> 14) & 0x3;  // cmd = rdvalue[15:14]
	addr = (rxvalue >> 8) & 0x3f; // addr = rdvalue[13:8]
	rddata = rxvalue & 0xff;      // data = rdvalue[7:0]
    
	switch (addr) {
        case 0x1:
            SPIS_1_SpiUartClearTxBuffer();
            SPIS_1_SpiUartWriteTxData( (int16)GetGPSSpeed() );
            break;
        case 0x2:
            SPIS_1_SpiUartClearTxBuffer();
            SPIS_1_SpiUartWriteTxData( (int16)getNumberOfSate() );
            break;
/*        case 0x3:
            SPIS_1_SpiUartClearTxBuffer();
            SPIS_1_SpiUartWriteTxData( (int16)GetBatteryVoltage() );
            break;*/
		default:
			break;
	}
	
	SPIS_1_ClearRxInterruptSource(SPIS_1_GetRxInterruptSource());
}