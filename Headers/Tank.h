#pragma once
#include <SFML/Graphics.hpp>
#include "Shell.h"

constexpr unsigned char TANK_SIZE = 38;
constexpr unsigned char TANK_SPEED = 3;
struct Position
{
    unsigned int x;
    unsigned int y;
};

class Tank {
    protected:
        Position position;
        sf::Sprite tank_img;
        sf::Texture texture;
        std::vector<Shell> shells;
        unsigned char fire_rate = 10;
        unsigned char fire_timer = 0;
        sf::Clock clock;
    public:
        Tank(unsigned int x, unsigned int y);
        void drawTank(sf::RenderWindow *win, std::vector<sf::RectangleShape> *walls);
        virtual void update(std::vector<sf::RectangleShape> *walls);
        void shoot();
};