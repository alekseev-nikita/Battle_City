#include "Headers/GameOver.h"

GameOver::GameOver(unsigned int x, unsigned int y) {
    texture.loadFromFile("../game_over.png");
    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2));
    sprite.setPosition(sf::Vector2f(x, y));
}

sf::Sprite& GameOver::getSprite() {
    return sprite;
}