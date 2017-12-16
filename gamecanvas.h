#ifndef GAMECANVAS_H
#define GAMECANVAS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QColor>
#include "tcsbox.h"
#include "QPaintEvent"
#include "QPainter"




class Gamecanvas : public QWidget  //¼Ì³ÐQWidge´°¿ÚÀà
{
    Q_OBJECT
public:
    explicit Gamecanvas(QWidget *parent = 0);

    void finning();
    TcsBox* getBox(int row,int col);
    void reset();
    void paintEvent(QPaintEvent *event);

private:
    TcsBox boxs[20][30];
    //TcsBox (*p)[30] = boxs;


    double boxwidth, boxheight;
    int x, y, k = 0;
    QColor frontColor;
    QColor backColor;



signals:

public slots:


};

#endif // GAMECANVAS_H
