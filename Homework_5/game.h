#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "item.h"

class Game {
public:
    //Game(QGraphicsView *view, QGraphicsScene * scene, QGraphicsView *view_2, QGraphicsScene * scene_2);
    Game();
    void change_tile(Tiletype new_type, int player_num, int x_pos, int y_pos);
    Tile get_tile(int set_num, int x_pos, int y_pos);
    void next_turn();
    int get_player_turn();
    //QRectF boundingRect() const override;
    //QPainterPath shape() const override;
private:
    /*QGraphicsView *view_;
    QGraphicsScene *scene_;
    QGraphicsView *view_2_;
    QGraphicsScene *scene_2_;*/
    int player_turn_;
    Tile tileset_one[10][10];
    Tile tileset_two[10][10];
};

#endif // GAME_H
