#pragma once
#include "Tank.h"
#include "Player.h"

class Enemy : public Tank {
    private:
        char getDirectionToVisiblePlayer(Player &player, sf::RenderWindow *window);
    public:
        Enemy(unsigned int x, unsigned int y);
        void update(Player &player, sf::RenderWindow *window); 
};