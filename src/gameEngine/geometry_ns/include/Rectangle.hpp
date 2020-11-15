/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Rectangle
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Vector.hpp"

namespace gameEngine_ns {
    namespace geometry_ns {
        class Rectangle {

            public:
                Vector origin;
                Vector size;
                /**
                 * @brief Construct a new Rectangle object
                 * 
                 */
                Rectangle();
                /**
                 * @brief Construct a new Rectangle object
                 * 
                 * @param origin 
                 * @param size 
                 */
                Rectangle(const Vector &origin, const Vector &size);
                /**
                 * @brief Construct a new Rectangle object
                 * 
                 * @param left 
                 * @param top 
                 * @param width 
                 * @param height 
                 */
                Rectangle(const float &left, const float &top, const float &width, const float &height);
                /**
                 * @brief Adds two rectangle
                 * 
                 * @param rectangle 
                 * @return Rectangle 
                 */
                Rectangle operator+(const Rectangle &rectangle) const;
                /**
                 * @brief Substract two rectangles
                 * 
                 * @param rectangle 
                 * @return Rectangle 
                 */
                Rectangle operator-(const Rectangle &rectangle) const;
                /**
                 * @brief Multiply two rectangles
                 * 
                 * @param rectangle 
                 * @return Rectangle 
                 */
                Rectangle operator*(const Rectangle &rectangle) const;
                /**
                 * @brief Divide two rectangles
                 * 
                 * @param rectangle 
                 * @return Rectangle 
                 */
                Rectangle operator/(const Rectangle &rectangle) const;
                /**
                 * @brief Check rectangle equality
                 * 
                 * @param rectangle 
                 * @return true if both rectangles are equal
                 * @return false if rectangles are not equal
                 */
                bool operator==(const Rectangle &rectangle) const;
                /**
                 * @brief Compute the rectangle area
                 * 
                 * @return float area
                 */
                float area() const;
                /**
                 * @brief COmpute the rectangle permiter
                 * 
                 * @return float perimeter
                 */
                float perimeter() const;
                /**
                 * @brief Convert to sf::IntRect
                 * 
                 * @return sf::IntRect 
                 */
                sf::IntRect toSfIntRect() const;
        };
    }
}

