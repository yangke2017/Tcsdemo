#include "UIrepaint.h"

UIRepaint::UIRepaint(QObject* par,Snake* snake)
{
    this->snake = snake;
}

void UIRepaint::run()
{
    if (snake->isRunning())
    {
       bool m = true;
       while (m)
       {
         msleep(200);

           emit sendUIrepaintMessage();
           m = snake->isRunning();
       }
        emit sendStopMessage();
    }

     return;
}

