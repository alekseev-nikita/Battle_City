#pragma once
#include <SFML/Graphics.hpp>

class Shell {
    private:
        unsigned char speed = 10;
        sf::Vector2f position;
        sf::Vector2f direction;
        float r = 5;
        std::size_t d = 10;
        sf::CircleShape shell_img;
    public:
        bool alive = true;
        Shell(sf::Vector2f pos, sf::Vector2f dir);
        void draw(sf::RenderWindow *win);
        void update();
        sf::CircleShape getShape();
};