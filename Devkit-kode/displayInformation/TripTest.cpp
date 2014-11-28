#include "TripController.h"
#include <unistd.h>
#include <iostream>
using namespace std;

TripController boardTrip;

void print()
{
	cout << "Battery left: " << boardTrip.getBatLeft() << " minutes\n";
	cout << "Average speed: " << boardTrip.getAvgSpeed() << " kph\n";
}

int main ( )
{
	/*
//Test speed boundaries
	boardTrip.addSample(-1, 50);
	print();
	sleep(2);
	boardTrip.addSample(0, 50);
	print();
	sleep(2);
	boardTrip.addSample(100, 50);
	print();
*/

//Test battery boundaries
	cout << boardTrip.addSample(50, 101) << "\n";
	cout << "Battery: " << boardTrip.getBatLevel() << " percent\n";
	sleep(2);
	boardTrip.addSample(50, 100);
	cout << "Battery: " << boardTrip.getBatLevel() << " percent\n";
	sleep(2);
	boardTrip.addSample(50, 99);
	boardTrip.addSample(50, 99);
	boardTrip.addSample(50, 99);
	cout << "Battery: " << boardTrip.getBatLevel() << " percent\n";
	sleep(2);
	boardTrip.addSample(50, 1);
	cout << "Battery: " << boardTrip.getBatLevel() << " percent\n";
	sleep(2);
	boardTrip.addSample(50, 0);
	cout << "Battery: " << boardTrip.getBatLevel() << " percent\n";
	sleep(2);
	cout << boardTrip.addSample(50, -1) << "\n";
	cout << "Battery: " << boardTrip.getBatLevel() << " percent\n";

/*//test multiple samples
	boardTrip.addSample(10, 99);
	print();
	sleep(1);
	boardTrip.addSample(12, 99);
	print();
	sleep(1);
	boardTrip.addSample(15, 99);
	print();
	sleep(5);
	boardTrip.addSample(20, 98);
	print();
	sleep(1);
	boardTrip.addSample(22, 98);
	print();
	sleep(1);
	boardTrip.addSample(18, 98);
	print();
	sleep(1);
	boardTrip.addSample(9, 98);
	print();
	sleep(1);
	boardTrip.addSample(2, 97);
	print();
	sleep(1);
*/
	return 0;
}