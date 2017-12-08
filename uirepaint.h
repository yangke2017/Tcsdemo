#ifndef UIREPAINT_H
#define UIREPAINT_H
#include "snake.h"
#include "qthread.h"
#include "qdebug.h"


class UIRepaint : public QThread
{
    Q_OBJECT
signals:
    void sendUIrepaintMessage();
    void sendStopMessage();
public:
    UIRepaint(QObject* par, Snake* snake);
    void run();
private:
    Snake* snake;
};

#endif // UIREPAINT_H
