#include "Headers/Tank.h"

Tank::Tank(unsigned int x, unsigned int y) {
    position.x = x;
    position.y = y;
    texture.loadFromFile("../tank.png");
    tank_img.setTexture(texture);
    sf::Rect sprite_size = tank_img.getGlobalBounds();
    tank_img.setOrigin(sf::Vector2f(sprite_size.width / 2, sprite_size.height / 2));
    tank_img.setScale(0.1, 0.1);
    tank_img.setPosition(position.x, position.y);
    
}
void Tank::drawTank(sf::RenderWindow *win, std::vector<sf::RectangleShape> *walls) {
    tank_img.setPosition(position.x, position.y);
    win->draw(tank_img);

    auto it = shells.begin();
    while(it != shells.end()) {
        it->draw(win);
        ++it;
    }
}
void Tank::update(std::vector<sf::RectangleShape> *walls) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == 1) {
        shoot();
    }
    
    //
    auto it = shells.begin();
    while(it != shells.end()) {
        it->update();
        bool is_deleted = false;
        for(sf::RectangleShape &wall : *walls) {
            if(it->getShape().getGlobalBounds().intersects(wall.getGlobalBounds())) {
                it = shells.erase(it);
                is_deleted = true;
                break;
            }
        }
        if(!is_deleted) {
            ++it;
        }
    }
    //

    Position origin_position = position;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == 1) {
        tank_img.setRotation(0.f);
        position.y -= TANK_SPEED;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) == 1) {
        tank_img.setRotation(180.f);
        position.y += TANK_SPEED;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) == 1) {
        tank_img.setRotation(270.f);
        position.x -= TANK_SPEED;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) == 1) {
        tank_img.setRotation(90.f);
        position.x += TANK_SPEED;
    }
    tank_img.setPosition(position.x, position.y);

    for(sf::RectangleShape wall : *walls) {
        if(tank_img.getGlobalBounds().intersects(wall.getGlobalBounds())) {
            position = origin_position;
            return;
        }
    }
}
void Tank::shoot() {
    if(clock.getElapsedTime().asMilliseconds() >= 500 ) {
        auto rot = tank_img.getRotation();
        if(rot == 0) {
            shells.push_back(Shell(tank_img.getPosition(), sf::Vector2f(0.f, -1.f)));
        }
        else if(rot == 90) {
            shells.push_back(Shell(tank_img.getPosition(), sf::Vector2f(1.f, 0.f)));
        }
        else if(rot == 180) {
            shells.push_back(Shell(tank_img.getPosition(), sf::Vector2f(0.f, 1.f)));
        }
        else {
            shells.push_back(Shell(tank_img.getPosition(), sf::Vector2f(-1.f, 0.f)));
        }
        clock.restart();
    }
}