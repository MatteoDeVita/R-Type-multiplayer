/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Vector
*/

#include "Vector.hpp"

gameEngine_ns::geometry_ns::Vector::Vector(const float &x, const float &y)
{
    this->_x = x;
    this->_y = y;
}

gameEngine_ns::geometry_ns::Vector &gameEngine_ns::geometry_ns::Vector::get() const
{
    Vector vector = gameEngine_ns::geometry_ns::Vector(this->_x, this->_y);
    return vector;
}

void gameEngine_ns::geometry_ns::Vector::setX(const float &x)
{
    this->_x = x;
}

void gameEngine_ns::geometry_ns::Vector::setY(const float &y)
{
    this->_y = y;
}

void gameEngine_ns::geometry_ns::Vector::set(const float &x, const float &y)
{
    this->_x = x;
    this->_y = y;
}

void gameEngine_ns::geometry_ns::Vector::set(const gameEngine_ns::geometry_ns::Vector &vector)
{
    
}
