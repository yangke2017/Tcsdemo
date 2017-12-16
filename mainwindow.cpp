#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  "food.h"
#include "gamecanvas.h"
#include "snake.h"
#include "qdebug.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	//以上为生成，以下为添加。添加 Game下拉菜单里面的Exit按钮。当然使用qtdesigner 添加也可以，双击.ui文件打开qt designer
	//代码自动生成。现在UI开发基本上先用qt Designer设计大概框架，再用代码补充
	//生成的界面文件位于：项目目录/Generated Files/ui_mainwindow.h
    QAction *actionExit = new QAction(this);             
    actionExit->setObjectName(QStringLiteral("actionExit"));
    ui->menuGame->addAction(actionExit);
    actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));

	//将信号和槽函数连接起来，点击exit按钮，发射信号 triggered(),执行SLOT_exit()函数
    connect(actionExit, SIGNAL(triggered()), this, SLOT(SLOT_exit()));

    /*
    snake = new Snake(ui->canvas, 6, 10);
    food = new Food(ui->canvas);
    QObject::connect(snake, SIGNAL(&Snake::emitUIupdateMessage), this, SLOT(&MainWindow::canvasRepaint));
    */
}

//析构函数，（生成）
MainWindow::~MainWindow()
{
    delete ui;
}

//键盘响应，键盘响应写的复杂了,不必在意
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "run key Press";
    if (snake->confirm == 'd')
    {
        switch (e->key())
        {
        case (Qt::Key_A):
            snake->direction = 'l';
            break;
        case (Qt::Key_D):
            snake->direction = 'r';
            break;
        default:
            qDebug() << "KeyPressed";
            break;
        }
    }

    if (snake->confirm == 'u')
    {
        switch (e->key())
        {
        case (Qt::Key_A):
            snake->direction = 'l';
            break;
        case (Qt::Key_D):
            snake->direction = 'r';
            break;
        default:
            qDebug() << "KeyPressed";
            break;
        }
    }

    if (snake->confirm == 'r' || snake->confirm == 'l')
    {
        switch (e->key())
        {
        case (Qt::Key_S):
            snake->direction = 'd';
            qDebug() << "press Key S";
            break;
        case (Qt::Key_W):
            snake->direction = 'u';
            break;
        default:
            qDebug() << "KeyPressed";
            break;

        }
    }
}


//startGame
void MainWindow::SLOT_startGame()
{
    qDebug() << "begin to start\n";
    ui->canvas->reset();  //清空画布
    Game();               //运行game函数
}

void MainWindow::SLOT_pauseGame()
{
    snake->pausing = true;     //暂停游戏
}

void MainWindow::SLOT_continueGame()
{
    snake->pausing = false;    //继续游戏
}

void MainWindow::SLOT_stopGame()
{
    snake->exit();     //结束线程
}

void MainWindow::SLOT_exit()
{

}

void MainWindow::reportGameover()
{
   QMessageBox::about(NULL, "About", "Game over");   //弹窗显示 Game Over
}

void MainWindow::Game()
{
    snake = new Snake(ui->canvas, 6, 10);   //创建蛇对象实例
    food = new Food(ui->canvas);            //创建食物对象实例

    connect(snake, SIGNAL(emitUIupdateMessage()), this, SLOT(canvasRepaint()));  //连接信号与槽，snake执行时不断刷新UI
    connect(snake, SIGNAL(emitThreadstopMessage()), this, SLOT(reportGameover()));  //snake执行完毕时，报告游戏结束
    qDebug() << "food snake init()";
    snake->start();              //开启线程，snake必须用线程。要不然程序一直在snake移动的循环里面，跳不出来。其他函数无法执行
	                             //当一个程序进入一个大的循环里面不能在短时间出来，程序没有响应，这就是用户感受到的程序卡顿。
	                               


}

//刷新UI
void MainWindow::canvasRepaint()
{

    ui->canvas->repaint();
}

//停止游戏
void MainWindow::on_actionStart_triggered()
{
    //reportGameover();
    SLOT_startGame();
}

//暂停游戏
void MainWindow::on_actionPause_triggered()
{
    SLOT_pauseGame();
}

//继续游戏
void MainWindow::on_actionContinue_triggered()
{
    SLOT_continueGame();
}
