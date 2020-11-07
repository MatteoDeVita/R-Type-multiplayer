/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Action
*/

#include "Action.hpp"
#include <iostream>

gameEngine_ns::action_ns::Action::Action()
{
    this->_isEnable = false;
}

gameEngine_ns::action_ns::Action::Action(gameEngine_ns::object_ns::Object *relatedObject)
{
    this->_relatedObject = relatedObject;
    this->_isEnable = false;
}

gameEngine_ns::action_ns::Action::~Action()
{

}

void gameEngine_ns::action_ns::Action::setActionObject(gameEngine_ns::object_ns::Object *actionObject)
{
    this->_actionObject = actionObject;
}

void gameEngine_ns::action_ns::Action::setRelatedObject(gameEngine_ns::object_ns::Object *relatedObject)
{
    this->_relatedObject = relatedObject;
}

bool gameEngine_ns::action_ns::Action::isEnable()
{
    return this->_isEnable;
}
