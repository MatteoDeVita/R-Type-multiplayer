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
}

Monster::Monster(
    gameEngine_ns::object_ns::Sprite *sprite,
    const gameEngine_ns::geometry_ns::Vector &position
) : gameEngine_ns::object_ns::Object(sprite, position)
{
    this->_posClock = new sf::Clock;
}

Monster::~Monster()
{
    delete this->_posClock;
}

void Monster::autoUpdatePos()
{
    if (this->_posClock->getElapsedTime().asMilliseconds() >= (rand() % 2500) + 100) {
        std::cout << "AAAAHA" << std::endl;
        this->moove(gameEngine_ns::geometry_ns::Vector(-((rand() % 90) + 10), (rand() % 100) - 50));
        this->_posClock->restart();
    }
}
