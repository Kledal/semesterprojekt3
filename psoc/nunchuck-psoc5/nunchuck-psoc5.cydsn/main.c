#include <project.h>
#include "controller.h"

int main()
{
    I2C_1_Start();
    SendHandshake();
    for(;;)
    {
        GetDataFromNunChuck();
    }
}
