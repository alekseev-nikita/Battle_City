#pragma once
#include "Enemy.h"

class EnemiesController {
    public:
        static void controll(std::vector<Enemy *> &enemies, sf::RenderWindow *window);
};