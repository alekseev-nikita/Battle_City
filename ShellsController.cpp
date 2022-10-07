#include "ShellsController.h"

std::vector<Shell> ShellsController::ingame_shells = {};

void ShellsController::updateAllShells() {
    auto it = ShellsController::ingame_shells.begin();
    while(it != ShellsController::ingame_shells.end()) {
        it->update();

        if(!it->alive) {
            it = ShellsController::ingame_shells.erase(it);
            continue;
        }

        bool to_delete = false;
        for(sf::RectangleShape &wall : Map::walls) {
            if(it->getShape().getGlobalBounds().intersects(wall.getGlobalBounds())) {
                it->alive = false;
                to_delete = true;
                it = ShellsController::ingame_shells.erase(it);
                break;
            }
        }
        if(!to_delete) {
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