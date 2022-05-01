#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPainter>
#include "game.h"
#include "item.h"
#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void Game_Loop();
    ~MainWindow();

private slots:
    void ItemSelectedSlot(Item *p);
    void PlaceItemSlot1();
    void PlaceItemSlot2();
    void QuitSlot();
    void HideBoard1Slot();
    void HideBoard2Slot();
    void ShowBoard1Slot();
    void ShowBoard2Slot();
    void StartGameSlot();
    void AttackSlot();
    void start_game();
private:
    Ui::MainWindow *ui_;
    QGraphicsView *view_;
    QGraphicsScene *scene_;
    QGraphicsView *view_2_;
    QGraphicsScene *scene_2_;
    QGraphicsView *view_3_;
    QGraphicsScene *scene_3_;
    QGraphicsView *view_4_;
    QGraphicsScene *scene_4_;
    Item * curr_item_;
    bool quit_;
    Player* player_1_;
    Player* player_2_;
    std::vector<Item*> shot_one_;
    std::vector<Item*> shot_two_;

    Game *game_;
};
#endif // MAINWINDOW_H
