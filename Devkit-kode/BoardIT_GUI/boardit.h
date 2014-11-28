#ifndef BOARDIT_H
#define BOARDIT_H

#include <QMainWindow>
#include <QString>
#include "mythread.h"

namespace Ui {
class BoardIT;
}

class BoardIT : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardIT(QWidget *parent = 0);
    ~BoardIT();
    MyThread *mThread;

private:
    Ui::BoardIT *ui;

public slots:
    void onTextChanged(QString);
};

#endif // BOARDIT_H
