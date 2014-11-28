#include "TripController"
#include "SPI_IF.h"

class DisplayInformation 
{
public:
	bool readData(int & speed, int & avgSpeed, int & batteryLevel, int & batteryLeft)
	{
		speed 			= tripPtr_->getSpeed();
		avgSpeed 		= tripPtr_->getAvgSpeed();
		batteryLevel 	= tripPtr_->getBatLevel();
		batteryLeft 	= tripPtr_->getBatLeft();

		return true;
	}

	bool storeData( )
	{
		//store temporary
		int tmpBat = getBatIF();
		int tmpSpeed = getSpeedIF();

		if(tripPtr_->addSample(tmpSpeed, tmpBat))
			return true;
		else 
			//sample not added
			return false;
	}


private:
	TripController * tripPtr_;
};