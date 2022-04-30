/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *plotGraphicsView;
    QGraphicsView *plotGraphicsView_2;
    QLabel *player1;
    QLabel *player2;
    QLabel *curr_player;
    QLabel *coordinates_label;
    QLineEdit *coordinates_entered;
    QLabel *to_shoot;
    QPushButton *enter_button;
    QGraphicsView *ships_view;
    QGraphicsView *ships_view_2;
    QLabel *label;
    QPushButton *place_ship_buttton;
    QLineEdit *ship_input_x;
    QPushButton *Start_Game;
    QPushButton *Quit_Game;
    QLineEdit *ship_input_y;
    QMenuBar *menubar;
    QMenu *menuBattleship;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plotGraphicsView = new QGraphicsView(centralwidget);
        plotGraphicsView->setObjectName(QString::fromUtf8("plotGraphicsView"));
        plotGraphicsView->setGeometry(QRect(0, 130, 321, 321));
        plotGraphicsView_2 = new QGraphicsView(centralwidget);
        plotGraphicsView_2->setObjectName(QString::fromUtf8("plotGraphicsView_2"));
        plotGraphicsView_2->setGeometry(QRect(480, 130, 321, 321));
        player1 = new QLabel(centralwidget);
        player1->setObjectName(QString::fromUtf8("player1"));
        player1->setGeometry(QRect(120, 80, 111, 20));
        player2 = new QLabel(centralwidget);
        player2->setObjectName(QString::fromUtf8("player2"));
        player2->setGeometry(QRect(630, 80, 111, 20));
        curr_player = new QLabel(centralwidget);
        curr_player->setObjectName(QString::fromUtf8("curr_player"));
        curr_player->setGeometry(QRect(350, 150, 91, 16));
        coordinates_label = new QLabel(centralwidget);
        coordinates_label->setObjectName(QString::fromUtf8("coordinates_label"));
        coordinates_label->setGeometry(QRect(350, 180, 161, 20));
        coordinates_entered = new QLineEdit(centralwidget);
        coordinates_entered->setObjectName(QString::fromUtf8("coordinates_entered"));
        coordinates_entered->setGeometry(QRect(350, 220, 113, 20));
        to_shoot = new QLabel(centralwidget);
        to_shoot->setObjectName(QString::fromUtf8("to_shoot"));
        to_shoot->setGeometry(QRect(370, 200, 61, 16));
        enter_button = new QPushButton(centralwidget);
        enter_button->setObjectName(QString::fromUtf8("enter_button"));
        enter_button->setGeometry(QRect(360, 250, 80, 31));
        ships_view = new QGraphicsView(centralwidget);
        ships_view->setObjectName(QString::fromUtf8("ships_view"));
        ships_view->setGeometry(QRect(0, 460, 301, 101));
        ships_view_2 = new QGraphicsView(centralwidget);
        ships_view_2->setObjectName(QString::fromUtf8("ships_view_2"));
        ships_view_2->setGeometry(QRect(500, 460, 301, 101));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 460, 161, 20));
        place_ship_buttton = new QPushButton(centralwidget);
        place_ship_buttton->setObjectName(QString::fromUtf8("place_ship_buttton"));
        place_ship_buttton->setGeometry(QRect(360, 520, 80, 31));
        ship_input_x = new QLineEdit(centralwidget);
        ship_input_x->setObjectName(QString::fromUtf8("ship_input_x"));
        ship_input_x->setGeometry(QRect(360, 490, 31, 20));
        Start_Game = new QPushButton(centralwidget);
        Start_Game->setObjectName(QString::fromUtf8("Start_Game"));
        Start_Game->setGeometry(QRect(360, 397, 91, 31));
        Quit_Game = new QPushButton(centralwidget);
        Quit_Game->setObjectName(QString::fromUtf8("Quit_Game"));
        Quit_Game->setGeometry(QRect(710, 10, 80, 18));
        ship_input_y = new QLineEdit(centralwidget);
        ship_input_y->setObjectName(QString::fromUtf8("ship_input_y"));
        ship_input_y->setGeometry(QRect(410, 490, 31, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuBattleship = new QMenu(menubar);
        menuBattleship->setObjectName(QString::fromUtf8("menuBattleship"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuBattleship->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        player1->setText(QCoreApplication::translate("MainWindow", "Player 1", nullptr));
        player2->setText(QCoreApplication::translate("MainWindow", "Player 2", nullptr));
        curr_player->setText(QCoreApplication::translate("MainWindow", "Current Player", nullptr));
        coordinates_label->setText(QCoreApplication::translate("MainWindow", "Enter coordinates", nullptr));
        to_shoot->setText(QCoreApplication::translate("MainWindow", "to shoot:", nullptr));
        enter_button->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Place selected ship starting at:", nullptr));
        place_ship_buttton->setText(QCoreApplication::translate("MainWindow", "Place", nullptr));
        Start_Game->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        Quit_Game->setText(QCoreApplication::translate("MainWindow", "Quit Game", nullptr));
        menuBattleship->setTitle(QCoreApplication::translate("MainWindow", "Battleship", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H