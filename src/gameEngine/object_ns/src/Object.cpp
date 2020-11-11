/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Object
*/

#include <iostream>

#include "Object.hpp"
#include "Error.hpp"

gameEngine_ns::object_ns::Object::Object()
{
    this->_sprite = nullptr;
    this->_position = gameEngine_ns::geometry_ns::Vector();
}

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
    this->_position = vector;    
    this->_sprite->getSFMLSprite()->setPosition(vector.toSfVector2f());
}

gameEngine_ns::object_ns::Object::~Object()
{
    if (this->_sprite != nullptr)
        delete this->_sprite;
}

void gameEngine_ns::object_ns::Object::moove(const gameEngine_ns::geometry_ns::Vector &vector)
{
    this->_position.x += vector.x;
    this->_position.y += vector.y;
    this->_sprite->moove(vector);
}

void gameEngine_ns::object_ns::Object::autoUpdatePos()
{
    
}

void gameEngine_ns::object_ns::Object::autoMoove()
{
    
}

bool gameEngine_ns::object_ns::Object::isFromMonster() const
{

}

void gameEngine_ns::object_ns::Object::autoMoove(const gameEngine_ns::geometry_ns::Vector &vector)
{

}

void gameEngine_ns::object_ns::Object::setSpeed(const unsigned int &speed)
{

}
