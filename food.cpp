#include "food.h"
#include "qdebug.h"
Food::Food()
{

}

Food::Food(Gamecanvas *canvas)
{
    qDebug() << "food gouzao";

    this->canvas = canvas;

        foodRow = (int) (this->random(20));
        foodCol = (int) (this->random(30));


        canvas->getBox(foodRow, foodCol)->setIscolor(true);


}
//生成 [0, x) 随机数
int Food::random(int x)
{
    int seed = QDateTime::currentDateTime().time().second();
    srand(seed);
    return rand() % (x);
}

Food::Food(int foodRow, int foodCol)
{
    this->foodRow = foodRow;
    this->foodCol = foodCol;
}

int Food::getFoodRow()
{
    return foodRow;
}

void Food::setFoodRow(int foodRow)
{
    this->foodRow = foodRow;
}

int Food::getFoodCol()
{
    return foodCol;
}

void Food::setFoodCol(int foodCol)
{
    this->foodCol = foodCol;
}
