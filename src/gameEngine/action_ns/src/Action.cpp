/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Action
*/

#include "Action.hpp"

gameEngine_ns::action_ns::Action::Action()
{

}

gameEngine_ns::action_ns::Action::Action(gameEngine_ns::object_ns::Object *relatedObject)
{
    this->_relatedObject = relatedObject;
}

gameEngine_ns::action_ns::Action::~Action()
{

}

void gameEngine_ns::action_ns::Action::setActionObject(gameEngine_ns::object_ns::Object *actionObject)
{
    this->_actionObject = actionObject;
}
