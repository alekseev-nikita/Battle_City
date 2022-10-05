#pragma once
#include "Tank.h"

class Enemy : public Tank {
    public:
        Enemy(unsigned int x, unsigned int y);
        void update(std::vector<sf::RectangleShape> *walls) override; 
};