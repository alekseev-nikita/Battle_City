#include <SFML/Graphics.hpp>
#include <string>
#include "Headers/Map.h"
#include "Headers/Player.h"
#include "Headers/Enemy.h"
#include "Headers/Shell.h"
#include "Headers/ShellsController.h"
#include "Headers/EnemiesController.h"

constexpr unsigned int WINDOW_SIZE = 800;

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Battle City");
    window->setFramerateLimit(30);
    Map map;

    Player player(WINDOW_SIZE / 2, WINDOW_SIZE / 1.33);

    //spawn enemies
    std::vector<Enemy *> enemies;
    for(sf::Vector2f spawn_point : map.spawn_points) {
        enemies.push_back(new Enemy(spawn_point.x, spawn_point.y));
    }
    

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

        //draw player
        player.update();
        player.drawTank(window);

        //draw enemy
        EnemiesController::controll(enemies, player, window);

        //draw shells
        ShellsController::updateAllShells();
        ShellsController::drawAllShells(window);

        window->display();
    }
    delete window;
}