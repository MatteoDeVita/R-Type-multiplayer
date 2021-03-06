/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Monster
*/

#include <iostream>

#include "Monster.hpp"

Monster::Monster()
{
    this->_posClock = new sf::Clock; 
    this->_damageClock = new sf::Clock;
    this->_damageClock->restart();
}

Monster::Monster(
    gameEngine_ns::object_ns::Sprite *sprite,
    const int &hp,
    const gameEngine_ns::geometry_ns::Vector &position
) : gameEngine_ns::object_ns::Object(sprite, position)
{
    this->_posClock = new sf::Clock;
    this->_hp = hp;
    this->_damageClock = new sf::Clock;
    this->_damageClock->restart();
}

Monster::~Monster()
{
    delete this->_posClock;
    delete this->_damageClock;
}

void Monster::autoUpdatePos()
{    
    if (this->_posClock->getElapsedTime().asMilliseconds() >= 30) {
        this->moove(gameEngine_ns::geometry_ns::Vector(-((rand() % 12) + 5), (rand() % 10) - 5));
        if (this->getPos().y <= 15)
            this->moove(gameEngine_ns::geometry_ns::Vector(0, 20));
        this->_posClock->restart();
    }
}

void Monster::damage()
{
    if (this->_damageClock != nullptr && this->_damageClock->getElapsedTime().asMilliseconds() > 250) {
        this->_hp--;
        this->_damageClock->restart();
    }
}

int Monster::getHp() const
{
    return this->_hp;
}