/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Rectangle
*/

#pragma once

#include "Vector.hpp"

namespace gameEngine_ns {
    namespace geometry_ns {
        class Rectangle {

            public:
                Vector origin;
                Vector size;
                Rectangle();
                Rectangle(const Vector &origin, const Vector &size);
                Rectangle(const float &left, const float &top, const float &width, const float &height);
                Rectangle operator+(const Rectangle &rectangle) const;
                Rectangle operator-(const Rectangle &rectangle) const;
                Rectangle operator*(const Rectangle &rectangle) const;
                Rectangle operator/(const Rectangle &rectangle) const;
                bool operator==(const Rectangle &rectangle) const;
                float area() const;
                float perimeter() const;
        };
    }
}

