#ifndef DISPLAYINFORMATION_H
#define DISPLAYINFORMATION_H

#include "TripController.h"
#include "../SPI_Interface/SPI_IF.h"
#include <iostream>

class DisplayInformation 
{
public:
	DisplayInformation () {
		tripPtr_ = new TripController;
	}
	bool readData(int * speed, int * avgSpeed, int * batteryLevel, int * batteryLeft)
	{
		bool err = storeData();	//Call for new data

		*speed 			= tripPtr_->getSpeed();
		*avgSpeed 		= tripPtr_->getAvgSpeed();
		*batteryLevel 	= tripPtr_->getBatLevel();
		*batteryLeft 	= tripPtr_->getBatLeft();

		return err;
	}

private:
	bool storeData( )
	{
		//store temporary
		int tmpBat = getBatIF();
		int tmpSpeed = getSpeedIF();

		if(tripPtr_->addSample(tmpSpeed, tmpBat))
			return true;
		else 
			return false;	//sample not added
	}

	TripController* tripPtr_;
};

#endif // DISPLAYINFORMATION_H