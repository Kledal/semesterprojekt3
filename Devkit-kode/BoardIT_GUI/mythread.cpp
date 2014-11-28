#include "mythread.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <QString>

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
}

void MyThread::run()
{
  QString temp = "";
  int fd;
  char buffer[6];
  fd = open("/dev/psoc1", O_RDONLY);
  
  while(1)
  {
    
    if(!read(fd, buffer, 6))
    printf("FAIL");
    
    QString string(buffer);
    emit textChanged(string);
    
    this->msleep(1000);
  }
  
  /*
  while (buffer[i] != '\0')
  {
    temp.append(buffer[i]);
    i++;
  }
  
  for (int i = 0; i < 1000; i++)
  {
      

  */
}
