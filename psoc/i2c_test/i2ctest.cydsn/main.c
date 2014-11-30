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
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    
    SPIS_1_SetCustomInterruptHandler(isr_spi_rx);
	SPIS_1_SpiUartClearTxBuffer();
    SPIS_1_Start();
    
    //I2C_1_Start();
    UART_PC_Start();
    UART_GPS_Start();
    for(;;)
    {
        readGPSData();
//        UART_PC_UartPutString( getGPSUartNumberOfSate() );
//        UART_PC_UartPutChar(0xd);
//        UART_PC_UartPutString( getGPSUartSpeed() );
//        UART_PC_UartPutChar(0xd);
//        UART_PC_UartPutString("GPS Speed: ");
//        UART_PC_UartPutString(getGPSUartSpeed());
//        UART_PC_UartPutChar(0xd);
//        
//        UART_PC_UartPutString("Sats: ");
//        UART_PC_UartPutString(getGPSUartNumberOfSate());
//        if (getNumberOfSate() > 0) {
//            char returnStr[22];
//            UART_PC_UartPutString(",");
//            
//            GetGPSLatitude(returnStr);
//            UART_PC_UartPutString( returnStr );
//            
//            UART_PC_UartPutString(",");
//            UART_PC_UartPutChar(GetGPSLatitudePos());
//            
//            GetGPSLongitude(returnStr);
//            UART_PC_UartPutString(",");
//            UART_PC_UartPutString( returnStr  );
//            
//            UART_PC_UartPutString(",");
//            UART_PC_UartPutChar(GetGPSLongitudePos());
//        }
//        UART_PC_UartPutChar(0xd);
    }
}

CY_ISR(isr_spi_rx) {

	uint32 addr = SPIS_1_SpiUartReadRxData();
//    UART_PC_UartPutChar(addr );
//    UART_PC_UartPutChar(0xd);
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