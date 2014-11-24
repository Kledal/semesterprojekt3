#include <project.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gps.h"

/* I2C slave address to communicate with */
#define I2C_SLAVE_ADDR  (0x52u)

void processUSBUart();

/******** SPI ***************/
CY_ISR_PROTO(isr_spi_rx);
/********* /SPI *************/

void reverse(char *str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char *res, int afterpoint);

int main()
{
   
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    //I2C_1_Start();
    UART_PC_Start();
    UART_GPS_Start();
    
    SPIS_1_SetCustomInterruptHandler(isr_spi_rx);
	SPIS_1_SpiUartClearTxBuffer();
    SPIS_1_Start();
 
    for(;;)
    {
        readGPSData();
//        UART_PC_UartPutString("GPS Speed: ");
//        UART_PC_UartPutString(getGPSUartSpeed());
//        UART_PC_UartPutChar(0xd);
//        
//        UART_PC_UartPutString("Number of satelites: ");
//        UART_PC_UartPutString(GetGPSTime());
//        UART_PC_UartPutChar(0xd);
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
			SPIS_1_SpiUartWriteTxData( (int16)GetGPSTime() );
            break;
		default:
			break;
	}
	
	SPIS_1_ClearRxInterruptSource(SPIS_1_GetRxInterruptSource());
}