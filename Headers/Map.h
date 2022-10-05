#pragma once
#include <SFML/Graphics.hpp>
#include <string>

constexpr unsigned int MAP_SIZE = 40;
constexpr unsigned char CELL_SIZE = 40;
class Map {
    private:
        sf::RectangleShape cell;
        const std::array<std::string, MAP_SIZE> MAP = {
        "####################",
        "#                  #",
        "# *    *    *    * #",
        "#  #  #  ##  #  #  #",
        "#  #  #  ##  #  #  #",
        "#  #  #  ##  #  #  #",
        "#     #  ##  #     #",
        "#     #      #     #",
        "###   ########   ###",
        "#     #      #     #",
        "#     #  ##  #     #",
        "#  #  #  ##  #  #  #",
        "#  #  #  ##  #  #  #",
        "#  #  #  ##  #  #  #",
        "#  #            #  #",
        "#  #            #  #",
        "#      ######      #",
        "#      #    #      #",
        "#      #    #      #",
        "####################",
    };
    public:
        Map();
        std::vector<sf::RectangleShape> walls;
        std::vector<sf::Vector2f> spawn_points;
        void drawMap(sf::RenderWindow *win);
};