#include "snake.h"
#include "qdebug.h"

Snake::Snake(Gamecanvas*canvas, int x, int y)
{  //构造函数，传入画布，蛇头坐标（x，y）。
   //因为要改变画布相应位置的box颜色，画布类 Gamecanvas 一定要用指针传递！
	//包括Gamecanvas的 getBox 函数，一定要返回指针！

  
    this->canvas = canvas;
    this->x = x;
    this->y = y;
    snake << canvas->getBox(x, y)              //snake链表初始化，将指向这三个位置的box的指针放在QList里面
          << canvas->getBox(x, y - 1)
          << canvas->getBox(x, y - 2);
    display();                                 //显示
}



void Snake::moveleft()
{
    moveTo(x, y - 1);  //右键moveTo转到定义，查看moveTo函数。
}

void Snake::moveright()
{
    moveTo(x, y + 1);
}

void Snake::moveup()
{
    moveTo(x + 1, y);
}

void Snake::movedown()
{
    moveTo(x - 1, y);
}

//得分
int Snake::score()
{
    return (snake.size() - 3) * 10;

}

//线程体
void Snake::run()
{
    qDebug() << "thread snake is running\n";
    while(moving)
    {
        emit emitUIupdateMessage();  //发射信号给 mainwindow，让其刷新 UI。connect（SIGNAL, SLOT）
        qDebug() << "进入循环";       //控制台输出，检查有没有进入run（）；
        msleep(150);                 //休眠 150ms，过150ms执行下一句
        if(!pausing)                 //如果没有暂停，开始移动
            switch (direction)  
            {
            case ('r'):
                moving = (moveTo(x, y + 1) && moving);
                confirm = 'r';        
                break;
            case ('l'):
                moving = (moveTo(x, y - 1) && moving);
                confirm = 'l';
                break;
            case ('d'):
                moving = (moveTo(x + 1, y) && moving);
                confirm = 'd';
                break;
            case ('u'):
                moving = (moveTo(x - 1, y) && moving);
                confirm = 'u';
                break;
            default:

                moving = (moveTo(x, y + 1) && moving);
                confirm = 'r';

                break;
            }

    }
   emit emitThreadstopMessage();   //如果跳出循环，发射信号（线程结束）给 mainwindow，报告游戏结束
}


//蛇头移动到（newRow，newCol)
bool Snake::moveTo(int newRow, int newCol)
{
    if (!isMoveAble(newRow, newCol) || !moving) 
    {//蛇头不能移动到新的位置
        qDebug() << "can't move";
        return false;
    }
    else
    {//开始移动
        if ((*canvas).getBox(newRow, newCol)->isIscolor()) //遇到有颜色的box，认为：吃到食物
        {
           earse();  //先把以前的一帧擦掉
           x = newRow;  //新的蛇头位置为 （newRow，newCol）
           y = newCol;

          snake.insert(0, (*canvas).getBox(x, y));  //蛇头前面加一块box

		  switch (direction) {
		  case ('r'):
			  moveright();
			  break;
		  case ('l'):
			  moveleft();
			  break;
		  case ('d'):
			  moveup();
			  break;
		  case ('u'):
			  movedown();
			  break;
		  default:
			  break;
		  }

          food = Food(canvas);        //新建食物
          qDebug() << snake.size();   //控制台输出snake链表的元素个数
          display();                  //之前操作的都是snake的链表元素，现在让这些元素显示，iscolor = true；

          return true;
        }
		//没有吃到食物的情况
		else
		{
			earse();            //先擦掉原来的
			x = newRow;         //新的蛇头位置为（newRow，newCol）
			y = newCol;


			snake.insert(0, (*canvas).getBox(x, y));  //前面加一个方块
			snake.removeLast();                       //后面减一个方块
			display();                                //显示

			return true;
		}

    }
}

//判断蛇头是不是可以移动到新的位置。蛇碰到自己不死bug出在这里
bool Snake::isMoveAble(int newRow, int newCol)
{
    TcsBox* box = canvas->getBox(newRow, newCol);

	for (int i = 0; i < snake.size(); i++)
	{
		if (box == snake.at(i))
			return false;
	}
    if (box == NULL)
        return false;
   // else if (snake.contains(box))
	//else if (box == snake.at)
    //{
    //    return false;
    //}
	else
	   return true;
    
}

//把蛇从UI显示，把snake的box的iscolor参数设置为true
void Snake::display()
{
    for (int i = 0; i < snake.size(); i++)
    {
        snake.at(i)->setIscolor(true);

        qDebug() << "snake display finished\n";
    }
}

//把蛇从UI擦掉，把snake的box的iscolor参数设置为false
void Snake::earse()
{
    for (int i = 0; i < snake.size(); i++)
    {
       snake.at(i)->setIscolor(false);
    }

}
