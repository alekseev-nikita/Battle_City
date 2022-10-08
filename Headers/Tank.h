#pragma once
#include <SFML/Graphics.hpp>
#include "Shell.h"
#include "ShellsController.h"
#include "Map.h"

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
        sf::Clock clock;
        unsigned int shoot_delay = 1000;
    public:
        bool alive = true;
        Tank(unsigned int x, unsigned int y);
        void drawTank(sf::RenderWindow *win);
        virtual void update();
        void shoot();
};