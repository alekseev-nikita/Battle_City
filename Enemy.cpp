#include "Headers/Enemy.h"

Enemy::Enemy(unsigned int x, unsigned int y) : Tank(x, y) {
    tank_img.setRotation(180.f);
    tank_img.setColor(sf::Color(0, 255, 0));
    std::random_device rd;
    gen = std::mt19937(rd());
    distr = std::uniform_int_distribution<>(0, 3);
    move_direction = distr(gen);
}
void Enemy::update(Player &player, sf::RenderWindow *window) {
    for(Shell &shell : ShellsController::ingame_shells) {
        if(tank_img.getGlobalBounds().intersects(shell.getShape().getGlobalBounds())) {
            alive = false;
            shell.alive = false;
            return;
        }
    }

    char attack_direction = getDirectionToVisiblePlayer(player, window);
    if(attack_direction != -1) {
        tank_img.setRotation(90.f * attack_direction);
        shoot();
    }
    else {
        move(window, player);
    }
}
void Enemy::move(sf::RenderWindow *window, Player &player) {
    sf::RectangleShape fwd_wand(sf::Vector2f(2.f, -CELL_SIZE));
    fwd_wand.setOrigin(sf::Vector2f(1.f, 0.f));
    fwd_wand.setFillColor(sf::Color(0, 255, 0));
    fwd_wand.setPosition(tank_img.getPosition().x, tank_img.getPosition().y);
    fwd_wand.setRotation(tank_img.getRotation());

    for(sf::RectangleShape &wall : Map::walls) {
        if(fwd_wand.getGlobalBounds().intersects(wall.getGlobalBounds())) {
            std::cout << "Wall Collision !" << std::endl;
            unsigned char old_direction = move_direction;
            while(old_direction == move_direction) {
                move_direction = distr(gen);
                std::cout << "Direction = " << move_direction << std::endl;
            }
            tank_img.setRotation(90.f * move_direction);
            return;
        }
    }

    tank_img.setRotation(90.f * move_direction);
    switch (move_direction) {
        case 0:
            position.y -= TANK_SPEED;
            break;
    
        case 1:
            position.x += TANK_SPEED;
            break;
            
        case 2:
            position.y += TANK_SPEED;
            break;
        
        case 3:
            position.x -= TANK_SPEED;
            break;
    }
}

char Enemy::getDirectionToVisiblePlayer(Player &player, sf::RenderWindow *window) {
    for(char direction = 0; direction < 4; ++direction) {
        sf::RectangleShape line(sf::Vector2f(2.f, -CELL_SIZE));
        line.setOrigin(sf::Vector2f(1.f, 0.f));
        line.setPosition(tank_img.getPosition().x, tank_img.getPosition().y);
        line.setFillColor(sf::Color(255, 255, 0));
        line.setRotation(90.f * direction);
        
        unsigned char ray_length = 1;
        const unsigned char RAY_MAX_LENGTH = 30;
        while(ray_length != RAY_MAX_LENGTH) {
            line.setSize(sf::Vector2f(2.f, (-CELL_SIZE/2) * ray_length));
            
            //checkwalls
            bool wall_collision = false;
            for(sf::RectangleShape &wall : Map::walls) {
                if(line.getGlobalBounds().intersects(wall.getGlobalBounds())) {
                    wall_collision = true;
                    break;
                }
            }
            if(wall_collision) {
                break;
            }

            if(line.getGlobalBounds().intersects(player.getPlayer().getGlobalBounds())) {
                line.setFillColor(sf::Color(255, 0, 0));
                return direction;
            }
            else {
                ++ray_length;
            }
        }
    }
    return -1;
}
