/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Moove
*/

#include "Moove.hpp"


gameEngine_ns::action_ns::Moove::Moove(
    gameEngine_ns::object_ns::Object *relatedObject,
    const gameEngine_ns::geometry_ns::Vector &speed
) : gameEngine_ns::action_ns::Action(relatedObject)
{
    this->_speed = speed;
}


gameEngine_ns::action_ns::Moove::Moove()
{
    this->_relatedObject = nullptr;
}

gameEngine_ns::action_ns::Moove::~Moove()
{
}
