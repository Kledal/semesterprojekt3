#include <project.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "controller.h"

void write(const char8 string[]);
int main()
{
    int test = 0;
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    I2C_1_Start();
    UART_PC_Start();
    
    write("Sending handshake.");
    SendHandshake();    
    for(;;)
    {
        SendZero();
        GetDataFromNunChuck();

        UART_PC_UartPutChar(GetJoystickX());
    }
}

void write(const char8 string[]) {
    UART_PC_UartPutString(string); 
    UART_PC_UartPutChar(0xd);
}