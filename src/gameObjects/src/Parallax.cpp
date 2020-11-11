/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Parallax
*/

#include "Parallax.hpp"

Parallax::Parallax()
{
    this->_speed = 1;
    this->_mooveClock = new sf::Clock;
}

Parallax::~Parallax()
{
    delete this->_mooveClock;
}

Parallax::Parallax(
    gameEngine_ns::object_ns::Sprite *sprite,
    const unsigned int &speed,
    const gameEngine_ns::geometry_ns::Vector &position
) : gameEngine_ns::object_ns::Object(sprite, position)
{
    this->_speed = speed;
    this->_mooveClock = new sf::Clock;
}

void Parallax::autoMoove(const gameEngine_ns::geometry_ns::Vector &vector)
{
    if (this->_mooveClock->getElapsedTime().asMilliseconds() >= 20) {
        if (this->getPos().x <= -1600)
            this->setPos(gameEngine_ns::geometry_ns::Vector(1600));
        this->moove(vector);
        this->_mooveClock->restart();
    }
}
 
void Parallax::autoMoove()
{
    if (this->_mooveClock->getElapsedTime().asMilliseconds() >= 20) {
        if (this->getPos().x <= -1600)
            this->setPos(gameEngine_ns::geometry_ns::Vector(1600));
        this->moove(gameEngine_ns::geometry_ns::Vector(
            -1 * this->_speed,
            0
        ));
        this->_mooveClock->restart();
    }
}

void Parallax::setSpeed(const unsigned int &speed)
{
    this->_speed = speed;
}