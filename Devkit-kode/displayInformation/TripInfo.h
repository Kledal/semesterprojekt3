#pragma once
#include <ctime>

class TripInfo
{
public:
	TripInfo( int s, int bL ) : 
		timestamp_(std::time(0)), 
		speed_(s), 
		batLevel_(bL) { }

	int getSpeed( ) const 
	{
		return speed_;
	}

	int getBatLevel( ) const
	{
		return batLevel_;
	}

	std::time_t getTime( ) const 
	{
		return timestamp_;
	}

private:
	const std::time_t timestamp_; //seconds since 01-Jan-1970
	const int speed_; //kph
	const int batLevel_; //percent
};
