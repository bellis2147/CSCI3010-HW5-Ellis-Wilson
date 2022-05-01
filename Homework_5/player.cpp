#include "player.h"

Player::Player(std::vector<Item*> items)
{
    items_ = items;
    powerUp_ = false;
}
void Player::add_item(Item* item){
    items_.push_back(item);
}
void Player::remove_item(int position){
    items_.erase(items_.begin() + position);
}
void Player::set_powerUp(bool powerUp)
{
    powerUp_ = powerUp;
}
