#ifndef ITEM_H
#define ITEM_H
#include <QColor>
#include <QGraphicsItem>

class Item : public QObject, public QGraphicsItem
{
    // this makes it so that we can emit signals
    Q_OBJECT

public:
    Item(QColor color, const int x, const int y, int width, int height);  // constructor

    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function
    int get_width() const { return width_; }  // inline member function
    int get_height() const { return height_; }  // inline member function
    void set_x(int x);
    void set_y(int y);
    void set_color(QColor color);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

// in point.h
signals:

    // Day 2, Task 3
    void ItemSelected(Item *p);

    void DeleteItem(Item *p);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;


private:
  int x_;
  int y_;
  int height_;
  int width_;
  QColor color_;
};

#endif // ITEM_H




