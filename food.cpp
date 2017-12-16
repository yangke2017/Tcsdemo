#include "food.h"
#include "qdebug.h"
Food::Food()
{

}

Food::Food(Gamecanvas *canvas)
{//随机生成坐标，将相应坐标的box的iscolor设置为ture.

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

//构造函数
Food::Food(int foodRow, int foodCol)
{
    this->foodRow = foodRow;
    this->foodCol = foodCol;
}

//返回食物坐标
int Food::getFoodRow()
{
    return foodRow;
}

//设置食物坐标
void Food::setFoodRow(int foodRow)
{
    this->foodRow = foodRow;
}

//返回食物坐标
int Food::getFoodCol()
{
    return foodCol;
}

//设置食物坐标
void Food::setFoodCol(int foodCol)
{
    this->foodCol = foodCol;
}
