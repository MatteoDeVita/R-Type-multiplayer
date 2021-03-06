/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Laser
*/

#include "Laser.hpp"

Laser::Laser()
{
    this->_laserClock = new sf::Clock;
    this->_leftToRight = true;
    this->_laserClock->restart();
    this->_yValue = (rand() % 12) - 6;
    this->_xValue = (rand() % 8) - 4;
    
}

Laser::Laser(
    gameEngine_ns::object_ns::Sprite *sprite,
    const bool &leftToRight,
    const gameEngine_ns::geometry_ns::Vector &position
) : gameEngine_ns::object_ns::Object(sprite, position)
{
    this->_laserClock = new sf::Clock;
    this->_leftToRight = leftToRight;
    this->_laserClock->restart();
    this->_yValue = (rand() % 12) - 6;
    this->_xValue = (rand() % 6) - 3;
    
}

Laser::~Laser()
{
    delete this->_laserClock;
}

void Laser::autoMoove()
{
    if (this->_laserClock->getElapsedTime().asMilliseconds() >= 10) {
        this->moove(gameEngine_ns::geometry_ns::Vector(
            this->_leftToRight ? 20 : -15,
            this->_leftToRight ? this->_xValue : this->_yValue
        ));
        this->_laserClock->restart();
    }
}

bool Laser::isFromMonster() const
{
    return !this->_leftToRight;
}