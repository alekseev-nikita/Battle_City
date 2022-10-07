#include "Headers/Enemy.h"

Enemy::Enemy(unsigned int x, unsigned int y) : Tank(x, y) {
    tank_img.setRotation(180.f);
    tank_img.setColor(sf::Color(0, 255, 0));
}
void Enemy::update(Player &player, sf::RenderWindow *window) {
    for(Shell &shell : ShellsController::ingame_shells) {
        if(tank_img.getGlobalBounds().intersects(shell.getShape().getGlobalBounds())) {
            alive = false;
            shell.alive = false;
            return;
        }
    }

    //player detection
    char attack_direction = getDirectionToVisiblePlayer(player, window);
    if(attack_direction != -1) {
        //turn that direction
        tank_img.setRotation(90.f * attack_direction);
    }

    //write shoots & movement
}

char Enemy::getDirectionToVisiblePlayer(Player &player, sf::RenderWindow *window) {
    for(char direction = 0; direction < 4; ++direction) {
        sf::RectangleShape line(sf::Vector2f(2.f, -CELL_SIZE));
        line.setOrigin(sf::Vector2f(1.f, 0.f));
        line.setPosition(tank_img.getPosition().x, tank_img.getPosition().y);
        line.setFillColor(sf::Color(255, 255, 0));
        line.setRotation(90.f * direction);
        
        unsigned char ray_length = 1;
        const unsigned char RAY_MAX_LENGTH = 10;
        while(ray_length != RAY_MAX_LENGTH) {
            line.setScale(1.f, ray_length);
            if(line.getGlobalBounds().intersects(player.getPlayer().getGlobalBounds())) {
                line.setFillColor(sf::Color(255, 0, 0));
                window->draw(line);
                return direction;
            }
            else {
                ++ray_length;
            }
        }
        
        //draw
        window->draw(line);
    }
    return -1;
}
