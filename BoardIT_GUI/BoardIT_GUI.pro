#-------------------------------------------------
#
# Project created by QtCreator 2014-11-07T12:57:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BoardIT_GUI
TEMPLATE = app


SOURCES += main.cpp\
        boardit.cpp \
    mythread.cpp

HEADERS  += boardit.h \
    mythread.h

FORMS    += boardit.ui
