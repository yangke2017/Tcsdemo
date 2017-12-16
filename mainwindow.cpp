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

	//����Ϊ���ɣ�����Ϊ��ӡ���� Game�����˵������Exit��ť����Ȼʹ��qtdesigner ���Ҳ���ԣ�˫��.ui�ļ���qt designer
	//�����Զ����ɡ�����UI��������������qt Designer��ƴ�ſ�ܣ����ô��벹��
	//���ɵĽ����ļ�λ�ڣ���ĿĿ¼/Generated Files/ui_mainwindow.h
    QAction *actionExit = new QAction(this);             
    actionExit->setObjectName(QStringLiteral("actionExit"));
    ui->menuGame->addAction(actionExit);
    actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));

	//���źźͲۺ����������������exit��ť�������ź� triggered(),ִ��SLOT_exit()����
    connect(actionExit, SIGNAL(triggered()), this, SLOT(SLOT_exit()));

    /*
    snake = new Snake(ui->canvas, 6, 10);
    food = new Food(ui->canvas);
    QObject::connect(snake, SIGNAL(&Snake::emitUIupdateMessage), this, SLOT(&MainWindow::canvasRepaint));
    */
}

//���������������ɣ�
MainWindow::~MainWindow()
{
    delete ui;
}

//������Ӧ��������Ӧд�ĸ�����,��������
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
    ui->canvas->reset();  //��ջ���
    Game();               //����game����
}

void MainWindow::SLOT_pauseGame()
{
    snake->pausing = true;     //��ͣ��Ϸ
}

void MainWindow::SLOT_continueGame()
{
    snake->pausing = false;    //������Ϸ
}

void MainWindow::SLOT_stopGame()
{
    snake->exit();     //�����߳�
}

void MainWindow::SLOT_exit()
{

}

void MainWindow::reportGameover()
{
   QMessageBox::about(NULL, "About", "Game over");   //������ʾ Game Over
}

void MainWindow::Game()
{
    snake = new Snake(ui->canvas, 6, 10);   //�����߶���ʵ��
    food = new Food(ui->canvas);            //����ʳ�����ʵ��

    connect(snake, SIGNAL(emitUIupdateMessage()), this, SLOT(canvasRepaint()));  //�����ź���ۣ�snakeִ��ʱ����ˢ��UI
    connect(snake, SIGNAL(emitThreadstopMessage()), this, SLOT(reportGameover()));  //snakeִ�����ʱ��������Ϸ����
    qDebug() << "food snake init()";
    snake->start();              //�����̣߳�snake�������̡߳�Ҫ��Ȼ����һֱ��snake�ƶ���ѭ�����棬�������������������޷�ִ��
	                             //��һ���������һ�����ѭ�����治���ڶ�ʱ�����������û����Ӧ��������û����ܵ��ĳ��򿨶١�
	                               


}

//ˢ��UI
void MainWindow::canvasRepaint()
{

    ui->canvas->repaint();
}

//ֹͣ��Ϸ
void MainWindow::on_actionStart_triggered()
{
    //reportGameover();
    SLOT_startGame();
}

//��ͣ��Ϸ
void MainWindow::on_actionPause_triggered()
{
    SLOT_pauseGame();
}

//������Ϸ
void MainWindow::on_actionContinue_triggered()
{
    SLOT_continueGame();
}
