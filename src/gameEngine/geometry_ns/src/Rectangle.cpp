/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

gameEngine_ns::geometry_ns::Rectangle::Rectangle()
{
    this->origin = Vector();
    this->size = Vector();
}

gameEngine_ns::geometry_ns::Rectangle::Rectangle(const Vector &origin = Vector(), const Vector &size = Vector())
{
    this->origin = origin;
    this->size = size;
}

gameEngine_ns::geometry_ns::Rectangle::Rectangle(const float &left = 0, const float &top = 0, const float &width = 0, const float &height = 0)
{
    this->origin = Vector(left, top);
    this->size = Vector(width, height);
}

gameEngine_ns::geometry_ns::Rectangle gameEngine_ns::geometry_ns::Rectangle::operator+(const Rectangle &rectangle) const
{
    return Rectangle(this->origin + rectangle.origin, this->size + rectangle.size);
}

gameEngine_ns::geometry_ns::Rectangle gameEngine_ns::geometry_ns::Rectangle::operator-(const Rectangle &rectangle) const
{
    return Rectangle(this->origin - rectangle.origin, this->size - rectangle.size);
}

gameEngine_ns::geometry_ns::Rectangle gameEngine_ns::geometry_ns::Rectangle::operator*(const Rectangle &rectangle) const
{
    return Rectangle(this->origin * rectangle.origin, this->size * rectangle.size);
}

gameEngine_ns::geometry_ns::Rectangle gameEngine_ns::geometry_ns::Rectangle::operator/(const Rectangle &rectangle) const
{
    return Rectangle(this->origin / rectangle.origin, this->size / rectangle.size);
}

bool gameEngine_ns::geometry_ns::Rectangle::operator==(const Rectangle &rectangle) const
{
    return this->origin == rectangle.origin && this->size == rectangle.size;
}

float gameEngine_ns::geometry_ns::Rectangle::area() const
{
    return this->size.x * this->size.y;
}

float gameEngine_ns::geometry_ns::Rectangle::perimeter() const
{
    return this->origin.x + this->origin.y + this->size.x + this->size.y;
}

sf::IntRect gameEngine_ns::geometry_ns::Rectangle::toSfIntRect() const 
{
    int left = (int) this->origin.x;
    int top = (int) this->origin.y;
    int width = (int) this->size.x;
    int height = (int) this->size.y;
    return sf::IntRect(left, top, width, height);
}