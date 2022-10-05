#include "Headers/Map.h"

Map::Map() {
    cell = sf::RectangleShape(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
    cell.setFillColor(sf::Color(255, 0, 0));
    for(unsigned int x = 0; x < MAP_SIZE; ++x) {
        for(unsigned int y = 0; y < MAP_SIZE; ++y) {
            if(MAP[x][y] == '#') {
                cell.setPosition(CELL_SIZE * y, CELL_SIZE * x);
                walls.push_back(cell);
            }
        }
    }
}
void Map::drawMap(sf::RenderWindow *win) {
    for(sf::RectangleShape cell : walls) {
        win->draw(cell);
    }
}