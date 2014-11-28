#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
  int fd_speed, fd_bat;
  char buffer_speed[6], buffer_bat[6];
  fd_speed = open("/sys/class/fake_psoc/fake_psoc1/speed", O_WRONLY);
  fd_bat = open("/sys/class/fake_psoc/fake_psoc1/battery", O_WRONLY);
  int count = 0;
  int len_speed, len_bat;
  while(1)
  {
  	count++;
  	len_speed = sprintf(buffer_speed, "%d", count);
  	len_bat = sprintf(buffer_bat, "%d", count);

    printf("speed: %d\n", len_speed);
    printf("battery: %d\n", len_bat);
    if(!write(fd_speed, buffer_speed, len_speed))
      printf("ERROR write to speed");

    if(!write(fd_bat, buffer_bat, len_bat))
      printf("ERROR write to battery");

  	usleep(500000); 	//Sleep 0.5 sec
    
  }
return 0;
}