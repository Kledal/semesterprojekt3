#pragma once

int getBatIF( );
int getSpeedIF( );

int getBatIF( ) {
	int fd_bat;
	long temp_bat;
	int len_bat = 2; // ??
	char buffer_bat[6]; // ??
	fd_bat = open("/sys/class/fake_psoc/fake_psoc1/battery", O_WRONLY);
	read(fd_bat, buffer_bat, len_bat);

	//cast from char array to long and then to int
	kstrtol(buffer_bat, 10, &temp_bat);

	return (int)temp_bat;
}

int getSpeedIF( ) {
	int fd_speed;
	long temp_speed;
	int len_speed = 2; // ??
	char buffer_speed[6]; // ??
	fd_speed = open("/sys/class/fake_psoc/fake_psoc1/speed", O_RDONLY);
	read(fd_speed, buffer_speed, len_speed);

	//cast from char array to long and then to int
  	kstrtol(buffer_speed, 10, &temp_speed);

  	return (int)temp_speed;
}
