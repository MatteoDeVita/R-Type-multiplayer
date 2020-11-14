/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Explosion
*/

#include "Explosion.hpp"

Explosion::Explosion()
{
    this->_isActive = false;
    this->activeClock = new sf::Clock;
    this->activeClock->restart();
}

Explosion::Explosion(
    gameEngine_ns::object_ns::Sprite *sprite,
    const gameEngine_ns::geometry_ns::Vector &position
) : gameEngine_ns::object_ns::Object(sprite, position)
{
    this->_isActive = false;
    this->activeClock = new sf::Clock;
    this->activeClock->restart();
}

Explosion::~Explosion()
{
    if (this->activeClock != nullptr)
        delete this->activeClock;
}

// bool Explosion::isActive()
// {
//     if (this->_activeClock->getElapsedTime().asMilliseconds() >= 50 * 6) {        
//         this->_isActive = false;
//         this->_activeClock->restart();
//     }
//     return this->_isActive;
// }

// void Explosion::setActive(const bool &active)
// {
//     this->_isActive = active;
//     this->_activeClock->restart();
// }
