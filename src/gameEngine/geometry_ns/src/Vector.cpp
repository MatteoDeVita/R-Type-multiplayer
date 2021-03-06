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

gameEngine_ns::geometry_ns::Vector gameEngine_ns::geometry_ns::Vector::operator+(const Vector &vector) const
{
    return Vector(this->x + vector.x, this->y + vector.y);
}

gameEngine_ns::geometry_ns::Vector gameEngine_ns::geometry_ns::Vector::operator-(const Vector &vector) const
{
    return Vector(this->x - vector.x, this->y - vector.y);

}

gameEngine_ns::geometry_ns::Vector gameEngine_ns::geometry_ns::Vector::operator*(const Vector &vector) const
{
    return Vector(this->x * vector.x, this->y * vector.y);

}

gameEngine_ns::geometry_ns::Vector gameEngine_ns::geometry_ns::Vector::operator/(const Vector &vector) const
{
    return Vector(this->x / vector.x, this->y / vector.y);

}

bool gameEngine_ns::geometry_ns::Vector::operator==(const Vector &vector) const
{
    return this->x == vector.x && this->y == vector.y;
}

sf::Vector2f gameEngine_ns::geometry_ns::Vector:: toSfVector2f() const
{
    return sf::Vector2f(
        this->x,
        this->y
    );
}