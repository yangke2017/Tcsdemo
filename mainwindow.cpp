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
    QAction *actionExit = new QAction(this);
    actionExit->setObjectName(QStringLiteral("actionExit"));
    ui->menuGame->addAction(actionExit);
    actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
    connect(actionExit, SIGNAL(triggered()), this, SLOT(SLOT_exit()));
    this->setFocusPolicy(Qt::StrongFocus);
    /*
    snake = new Snake(ui->canvas, 6, 10);
    food = new Food(ui->canvas);
    QObject::connect(snake, SIGNAL(&Snake::emitUIupdateMessage), this, SLOT(&MainWindow::canvasRepaint));
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

void MainWindow::SLOT_startGame()
{
    qDebug() << "begin to start\n";
    ui->canvas->reset();
    Game();
}

void MainWindow::SLOT_pauseGame()
{
    snake->pausing = true;
}

void MainWindow::SLOT_continueGame()
{
    snake->pausing = false;
}

void MainWindow::SLOT_stopGame()
{
    snake->exit();
}

void MainWindow::SLOT_exit()
{

}

void MainWindow::reportGameover()
{
   QMessageBox::about(NULL, "About", "Game over");
}

void MainWindow::Game()
{
    snake = new Snake(ui->canvas, 6, 10);
    food = new Food(ui->canvas);

    connect(snake, SIGNAL(emitUIupdateMessage()), this, SLOT(canvasRepaint()));
    connect(snake, SIGNAL(emitThreadstopMessage()), this, SLOT(reportGameover()));
    qDebug() << "food snake init()";
    snake->start();


}


void MainWindow::canvasRepaint()
{

    ui->canvas->repaint();
}

void MainWindow::on_actionStart_triggered()
{
    //reportGameover();
    SLOT_startGame();
}

void MainWindow::on_actionPause_triggered()
{
    SLOT_pauseGame();
}

void MainWindow::on_actionContinue_triggered()
{
    SLOT_continueGame();
}
