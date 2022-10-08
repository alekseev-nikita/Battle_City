#pragma once
#include <SFML/Graphics.hpp>

class GameOver {
    private:
        sf::Texture texture;
        sf::Sprite sprite;
    public:
        GameOver(unsigned int x, unsigned int y);
        sf::Sprite& getSprite();
};
