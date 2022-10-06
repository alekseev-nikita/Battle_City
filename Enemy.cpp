#include "Headers/Enemy.h"

Enemy::Enemy(unsigned int x, unsigned int y) : Tank(x, y) {
    tank_img.setRotation(180.f);
    tank_img.setColor(sf::Color(0, 255, 0));
}
void Enemy::update() {
    for(Shell &shell : ShellsController::ingame_shells) {
        if(tank_img.getGlobalBounds().intersects(shell.getShape().getGlobalBounds())) {
            alive = false;
            shell.alive = false;
            return;
        }
    }
    //write shoots & movement
}
