#pragma once
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

int getBatIF( ) {
	int fd_bat;
	int temp_bat;
	int len_bat = 3; 
	char buffer_bat[6] = {0};
	fd_bat = open("/sys/class/fake_psoc/fake_psoc1/battery", O_RDONLY);
	if (read(fd_bat, buffer_bat, len_bat) > 3)
		std::cout << "Error read in getBatIF";

	//cast from char array to int
	temp_bat = atoi(buffer_bat);

	close(fd_bat);

	return temp_bat;
}

int getSpeedIF( ) {
	int fd_speed;
	int temp_speed;
	int len_speed = 3;
	char buffer_speed[6] = {0};
	fd_speed = open("/sys/class/fake_psoc/fake_psoc1/speed", O_RDONLY);
	if (read(fd_speed, buffer_speed, len_speed) > 3)
		std::cout << "Error read in getBatIF";

	//cast from char array to int
	temp_speed = atoi(buffer_speed);

	close(fd_speed);
	
	return temp_speed;
}
