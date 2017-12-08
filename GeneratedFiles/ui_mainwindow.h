/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include "gamecanvas.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart;
    QAction *actionPause;
    QAction *actionContinue;
    QAction *actionStop;
    Gamecanvas *canvas;
    QMenuBar *menuBar;
    QMenu *menuGame;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setFocusPolicy(Qt::WheelFocus);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionContinue = new QAction(MainWindow);
        actionContinue->setObjectName(QStringLiteral("actionContinue"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        canvas = new Gamecanvas(MainWindow);
        canvas->setObjectName(QStringLiteral("canvas"));
        MainWindow->setCentralWidget(canvas);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 17));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QStringLiteral("menuGame"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGame->menuAction());
        menuGame->addAction(actionStart);
        menuGame->addAction(actionPause);
        menuGame->addAction(actionContinue);
        menuGame->addAction(actionStop);
        mainToolBar->addAction(actionStart);
        mainToolBar->addAction(actionPause);
        mainToolBar->addAction(actionContinue);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionStart->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", Q_NULLPTR));
        actionContinue->setText(QApplication::translate("MainWindow", "Continue", Q_NULLPTR));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
