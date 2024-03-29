#ifndef ITEM_H
#define ITEM_H
#include <QColor>
#include <QGraphicsItem>


enum Tiletype{empty, ship, chest, mine, miss, hit_ship, hit_chest, hit_mine, selected};

struct Tile{
    Tiletype type;
    int x_pos;
    int y_pos;
};

class Item : public QObject, public QGraphicsItem
{
    // this makes it so that we can emit signals
    Q_OBJECT

public:
    Item(Tiletype tile, const int x, const int y, int width, int height);  // constructor
    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function
    int get_width() const { return width_; }  // inline member function
    int get_height() const { return height_; }  // inline member function
    Tiletype get_tiletype() const {return tile_;}
    Tiletype get_prev_tiletype() const {return prev_tile_;}
    void set_x(const int x);
    void set_y(const int y);
    void set_color(const QColor color);
    void set_tiletype(const Tiletype new_type);

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
  Tiletype tile_;
  Tiletype prev_tile_;
};

#endif // ITEM_H




