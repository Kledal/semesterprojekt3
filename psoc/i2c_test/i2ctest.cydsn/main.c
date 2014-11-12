/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/* I2C slave address to communicate with */
#define I2C_SLAVE_ADDR  (0x52u)

uint32 ReadStatusPacket(void);
void SendHandshake();
void SendZero();
uint8 DecodeByte(uint8 input);
void GetDataFromNunChuck();

void processUSBUart();
/********** GPS  ***************/
void readGPSData();
int compareGPSCMD(char* cmd);
void resetGPSBuffer();
void handleGPSData(char* cmd);

char gpsBuffer[300] = "";
int gpsBufferPointer = 0;
char* gpvtg = "$GPVTG";
char* gpgga = "$GPGGA";

/********** /GPS  ***************/

int last_joystick_x = 0;
uint8 readBuf[6];

void reverse(char *str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char *res, int afterpoint);

int main()
{
    I2C_1_Start();
    UART_PC_Start();
    UART_GPS_Start();
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    
    // Set GPS to 10 Hz
    UART_GPS_PutString("$PMTK220,200*2C");
    UART_GPS_PutChar(13);
    UART_GPS_PutChar(10);
    UART_GPS_PutString("$PMTK300,200,0,0,0,0*2F");
    UART_GPS_PutChar(13);
    UART_GPS_PutChar(10);
    
    SendHandshake();
    SendZero();
    
    int shiftMode = 0;
    for(;;)
    {
        GetDataFromNunChuck();
        if (shiftMode%10 == 0) {
            readGPSData();
            shiftMode = 0;   
        }
        shiftMode++;
        
    }
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
                if (compareGPSCMD(gpgga)){
                    handleGPSData("GPGGA");
                    completedGGA = 1;
                }
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
    
    UART_PC_UartPutString(packet);
    UART_PC_UartPutChar(0xd);
    
//    char* token = strtok(packet, ",");
//    i = 0;
//    while( token != NULL ) 
//    {
//        if (i == 2 && strcmp(cmd, "GPGGA") == 0) {
//            latitude = atof(token);
//        }
//        if (i == 3 && strcmp(cmd, "GPGGA") == 0) {
//            sscanf(token, "%c", &latitude_pos);
//        }
//        if (i == 4 && strcmp(cmd, "GPGGA") == 0) {
//            longitude = atof(token);;
//        }
//        if (i == 5 && strcmp(cmd, "GPGGA") == 0) {
//            sscanf(token, "%c", &longitude_pos);
//        }
//        if (i == 7 && strcmp(cmd, "GPGGA") == 0) {
//            sscanf(token, "%d", &number_of_satelites);
//        }
//        if (i == 9 && strcmp(cmd, "GPGGA") == 0) {
//            altitude = atof(token);
//        }
//        if (i == 6 && strcmp(cmd, "GPVTG") == 0) {
//            ground_speed = atof(token);
//        }
//        token = strtok(NULL, ",");
//        i++;
//    }
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

uint8 DecodeByte(uint8 input) {
    return (input ^ 0x17) + 0x17;
}
void GetDataFromNunChuck() {
    I2C_1_I2CMasterSendStart(I2C_SLAVE_ADDR, 1);
    int i = 0;
    for(i=0;i<6;i++) {
        readBuf[i] = DecodeByte(I2C_1_I2CMasterReadByte(0));
        // UART_PC_UartPutChar(readBuf[i]);
    }
    I2C_1_I2CMasterSendStop();
    // UART_PC_UartPutString("\n\r");

    int cButton = !(readBuf[0] & (1 << 1));
    int zButton =  !(readBuf[0] & (1 << 0));
    if (cButton) {
        UART_PC_UartPutString("1");
    }else{
        UART_PC_UartPutString("0");
    }
    if (zButton) {
        UART_PC_UartPutString("1");
    } else {
        UART_PC_UartPutString("0");
    }

    int joystick_x = readBuf[1];
    int joystick_y = readBuf[2];

    UART_PC_UartPutChar(joystick_x);
    UART_PC_UartPutChar(joystick_y);
    UART_PC_UartPutChar(13);

    SendZero();
    CyDelay(10);
}
void SendZero() {
    I2C_1_I2CMasterSendStart(I2C_SLAVE_ADDR, 0);
    I2C_1_I2CMasterWriteByte(0x00);
    I2C_1_I2CMasterSendStop();
    //I2C_1_I2CMasterClearStatus();
    //UART_1_UartPutString("SendZero done\n\r");
}
void SendHandshake()
{    
    I2C_1_I2CMasterSendStart(I2C_SLAVE_ADDR, 0);
    I2C_1_I2CMasterWriteByte(0x40);
    I2C_1_I2CMasterWriteByte(0x00);
    I2C_1_I2CMasterSendStop();
    //(void) I2C_1_I2CMasterClearStatus();
    
    UART_PC_UartPutString("Handshake done\n\r");
    
    CyDelay(300);
}
//
//// reverses a string 'str' of length 'len'
//void reverse(char *str, int len)
//{
//    int i=0, j=len-1, temp;
//    while (i<j)
//    {
//        temp = str[i];
//        str[i] = str[j];
//        str[j] = temp;
//        i++; j--;
//    }
//}
// 
// // Converts a given integer x to string str[].  d is the number
// // of digits required in output. If d is more than the number
// // of digits in x, then 0s are added at the beginning.
//int intToStr(int x, char str[], int d)
//{
//    int i = 0;
//    
//    if (x == 0)
//        str[i++] = '0';
//        
//    while (x)
//    {
//        str[i++] = (x%10) + '0';
//        x = x/10;
//    }
// 
//    // If number of digits required is more, then
//    // add 0s at the beginning
//    while (i < d)
//        str[i++] = '0';
// 
//    reverse(str, i);
//    str[i] = '\0';
//    return i;
//}
// 
//// Converts a floating point number to string.
//void ftoa(float n, char *res, int afterpoint)
//{
//    // Extract integer part
//    int ipart = (int)n;
// 
//    // Extract floating part
//    float fpart = n - (float)ipart;
// 
//    // convert integer part to string
//    int i = intToStr(ipart, res, 0);
// 
//    // check for display option after point
//    if (afterpoint != 0)
//    {
//        res[i] = '.';  // add dot
// 
//        // Get the value of fraction part upto given no.
//        // of points after dot. The third parameter is needed
//        // to handle cases like 233.007
//        fpart = fpart * pow(10, afterpoint);
// 
//        intToStr((int)fpart, res + i + 1, afterpoint);
//    }
//}
//