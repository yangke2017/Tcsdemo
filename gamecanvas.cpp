#include "gamecanvas.h"
#include "QPainter"
#include "cstdlib"
#include "qdebug.h"
#include "iostream"

Gamecanvas::Gamecanvas(QWidget *parent) : QWidget(parent)
{

     for (int i = 0; i< _countof(boxs); i++)
         for (int j = 0; j< _countof(boxs[i]); j++)
         {
             boxs[i][j].setIscolor(false);
         }
 //this->setFocusPolicy(Qt::StrongFocus);
}


void Gamecanvas::finning()
{
   boxwidth = this->width() / 30;
   boxheight = this->height() / 20;
}

//返回 boxs[row][col]
TcsBox* Gamecanvas::getBox(int row, int col)
{

    if (row < 0 || (row > _countof(boxs) - 1) || col < 0
            || (col > _countof(boxs[0]) - 1))
        return NULL;
    else
        return (*boxs + 30 * row ) + col ;
}

void Gamecanvas::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
    case (Qt::Key_A):

        break;
    case (Qt::Key_D):

        break;
    default:
        qDebug() << "Gamecanvas KeyPressed";
        break;
    }
}

void Gamecanvas::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    frontColor =  QColor(255, 215, 0);
    backColor = QColor(105, 105, 105);
    QPainter painter(this);
    painter.setPen(QPen(QColor(0, 160, 230), 2));
    finning();

    for (int i = 0; i < _countof(boxs); i++)

        for (int j = 0; j < _countof(boxs[i]); j++)
        {

            if (boxs[i][j].isIscolor())
                painter.setBrush(frontColor);
            else
                painter.setBrush(backColor);

            painter.drawRect(j * boxwidth, i * boxheight, boxwidth, boxheight);

        }
}

void Gamecanvas::reset()
{
    for (int i =0; i< _countof(boxs); i++)
        for (int j = 0; j < _countof(boxs[i]); j++)
        {
            boxs[i][j].setIscolor(false);
        }

    repaint();
}


