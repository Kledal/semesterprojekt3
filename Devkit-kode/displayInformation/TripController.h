#pragma once
#include <ctime>
#include <vector>
#include "TripInfo.h"

class TripController
{
public:
	TripController( ) {
		avgSpeed_ = 0;
		numOfSamples_ = 0;
		batLeft_ = 0; 
	}

	/* returns 1 for success, 0 for error */
	bool addSample( int speed, int batteryLevel ) {
		if(speed >= 0 && batteryLevel <= 100 && batteryLevel >= 0) {
			tripVector_.push_back( new TripInfo(speed, batteryLevel) );
			numOfSamples_++;
			calcAvgSpeed( );
			calcBatLeft( );

			return true;
		} else {
			//sample not added
			return false;
		}
	}

	void calcAvgSpeed( ) {
		if( numOfSamples_ ) {
			//average speed = sum of previous speed + current speed / number of samples
			avgSpeed_ = (avgSpeed_ * (numOfSamples_ - 1) + tripVector_[numOfSamples_ - 1]->getSpeed( )) / numOfSamples_;
		}
	}

	void calcBatLeft( ) {
		if( numOfSamples_ > 1 ) {
			//find the time spent = current time - initial time
			std::time_t timeSpent = tripVector_[numOfSamples_ - 1]->getTime( ) - tripVector_[0]->getTime( );
			int avgLastPoint;
			//find battery spent = current battery level - initial level
			if( numOfSamples_ >= 3 ) {
				avgLastPoint = (tripVector_[numOfSamples_ - 1]->getBatLevel( ) + 
					tripVector_[numOfSamples_ - 2]->getBatLevel( ) + 
					tripVector_[numOfSamples_ - 3]->getBatLevel( )) / 3;
			} else {
				avgLastPoint = tripVector_[numOfSamples_ - 1]->getBatLevel( );
			}
			int batSpent = avgLastPoint - tripVector_[0]->getBatLevel( );

			//Use the last 3 batterysamples to calculate how many minutes remain before batterylevel reach 0%
			// batteryleft = (-initial battery level) / (- battery spent / time spent) - time spent
			//batLeft_ = (int)(-(tripVector_[0]->getBatLevel( )) / (-batSpent / timeSpent) - timeSpent) / 60;

			float initial = tripVector_[0]->getBatLevel( );
			float delta = -(float)batSpent / (float)timeSpent;
			if (initial != avgLastPoint)
				batLeft_ = (int)(initial/delta - (float)timeSpent) / 60;
		}
	}

	int getSpeed( ) const {
		if( numOfSamples_ > 0 )
			return tripVector_[numOfSamples_ - 1]->getSpeed( );
		else 
			return 0;
	}

	int getAvgSpeed( ) const {
		return avgSpeed_;
	}

	int getBatLevel( ) const {
		if( numOfSamples_ > 0 )
			return tripVector_[numOfSamples_ - 1]->getBatLevel( );
		else 
			return 0;
	}

	int getBatLeft( ) const {
		return batLeft_;
	}

private:
	std::vector <TripInfo *> tripVector_;

	int avgSpeed_; //in kph
	int numOfSamples_;
	int batLeft_; //battery time remaining in minutes
};