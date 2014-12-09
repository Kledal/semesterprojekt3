#include <project.h>
#include "controller.h"

CY_ISR(nunchuck_isr) {
    int t = 0;
    t++;
    t *= 10;
}

int main()
{
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    isr_1_StartEx(nunchuck_isr);
   
    VDAC_Start();
    
    
    I2C_1_Start();
    SendHandshake();
    for(;;)
    {
        GetDataFromNunChuck();
        CyDelay(1);
        int test = GetJoystickY();
        VDAC_SetValue(test + 126);
    }
}