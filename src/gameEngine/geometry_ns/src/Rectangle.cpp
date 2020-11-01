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

gameEngine_ns::geometry_ns::Rectangle::~Rectangle()
{

}
