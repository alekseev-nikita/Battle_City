#include "ShellsController.h"

std::vector<Shell> ShellsController::ingame_shells = {};

void ShellsController::updateAllShells() {
    auto it = ShellsController::ingame_shells.begin();
    while(it != ShellsController::ingame_shells.end()) {
        it->update();
        bool is_deleted = false;
        for(sf::RectangleShape &wall : Map::walls) {
            if(it->getShape().getGlobalBounds().intersects(wall.getGlobalBounds())) {
                it = ShellsController::ingame_shells.erase(it);
                is_deleted = true;
                break;
            }
        }
        if(!is_deleted) {
            ++it;
        }
    }
}

void ShellsController::drawAllShells(sf::RenderWindow *win) {
    auto it = ShellsController::ingame_shells.begin();
    while (it != ShellsController::ingame_shells.end())
    {
        if(it->alive) {
            it->draw(win);
        }
        ++it;
    }
}