 #include <project.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gps.h"

/********** GPS  ***************/

char gpsBuffer[300] = "";
int gpsBufferPointer = 0;
char* gpvtg = "$GPVTG";
char* gpgga = "$GPGGA";

int speed_ = 0;
int numberOfSate_ = 0;

/********** /GPS  ***************/

int getNumberOfSate() {
    return numberOfSate_;
}
int getGPSSpeed() {
    return speed_;
}

void readGPSData() {
    int completedGGA = 0;
    int completedVTG = 0;
    while(!completedVTG) {
        uint8 rxHasData = UART_GPS_GetRxBufferSize();
        
        if (rxHasData) {
            char rxData = UART_GPS_ReadRxData();

            gpsBuffer[gpsBufferPointer] = rxData;
            gpsBufferPointer++;
            
            if (rxData == 0x10) {
                gpsBufferPointer = 0;
                resetGPSBuffer();
            }
            //UART_PC_UartPutChar(rxData);
            // Data completed. Received a full gps packet.
            if (rxData == 13) { 
                //Global Positioning System Fix Data           
                if (compareGPSCMD(gpgga)){
                    handleGPSData("GPGGA");
                    completedGGA = 1;
                }
                //Track Made Good and Ground Speed (km/h)
                if (compareGPSCMD(gpvtg)){
                    handleGPSData("GPVTG");
                    completedVTG = 1;
                }
                gpsBufferPointer = 0;
                resetGPSBuffer();
            }
        }
    }
}
void handleGPSData(char* cmd) {
    int i = 0;
    char packet[gpsBufferPointer-1];
    for(i =1;i<gpsBufferPointer-1;i++) {
        packet[i-1] = gpsBuffer[i];
    }
    
    char* token = strtok(packet, ",");
    i = 0;
    while( token != NULL ) 
    {
        if (i == 6 && strcmp(cmd, "GPVTG") == 0) {
            speed_ = atof(token);
        }
        if (i == 7 && strcmp(cmd, "GPGGA") == 0) {
            sscanf(token, "%d", &numberOfSate_);
        }
//      if (i == 9 && strcmp(cmd, "GPGGA") == 0) {
//          altitude = atof(token);
//      }
        token = strtok(NULL, ",");
        i++;
    }
}

int compareGPSCMD(char* cmd) {
    int i = 0;
    int correct = 0;
    for(i =1;i<7;i++) {
        if (cmd[i-1] == gpsBuffer[i])
            correct++;
    }
    return correct == 6;
}
void resetGPSBuffer() {
    int i;
    for (i=0;i<300;i++){
     gpsBuffer[i]=' ';             
   } 
}

void initGPSandSPI()
{
    UART_PC_Start();
    UART_GPS_Start();
    
    SPIS_1_SetCustomInterruptHandler(isr_spi_rx);
    SPIS_1_SpiUartClearTxBuffer();
    SPIS_1_Start();
}