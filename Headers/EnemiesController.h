#pragma once
#include "Enemy.h"

class EnemiesController {
    public:
        static void controll(std::vector<Enemy *> &enemies, Player &player, sf::RenderWindow *window);
};