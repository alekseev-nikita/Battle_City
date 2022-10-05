#include "Headers/Enemy.h"

Enemy::Enemy(unsigned int x, unsigned int y) : Tank(x, y) {
    tank_img.setRotation(180.f);
    tank_img.setColor(sf::Color(0, 255, 0));
}
void Enemy::update(std::vector<sf::RectangleShape> *walls) {
    //write shoots & movement
}
