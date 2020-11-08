/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Object
*/

#include <iostream>

#include "Object.hpp"
#include "Error.hpp"

gameEngine_ns::object_ns::Object::Object(gameEngine_ns::object_ns::Sprite *sprite, const gameEngine_ns::geometry_ns::Vector &position)
{
    this->_sprite = sprite;
    this->_position = position;
}

gameEngine_ns::object_ns::Sprite * gameEngine_ns::object_ns::Object::getSprite() const
{
    return this->_sprite;
}

gameEngine_ns::geometry_ns::Vector gameEngine_ns::object_ns::Object::getPos() const
{
    return this->_position;
}

void gameEngine_ns::object_ns::Object::setPos(const gameEngine_ns::geometry_ns::Vector &vector)
{    
    this->_position = _position;
    this->_sprite->getSFMLSprite()->setPosition(vector.toSfVector2f());
}

gameEngine_ns::object_ns::Object::~Object()
{

}

int gameEngine_ns::object_ns::Object::addAction(const std::string &id, gameEngine_ns::action_ns::IAction *action)
{
    if (this->_actions.insert(std::make_pair(id, action)).second == false) {
        std::cerr << "An action with id \"" << id << "\" already exists." << std::endl;
        return -1;
    }
    return 0;
}

gameEngine_ns::action_ns::IAction *gameEngine_ns::object_ns::Object::getAction(const std::string &id) const
{
    if (this->_actions.count(id) == false)
            return nullptr;
    return this->_actions.at(id);
}

std::map<const std::string, gameEngine_ns::action_ns::IAction *> gameEngine_ns::object_ns::Object::getActions() const
{
    return this->_actions;
}
