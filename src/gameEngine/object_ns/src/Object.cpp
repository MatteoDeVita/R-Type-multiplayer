/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Object
*/

#include "Object.hpp"

gameEngine_ns::object_ns::Object::Object(gameEngine_ns::object_ns::Sprite *sprite, const gameEngine_ns::geometry_ns::Vector &position)
{
    this->_sprite = sprite;
    this->_position = position;
}

gameEngine_ns::object_ns::Sprite * gameEngine_ns::object_ns::Object::getSprite() const
{
    return this->_sprite;
}
