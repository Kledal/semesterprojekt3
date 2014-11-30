#include "controller.h"
#include <project.h>

int joystick_x = 0;
int joystick_y = 0;
int cButton = 0;
int zButton = 0;
int readBuf[6];

uint8 handshakeSeq[8] = {0x40, 0x00};
uint8 getdataSeq[1] = {0x00};

#define I2C_SLAVE_ADDR  (0x52u)


int GetJoystickX() {
 return joystick_x;
}
int GetJoystickY() {
 return joystick_y;   
}
int DecodeByte(int input) {
    return (input ^ 0x17) + 0x17;
}
void GetDataFromNunChuck() {
    I2C_1_I2CMasterSendStart(I2C_SLAVE_ADDR, I2C_1_I2C_READ_XFER_MODE);
    int i = 0;
    for(i=0;i<6;i++) {
        int beforeDecode = I2C_1_I2CMasterReadByte(0);
        readBuf[i] = DecodeByte(beforeDecode);
//        UART_PC_UartPutChar(readBuf[i]);
    }
    I2C_1_I2CMasterSendStop();
    
//    uint8 buffer[6] = {};
//    I2C_1_I2CMasterReadBuf(I2C_SLAVE_ADDR, buffer, 6, I2C_1_I2C_MODE_COMPLETE_XFER);
//    I2C_1_I2CMasterClearReadBuf();
//    
//    int i = 0;
//    for(i=0;i<6;i++) {
////        readBuf[i] = DecodeByte(buffer[i]);
//        readBuf[i] = buffer[i];
//        UART_PC_UartPutChar(readBuf[i]);
//    }

    cButton = !(readBuf[0] & (1 << 1));
    zButton =  !(readBuf[0] & (1 << 0));

    joystick_x = readBuf[1];
    joystick_y = readBuf[2];
}
void SendZero() {
//    I2C_1_I2CMasterWriteBuf(I2C_SLAVE_ADDR, getdataSeq, 1, I2C_1_I2C_MODE_COMPLETE_XFER);
//    I2C_1_I2CMasterClearWriteBuf();
    I2C_1_I2CMasterSendStart(I2C_SLAVE_ADDR, I2C_1_I2C_WRITE_XFER_MODE);
    I2C_1_I2CMasterWriteByte(0x00);
    I2C_1_I2CMasterSendStop();
//    I2C_1_I2CMasterClearStatus();
//    UART_PC_UartPutString("SendZero done\n\r");
    CyDelay(5);
}
void SendHandshake()
{    
//    I2C_1_I2CMasterWriteBuf(I2C_SLAVE_ADDR, handshakeSeq, 2, I2C_1_I2C_MODE_COMPLETE_XFER);
//    I2C_1_I2CMasterClearWriteBuf();
    I2C_1_I2CMasterSendStart(I2C_SLAVE_ADDR, I2C_1_I2C_WRITE_XFER_MODE);    
    I2C_1_I2CMasterWriteByte(0x40);
    I2C_1_I2CMasterWriteByte(0x00);
    I2C_1_I2CMasterSendStop();
//    
    UART_PC_UartPutString("Handshake done\n\r");
    
    CyDelay(100);
}
