#include "controller.h"
#include <project.h>

int joystick_x = 0;
int joystick_y = 0;
int cButton = 0;
int zButton = 0;
int readBuf[6] = {};

uint8 handshakeSeq[8] = {0x40, 0x00};
uint8 getdataSeq[1] = {0x00};

#define I2C_SLAVE_ADDR  (0x52u)


int GetJoystickX() {
 return joystick_x;
}
int GetJoystickY() {
 return joystick_y - 126;   
}
int DecodeByte(int input) {
    return (input ^ 0x17) + 0x17;
}
void GetDataFromNunChuck() {
    SendZero();
    I2C_1_MasterSendStart(I2C_SLAVE_ADDR, I2C_1_READ_XFER_MODE);
    int i = 0;
    for(i=0;i<6;i++) {
        int beforeDecode = I2C_1_MasterReadByte(1);
        readBuf[i] = DecodeByte(beforeDecode);
    }
    I2C_1_MasterSendStop();

    cButton = !(readBuf[5] & (1 << 1));
    zButton =  !(readBuf[5] & (1 << 0));

    joystick_x = readBuf[0];
    joystick_y = readBuf[1];
}
void SendZero() {
    I2C_1_MasterSendStart(I2C_SLAVE_ADDR, I2C_1_WRITE_XFER_MODE);
    I2C_1_MasterWriteByte(0x00);
    I2C_1_MasterSendStop();
    
    int i = 0;
    do {
       i++;
    } while(i < 500);
}
void SendHandshake()
{    
    I2C_1_MasterSendStart(I2C_SLAVE_ADDR, I2C_1_WRITE_XFER_MODE);    
    I2C_1_MasterWriteByte(0x40);
    I2C_1_MasterWriteByte(0x00);
    I2C_1_MasterSendStop();
}
