#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsItem>

class Game : public QObject, public QGraphicsItem {
public:
    Game(QGraphicsView *view, QGraphicsScene * scene, QGraphicsView *view_2, QGraphicsScene * scene_2 );
    //QRectF boundingRect() const override;
    //QPainterPath shape() const override;
private:
    QGraphicsView *view_;
    QGraphicsScene *scene_;
    QGraphicsView *view_2_;
    QGraphicsScene *scene_2_;
};

#endif // GAME_H
