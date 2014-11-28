#pragma once
#include <stdlib.h>


class FakeApplication
{
public:
	FakeApplication() : count(0) {}

	bool readData(int & speed, int & avgSpeed, int & batteryLevel, int & batteryLeft) {
		speed = count % 200;
		avgSpeed = count % 200;
		batteryLevel = count % 101;
		batteryLeft = count % 200;
		count++;
		return true;
	}
	
private:
	int count;
};