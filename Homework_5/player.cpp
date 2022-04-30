#include "player.h"

Player::Player(std::vector<Item*> items)
{
    items_ = items;
}
void Player::add_item(Item* item){
    items_.push_back(item);
}
