/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Vector
*/

#pragma once

#include <SFML/Graphics.hpp>

namespace gameEngine_ns {
    namespace geometry_ns {
        class Vector {
            public:
                float x;
                float y;
                /**
                 * @brief Construct a new Vector object
                 * 
                 * @param x 
                 * @param y 
                 */
                Vector(const float &x = 0, const float &y = 0);
                /**
                 * @brief Add two vectors
                 * 
                 * @param vector 
                 * @return Vector 
                 */
                Vector operator+(const Vector &vector) const;
                /**
                 * @brief Substract two Vectors
                 * 
                 * @param vector 
                 * @return Vector 
                 */
                Vector operator-(const Vector &vector) const;
                /**
                 * @brief Multiply two Vectors
                 * 
                 * @param vector 
                 * @return Vector 
                 */
                Vector operator*(const Vector &vector) const;
                /**
                 * @brief Divide two Vectors
                 * 
                 * @param vector 
                 * @return Vector 
                 */
                Vector operator/(const Vector &vector) const;
                /**
                 * @brief Check vector equality
                 * 
                 * @param vector 
                 * @return true if both vectors are equal
                 * @return false if vectors are not equal
                 */
                bool operator==(const Vector &vector) const;
                /**
                 * @brief Convert to sf::vector2f
                 * 
                 * @return sf::Vector2f 
                 */
                sf::Vector2f toSfVector2f() const;
        };
    }
}
