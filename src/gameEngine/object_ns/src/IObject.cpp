/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** IObject
*/

#include "IObject.hpp"

gameEngine_ns::object_ns::IObject::IObject()
{
    this->activeClock = new sf::Clock;
}

gameEngine_ns::object_ns::IObject::~IObject()
{
    delete this->activeClock;
}
