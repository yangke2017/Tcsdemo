#include "gamecanvas.h"
#include "QPainter"
#include "cstdlib"
#include "qdebug.h"
#include "iostream"

Gamecanvas::Gamecanvas(QWidget *parent) : QWidget(parent)
{ // 构造函数，双循环赋值，将box.iscolor设置为 false

     for (int i = 0; i< _countof(boxs); i++)
         for (int j = 0; j< _countof(boxs[i]); j++)
         {
             boxs[i][j].setIscolor(false);
         }
 //this->setFocusPolicy(Qt::StrongFocus);
}

//获取窗口（widget）的长宽，确定每个小box的长款。以适应窗口变化
void Gamecanvas::finning()
{
   boxwidth = this->width() / 30;
   boxheight = this->height() / 20;
}

//返回指向 boxs[row][col]的指针
TcsBox* Gamecanvas::getBox(int row, int col)
{//如果（row，col）坐标有box，则返回box指针；没有box返回空

    if (row < 0 || (row > _countof(boxs) - 1) || col < 0
            || (col > _countof(boxs[0]) - 1))
        return NULL;
    else
        return (*boxs + 30 * row ) + col ;
}


//QPainter绘图，绘制 TcsBox[20][30]

void Gamecanvas::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);                               //声明 event 不使用。不然编译有一个warning
    frontColor =  QColor(255, 215, 0);             //设置前景色
    backColor = QColor(105, 105, 105);             //设置背景色
    QPainter painter(this);                        //创建画笔
    painter.setPen(QPen(QColor(0, 160, 230), 2));  //设置画笔
    finning();                                     //确定box的长宽
	//双循环将box一个一个画出来，这样效率很低。关注 QGraphicsview 类
    for (int i = 0; i < _countof(boxs); i++)

        for (int j = 0; j < _countof(boxs[i]); j++)
        {

            if (boxs[i][j].isIscolor())
                painter.setBrush(frontColor);      //如果box的iscolor为true，设置背景色为 frontcolor
            else
                painter.setBrush(backColor);       //如果box的iscolor为false，设置背景色为 backcolor

            painter.drawRect(j * boxwidth, i * boxheight, boxwidth, boxheight);  //画小方形

        }
}


//重置画布，将每个box的iscolor参数设置为false。
void Gamecanvas::reset()
{
    for (int i =0; i< _countof(boxs); i++)
        for (int j = 0; j < _countof(boxs[i]); j++)
        {
            boxs[i][j].setIscolor(false);
        }

    repaint();  //刷新UI
}


