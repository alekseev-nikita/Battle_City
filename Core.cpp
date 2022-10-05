#include <SFML/Graphics.hpp>
#include <string>
#include "Headers/Map.h"
#include "Headers/Tank.h"
#include "Headers/Shell.h"

constexpr unsigned int WINDOW_SIZE = 800;

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Battle City");
    window->setFramerateLimit(30);
    Map map;

    Tank players_tank(WINDOW_SIZE / 2, WINDOW_SIZE / 1.33);
    

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window->close();
            }
        }

        window->clear();

        map.drawMap(window);

        players_tank.update(&map.walls);
        players_tank.drawTank(window, &map.walls);

        

        window->display();
    }
    delete window;
}