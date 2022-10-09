#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "Headers/Map.h"
#include "Headers/Player.h"
#include "Headers/Enemy.h"
#include "Headers/Shell.h"
#include "Headers/ShellsController.h"
#include "Headers/EnemiesController.h"
#include "Headers/GameOver.h"

constexpr unsigned int WINDOW_SIZE = 800;

int main()
{
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Battle City");
    window->setFramerateLimit(30);

    sf::SoundBuffer main_theme;
    sf::Sound sound;
    main_theme.loadFromFile("../resources/theme.wav");
    sound.setBuffer(main_theme);
    sound.setVolume(70.f);
    sound.setLoop(true);
    sound.play();

    Map map;

    Player player(WINDOW_SIZE / 2, WINDOW_SIZE / 1.33);

    std::vector<Enemy *> enemies;

    GameOver game_over(WINDOW_SIZE / 2, WINDOW_SIZE / 2);

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

        if(enemies.size() == 0) {
            for(sf::Vector2f spawn_point : map.spawn_points) {
                enemies.push_back(new Enemy(spawn_point.x, spawn_point.y));
            }
        }

        window->clear();
        map.drawMap(window);

        if(!player.alive) {
            window->draw(game_over.getSprite());
            window->display();
            continue;
        }

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