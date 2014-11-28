#include <project.h>

int last_joystick_x = 0;
uint8 readBuf[6];
uint32 ReadStatusPacket(void);

uint8 DecodeByte(uint8 input) {
   return (input ^ 0x17) + 0x17;
}
void GetDataFromNunChuck() {
   I2C_1_I2CMasterSendStart(I2C_SLAVE_ADDR, 1);
   int i = 0;
   for(i=0;i<6;i++) {
       readBuf[i] = DecodeByte(I2C_1_I2CMasterReadByte(0));
   }
   I2C_1_I2CMasterSendStop();

   int cButton = !(readBuf[0] & (1 << 1));
   int zButton =  !(readBuf[0] & (1 << 0));

   int joystick_x = readBuf[1];

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
   
   //UART_PC_UartPutString("Handshake done\n\r");
   
   CyDelay(300);
}