#include "displayInformation/DisplayInformation.h"
#include <iostream>
#include <unistd.h>
using namespace std;



int main()
{
	DisplayInformation DI;

	int speed, avgSpeed, batteryLevel, batteryLeft;

	while (1)
	{
		DI.readData(&speed, &avgSpeed, &batteryLevel, &batteryLeft);
		cout << "Speed: " << speed << " km/t\n";
		cout << "Average speed: " << avgSpeed << " km/t\n";
		cout << "Battery level: " << batteryLevel << "\%\n";
		cout << "Battery left: " << batteryLeft << " minutes\n\n";
		sleep(1);
	}
}