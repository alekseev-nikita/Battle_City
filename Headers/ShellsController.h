#pragma once
#include "Shell.h"
#include "Map.h"

class ShellsController {
    public:
        static std::vector<Shell> ingame_shells;
        static void updateAllShells();
        static void drawAllShells(sf::RenderWindow *win);
};