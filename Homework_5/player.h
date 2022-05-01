#ifndef PLAYER_H
#define PLAYER_H
#include "item.h"
#include <vector>


class Player
{
public:
    Player(std::vector<Item*> items);
    bool get_powerUp() const {return powerUp_;};
    void add_item(Item* item);
    void remove_item(int position);
    void set_powerUp(bool powerUp);
    std::vector<Item*> get_items(){return items_;}

private:
    std::vector<Item*> items_;
    bool powerUp_;
};

#endif // PLAYER_H
