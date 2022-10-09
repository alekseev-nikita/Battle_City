#pragma once
#include "Tank.h"
#include "Player.h"
#include <random>

class Enemy : public Tank {
    private:
        unsigned int move_direction;
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<> distr;
        char getDirectionToVisiblePlayer(Player &player, sf::RenderWindow *window);
        void move(sf::RenderWindow *window, Player &player);
    public:
        Enemy(unsigned int x, unsigned int y);
        void update(Player &player, sf::RenderWindow *window);
};