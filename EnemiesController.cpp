#include "Headers/EnemiesController.h"

void EnemiesController::controll(std::vector<Enemy *> &enemies, Player &player, sf::RenderWindow *window) {
    auto it = enemies.begin();
        while(it != enemies.end()) {
            if(!(*it)->alive) {
                Enemy *p = (*it);
                it = enemies.erase(it);
                delete p;
            }
            else {
                (*it)->update(player, window);
                (*it)->drawTank(window);
                ++it;
            }
        }
}