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
Item::Item(Tiletype tile, QColor color, const int x, const int y, int width, int height) {
  this->color_ = color;
   tile_ = tile;
  x_ = x;
  y_ = y;
  height_ = height;
  width_ = width;
}
Item::Item(QColor color, const int x, const int y, int width, int height) {
  this->color_ = color;
  x_ = x;
  y_ = y;
  height_ = height;
  width_ = width;
}
void Item::set_x(int x){
    x_ = x;
}
void Item::set_y(int y){
    y_ = y;
}
void Item::set_color(QColor color){
    color_ = color;
}


//in point.cpp
void Item::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);

    qDebug() << "item selected!";
    emit ItemSelected(this);

    emit DeleteItem(this);


    // Day 3, Task 1
    // Change the color of the point when the user clicks on it

    // change to a new color
    QColor c(0, 191, 255);
    color_ = c;

    // need to make the point actually re-paint itself
    update();
}

// where is this object located
// always a rectangle, Qt uses this to know "where" the user
// would be interacting with this object
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
    painter->setBrush(QBrush(color_));
    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->height_));
    painter->setBrush(b);
}

