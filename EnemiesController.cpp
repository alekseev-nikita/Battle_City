#include "Headers/EnemiesController.h"

void EnemiesController::controll(std::vector<Enemy *> &enemies, sf::RenderWindow *window) {
    auto it = enemies.begin();
        while(it != enemies.end()) {
            if(!(*it)->alive) {
                Enemy *p = (*it);
                it = enemies.erase(it);
                delete p;
            }
            else {
                (*it)->update();
                (*it)->drawTank(window);
                ++it;
            }
        }
}