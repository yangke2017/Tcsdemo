#ifndef FOOD_H
#define FOOD_H
#include "gamecanvas.h"
#include "QDateTime"
#include "QDate"


class Food
{
public:
    Food();
    Food(Gamecanvas *canvas);
    Food(int foodRow, int foodCol);
    int getFoodRow();
    void setFoodRow(int foodRow);
    int getFoodCol();
    void setFoodCol(int foodCol);
    int random(int x);

private:
    int foodRow, foodCol;
    TcsBox box;
    Gamecanvas *canvas;


};

#endif // FOOD_H
