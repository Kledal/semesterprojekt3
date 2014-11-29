#include "boardit.h"
#include "ui_boardit.h"

BoardIT::BoardIT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoardIT)
{
    ui->setupUi(this);

    mThread = new MyThread(this);
    connect(mThread, SIGNAL(textChanged(QString, QString, QString, QString)), this, SLOT(onTextChanged(QString, QString, QString, QString)));

    mThread->start();
}

BoardIT::~BoardIT()
{
    delete ui;
}

void BoardIT::onTextChanged(QString speed, QString avgSpeed, QString batLevel, QString batLeft)
{
    QString temp_text_speed = speed;
    temp_text_speed.prepend("<p align='right'><span style=' font-size:36pt; color:#ff0004;'>");
    temp_text_speed.append("</span></p>");

    QString temp_text_avgSpeed = avgSpeed;
    temp_text_avgSpeed.prepend("<p align='right'><span style=' font-size:36pt; color:#ff0004;'>");
    temp_text_avgSpeed.append("</span></p>");

    QString temp_text_batLevel = batLevel;
    temp_text_batLevel.prepend("<p align='right'><span style=' font-size:36pt; color:#ab23ff;'>");
    temp_text_batLevel.append("</span></p>");

    QString temp_text_batLeft = batLeft;
    temp_text_batLeft.prepend("<p align='right'><span style=' font-size:36pt; color:#ab23ff;'>");
    temp_text_batLeft.append("</span></p>");

    ui->label->setText(temp_text_speed);
    ui->label_2->setText(temp_text_avgSpeed);
    ui->label_3->setText(temp_text_batLevel);
    ui->label_4->setText(temp_text_batLeft);
}
