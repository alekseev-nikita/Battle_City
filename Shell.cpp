#include "Headers/Shell.h"

Shell::Shell(sf::Vector2f pos, sf::Vector2f dir) {
    shell_img = sf::CircleShape(r, d);
    shell_img.setFillColor(sf::Color(255, 255, 0));
    shell_img.setOrigin(r, r);
    position = pos + sf::Vector2f(dir.x * 30.f, dir.y * 30.f);
    direction = dir;
    shell_img.setPosition(position);
}
sf::CircleShape Shell::getShape() {
    return shell_img;
}
void Shell::draw(sf::RenderWindow *win) {
    win->draw(shell_img);
}
void Shell::update() {
    position += sf::Vector2f(direction.x * speed, direction.y * speed);
    shell_img.setPosition(position);
}