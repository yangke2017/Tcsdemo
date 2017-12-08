#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include "Food.h"
#include "gamecanvas.h"
#include "QList"
#include "QString"
#include "QThread"
#include "stddef.h"
//#include "qdebug.h"

class Snake : public QThread
{
    Q_OBJECT
signals:
    void emitUIupdateMessage();
    void emitThreadstopMessage();
public:
   // Snake(QObject* parent = 0);
    Snake(Gamecanvas *canvas, int x, int y);
    QList<TcsBox> getSnake();
    void setSnake(QList<TcsBox> snake);
    void moveleft();
    void moveright();
    void moveup();
    void movedown();
    int score();
    void run();
    bool moveTo(int newRow, int newCol);
    bool isMoveAble(int newRow, int newCol);
    void display();
    void earse();
    char direction, confirm = 'r';
    bool moving = true;
    bool pausing = false;
    bool contain(TcsBox);

private:
    QList<TcsBox*> snake;
    Gamecanvas *canvas;
    int x, y;

    Food food;


};

#endif // SNAKE_H
