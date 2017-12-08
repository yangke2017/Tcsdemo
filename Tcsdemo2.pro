#-------------------------------------------------
#
# Project created by QtCreator 2017-11-17T16:44:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tcsdemo2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcsbox.cpp \
    gamecanvas.cpp \
    food.cpp \
    snake.cpp

HEADERS  += mainwindow.h \
    tcsbox.h \
    gamecanvas.h \
    food.h \
    snake.h

FORMS    += mainwindow.ui
