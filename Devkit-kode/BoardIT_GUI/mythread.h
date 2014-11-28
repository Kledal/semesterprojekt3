#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QtCore>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);
    void run();


signals:
    void textChanged(QString);
public slots:

};

#endif // MYTHREAD_H
