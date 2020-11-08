/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Moove
*/

#include <iostream>

#include "Moove.hpp"

gameEngine_ns::action_ns::Moove::Moove(
    gameEngine_ns::object_ns::Object *relatedObject,
    const gameEngine_ns::geometry_ns::Vector &vector,
    const float &speed
) : gameEngine_ns::action_ns::Action(relatedObject)
{
    this->_vector = vector;
    this->_speed = speed;
    this->_clock = new sf::Clock;    
    this->_clock->restart();
}


gameEngine_ns::action_ns::Moove::Moove()
{
    this->_relatedObject = nullptr;
    this->_clock = new sf::Clock;
    this->_clock->restart();
}

gameEngine_ns::action_ns::Moove::~Moove()
{
    if (this->_clock != nullptr)
        delete this->_clock;
}

void gameEngine_ns::action_ns::Moove::setVector(const gameEngine_ns::geometry_ns::Vector &vector)
{
    this->_vector = vector;
}

void gameEngine_ns::action_ns::Moove::act()
{
    this->_isEnable = true;
    if (this->_clock->getElapsedTime().asMilliseconds() >= this->_speed) {
        this->_relatedObject->getSprite()->moove(this->_vector);
        this->_clock->restart();
    }
}

void gameEngine_ns::action_ns::Moove::disable()
{
    this->_isEnable = false;
}
