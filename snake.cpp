#include "snake.h"
#include "qdebug.h"

Snake::Snake(Gamecanvas*canvas, int x, int y)
{

   // moveToThread(this);
    this->canvas = canvas;
    this->x = x;
    this->y = y;
    snake << canvas->getBox(x, y)
          << canvas->getBox(x, y - 1)
          << canvas->getBox(x, y - 2);
    display();
}



void Snake::moveleft()
{
    moveTo(x, y - 1);
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

int Snake::score()
{
    return (snake.size() - 3) * 10;

}

void Snake::run()
{
    qDebug() << "thread snake is running\n";
    while(moving)
    {
        emit emitUIupdateMessage();
        qDebug() << "进入循环";
        msleep(150);
        if(!pausing)
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
   emit emitThreadstopMessage();
}

bool Snake::moveTo(int newRow, int newCol)
{
    if (!isMoveAble(newRow, newCol) || !moving)
    {
        qDebug() << "can't move";
        return false;
    }
    else
    {
        if ((*canvas).getBox(newRow, newCol)->isIscolor())
        {
           earse();
           x = newRow;
           y = newCol;

           snake.insert(0, (*canvas).getBox(x, y));
           switch (direction)
           {
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

          food = Food(canvas);
          qDebug() << snake.size();
          display();

          return true;
        }

        earse();
        x = newRow;
        y = newCol;


        snake.insert(0, (*canvas).getBox(x, y));
        snake.removeLast();
        display();

        return true;

    }
}

bool Snake::isMoveAble(int newRow, int newCol)
{
    TcsBox box = canvas->getBox(newRow, newCol);

    if (box == NULL)
        return false;



    else if (box.isIscolor())
    {
        return true;
    }
    else
        return true;
}


void Snake::display()
{
    for (int i = 0; i < snake.size(); i++)
    {
        snake.at(i)->setIscolor(true);

        qDebug() << "snake display finished\n";
    }
}

void Snake::earse()
{
    for (int i = 0; i < snake.size(); i++)
    {
       snake.at(i)->setIscolor(false);
    }

}
