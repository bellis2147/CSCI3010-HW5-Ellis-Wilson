#include "game.h"

Game::Game(QGraphicsView *view, QGraphicsScene * scene, QGraphicsView *view_2, QGraphicsScene * scene_2 )
{
    view_ = view;
    scene_ = scene;
    view_2_ = view_2;
    scene_2_ = scene_2;
}
/*
QRectF Game::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}

// define the actual shape of the object
QPainterPath Game::shape() const
{
    QPainterPath path;
    path.addEllipse(x_, y_, width_, width_);
    return path;
}
*/
