#include "Headers/Player.h"

Player::Player(unsigned int x, unsigned int y) : Tank(x, y){}

sf::Sprite& Player::getPlayer() {
    return tank_img;
}
