#include "boardit.h"
#include "ui_boardit.h"

BoardIT::BoardIT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoardIT)
{
    ui->setupUi(this);

    mThread = new MyThread(this);
    connect(mThread, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));

    mThread->start();
}

BoardIT::~BoardIT()
{
    delete ui;
}

void BoardIT::onTextChanged(QString Number)
{
    QString temp_text_hast = Number;
    temp_text_hast.prepend("<p align='right'><span style=' font-size:36pt; color:#ff0004;'>");
    temp_text_hast.append("</span></p>");

    QString temp_text_bat = Number;
    temp_text_bat.prepend("<p align='right'><span style=' font-size:36pt; color:#ab23ff;'>");
    temp_text_bat.append("</span></p>");

    ui->label->setText(temp_text_hast);
    ui->label_2->setText(temp_text_hast);
    ui->label_3->setText(temp_text_bat);
    ui->label_4->setText(temp_text_bat);
}
