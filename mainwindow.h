#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "gamecanvas.h"
#include "food.h"
#include "snake.h"
#include "QThread"

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

/*
class GameRepaint : public QThread
{
public:
    void run()
    {
        bool isGameover = true;
        while (isGameover)
        {
            ui->canvas->repaint();
        }
        if (isGameover == false)
            reportGameover();
    }
};

class Event : public QObject
{
    Q_OBJECT
public:
    Event(QWidget * MainWindow) //主窗口指针
    { this->installEventFilter ( MainWindow); }
protected:
    bool eventFilter(QEvent *);//在这里捕获主窗口的的所有事件，可以自己做处理
};
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent * e);
    void Game();

private slots:
    void SLOT_startGame();
    void SLOT_pauseGame();
    void SLOT_continueGame();
    void SLOT_stopGame();
    void SLOT_exit();
    void reportGameover();
    void canvasRepaint();

    void on_actionStart_triggered();

    void on_actionPause_triggered();

    void on_actionContinue_triggered();

private:
    Ui::MainWindow *ui;
   // Gamecanvas *canvas;
    bool playing = true;
    bool m;
    bool pausing = false;
    Snake *snake;
    Food *food;


};

#endif // MAINWINDOW_H
