#include <project.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gps.h"
#include "util.h"

// Set GPS to 10 Hz
//    UART_GPS_PutString("$PMTK220,200*2C");
//    UART_GPS_PutChar(13);
//    UART_GPS_PutChar(10);
//    UART_GPS_PutString("$PMTK300,200,0,0,0,0*2F");
//    UART_GPS_PutChar(13);
//    UART_GPS_PutChar(10);

/********** GPS  ***************/

char gpsBuffer[300] = "";
int gpsBufferPointer = 0;
char* gpvtg = "$GPVTG";
char* gpgga = "$GPGGA";
char* gpgsv = "$GPGSV";

int speed_ = 0;

/********** /GPS  ***************/

int getGPSSpeed() {
    return speed_;
}
char* getGPSUartNumberOfSate() {
    char returnSpeed[22];
    intToStr(getNumberOfSate(), *returnSpeed, 2);
    return *returnSpeed;
}
char* getGPSUartSpeed() {
    char returnSpeed[22];
    intToStr(getGPSSpeed(), *returnSpeed, 4);
    return *returnSpeed;
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
            // Data completed. Received a full gps packet.
            if (rxData == 13) {            
                if (compareGPSCMD(gpgga)){
                    handleGPSData("GPGGA");
                    completedGGA = 1;
                }
                if (compareGPSCMD(gpvtg)){
                    handleGPSData("GPVTG");
                    completedVTG = 1;
                }
                if (compareGPSCMD(gpgsv)) {
                    handleGPSData("GPVSG");
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