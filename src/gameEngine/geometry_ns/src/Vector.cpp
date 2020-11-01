/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Vector
*/

#include "Vector.hpp"

gameEngine_ns::geometry_ns::Vector::Vector(const float &x, const float &y)
{
    this->x = x;
    this->y = y;
}

gameEngine_ns::geometry_ns::Vector gameEngine_ns::geometry_ns::Vector::operator+(const Vector &vector)
{
    gameEngine_ns::geometry_ns::Vector newVector = gameEngine_ns::geometry_ns::Vector(this->x + vector.x, this->y + vector.y);
    return newVector;
}

gameEngine_ns::geometry_ns::Vector gameEngine_ns::geometry_ns::Vector::operator-(const Vector &vector)
{
    gameEngine_ns::geometry_ns::Vector newVector = gameEngine_ns::geometry_ns::Vector(this->x - vector.x, this->y - vector.y);
    return newVector;
}

gameEngine_ns::geometry_ns::Vector gameEngine_ns::geometry_ns::Vector::operator*(const Vector &vector)
{
    gameEngine_ns::geometry_ns::Vector newVector = gameEngine_ns::geometry_ns::Vector(this->x * vector.x, this->y * vector.y);
    return newVector;
}

gameEngine_ns::geometry_ns::Vector gameEngine_ns::geometry_ns::Vector::operator/(const Vector &vector)
{
    gameEngine_ns::geometry_ns::Vector newVector = gameEngine_ns::geometry_ns::Vector(this->x / vector.x, this->y / vector.y);
    return newVector;
}

bool gameEngine_ns::geometry_ns::Vector::operator==(const Vector &vector)
{
    return this->x == vector.x && this->y == vector.y;
}
