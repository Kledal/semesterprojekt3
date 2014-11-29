#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
  int fd_speed, fd_bat;
  char buffer_speed[4], buffer_bat[4];
  fd_speed = open("/sys/class/fake_psoc/fake_psoc1/speed", O_WRONLY);
  fd_bat = open("/sys/class/fake_psoc/fake_psoc1/battery", O_WRONLY);
  int battery = 100;
  int speed = 0;
  int len_speed, len_bat;
  while(1)
  {
  	speed++;
    battery--;
    if (speed >= 25)
      speed = 0;
    if (battery <= 0)
      battery = 100;

  	len_speed = sprintf(buffer_speed, "%d", speed);
  	len_bat = sprintf(buffer_bat, "%d", battery);

    if(!write(fd_speed, buffer_speed, len_speed))
      printf("ERROR write to speed");

    if(!write(fd_bat, buffer_bat, len_bat))
      printf("ERROR write to battery");

  	usleep(1000000); 	//Sleep 1 sec
    
  }
return 0;
}