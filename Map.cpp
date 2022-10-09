#include "Headers/Map.h"

std::vector<sf::RectangleShape> Map::walls = {};

Map::Map() {
    cell = sf::RectangleShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    //cell.setFillColor(sf::Color(255, 0, 0));
    texture.loadFromFile("../resources/wall.png");
    cell.setTexture(&texture);
    for(unsigned int x = 0; x < MAP_SIZE; ++x) {
        for(unsigned int y = 0; y < MAP_SIZE; ++y) {
            if(MAP[x][y] == '#') {
                cell.setPosition(CELL_SIZE * y, CELL_SIZE * x);
                walls.push_back(cell);
            }
            else if(MAP[x][y] == '*') {
                spawn_points.push_back(sf::Vector2f(CELL_SIZE * y, CELL_SIZE * x));
            }
        }
    }
}
void Map::drawMap(sf::RenderWindow *win) {
    for(sf::RectangleShape cell : walls) {
        win->draw(cell);
    }
}