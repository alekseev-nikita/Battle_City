#include "Headers/Tank.h"

Tank::Tank(unsigned int x, unsigned int y)
{
    shot_sound.loadFromFile("../resources/shot.wav");
    position.x = x;
    position.y = y;
    texture.loadFromFile("../resources/tank.png");
    tank_img.setTexture(texture);
    sf::Rect sprite_size = tank_img.getGlobalBounds();
    tank_img.setOrigin(sf::Vector2f(sprite_size.width / 2, sprite_size.height / 2));
    tank_img.setScale(0.1, 0.1);
    tank_img.setPosition(position.x, position.y);
}
void Tank::drawTank(sf::RenderWindow *win)
{
    tank_img.setPosition(position.x, position.y);
    win->draw(tank_img);
}
void Tank::update()
{
    for(Shell &shell : ShellsController::ingame_shells) {
        if(tank_img.getGlobalBounds().intersects(shell.getShape().getGlobalBounds())) {
            alive = false;
            shell.alive = false;
            return;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == 1)
    {
        shoot();
    }

    Position origin_position = position;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) == 1)
    {
        tank_img.setRotation(0.f);
        position.y -= TANK_SPEED;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) == 1)
    {
        tank_img.setRotation(180.f);
        position.y += TANK_SPEED;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) == 1)
    {
        tank_img.setRotation(270.f);
        position.x -= TANK_SPEED;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) == 1)
    {
        tank_img.setRotation(90.f);
        position.x += TANK_SPEED;
    }
    tank_img.setPosition(position.x, position.y);

    for (sf::RectangleShape &wall : Map::walls)
    {
        if (tank_img.getGlobalBounds().intersects(wall.getGlobalBounds()))
        {
            position = origin_position;
            return;
        }
    }
}
void Tank::shoot()
{
    if (clock.getElapsedTime().asMilliseconds() >= shoot_delay)
    {
        auto rot = tank_img.getRotation();
        sound.setBuffer(shot_sound);
        sound.play();
        if (rot == 0)
        {
            ShellsController::ingame_shells.push_back(Shell(tank_img.getPosition(), sf::Vector2f(0.f, -1.f)));
        }
        else if (rot == 90)
        {
            ShellsController::ingame_shells.push_back(Shell(tank_img.getPosition(), sf::Vector2f(1.f, 0.f)));
        }
        else if (rot == 180)
        {
            ShellsController::ingame_shells.push_back(Shell(tank_img.getPosition(), sf::Vector2f(0.f, 1.f)));
        }
        else
        {
            ShellsController::ingame_shells.push_back(Shell(tank_img.getPosition(), sf::Vector2f(-1.f, 0.f)));
        }
        clock.restart();
    }
}