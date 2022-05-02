#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

#include "item.h"

/**
  Creates a new Point object with coordinates x and y
  @param x int x coordinate
  @param y int y coordinate
*/
Item::Item(Tiletype tile, const int x, const int y, int width, int height) {
  tile_ = tile;
  prev_tile_ = tile;
  x_ = x;
  y_ = y;
  height_ = height;
  width_ = width;
}
void Item::set_x(const int x){
    x_ = x;
}
void Item::set_y(const int y){
    y_ = y;
}
void Item::set_tiletype(const Tiletype new_tile){
    tile_ = new_tile;
}


//in point.cpp
void Item::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

    qDebug() << "item selected!";

    // Day 3, Task 1
    // Change the color of the point when the user clicks on it

    // change to a new color
     if(x_ %29 != 0){
        tile_ = selected;
        emit ItemSelected(this);
     }

    // need to make the point actually re-paint itself
    update();

}
QRectF Item::boundingRect() const
{
    return QRectF(x_, y_, width_, height_);
}

// define the actual shape of the object
QPainterPath Item::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, height_);
    return path;
}

// called by Qt to actually display the point
void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    // update the line for setBrush to be this
    //set Brush based on tiletype
    switch (tile_)
    {
        case empty:
            painter->setBrush(QBrush(QColor(200,200,200)));
            break;
        case ship:
            painter->setBrush(QBrush(QColor(150,75,0)));
            break;
        case chest:
            painter->setBrush(QBrush(QColor(255,215,0)));
            break;
        case mine:
            painter->setBrush(QBrush(QColor(0,0,0)));
            break;
        case miss:
            painter->setBrush(QBrush(QColor(60,75,200)));
            break;
        case hit_ship:
            painter->setBrush(QBrush(QColor(175,55,55)));
            break;
        case hit_chest:
            painter->setBrush(QBrush(QColor(255,255,0)));
            break;
        case hit_mine:
            painter->setBrush(QBrush(QColor(0,0,0)));
            break;
        case selected:
            painter->setBrush(QBrush(QColor(0,191,255)));
            break;
    }
    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->height_));
    painter->setBrush(b);
}

