#ifndef PLAYER_H
#define PLAYER_H
#include "item.h"
#include <vector>


class Player
{
public:
    Player(std::vector<Item*> items);
    void add_item(Item* item);
    void remove_item(int position);
    std::vector<Item*> get_items(){return items_;}

private:
    std::vector<Item*> items_;
};

#endif // PLAYER_H
