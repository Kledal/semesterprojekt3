#include "mythread.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <QString>
#include "../displayInformation/DisplayInformation.h"

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
}

void MyThread::run()
{
  int speed, avgSpeed, batLevel, batLeft;
  
  DisplayInformation DI;

  while(1)
  {
    DI.readData(&speed, &avgSpeed, &batLevel, &batLeft);
    
    QString speedStr = QString::number(speed);
    QString avgSpeedStr = QString::number(avgSpeed);
    QString batLevelStr = QString::number(batLevel);
    QString batLeftStr = QString::number(batLeft);
    emit textChanged(speedStr, avgSpeedStr, batLevelStr, batLeftStr);
    
    this->msleep(1000);
  }
  
}
