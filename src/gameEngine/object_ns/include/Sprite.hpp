/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Sprite
*/

#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "Rectangle.hpp"
#include "Sprite.hpp"
#include "Vector.hpp"

namespace gameEngine_ns {
    namespace object_ns {
        class Sprite {
            private:
                sf::Texture *_texture;
                sf::Sprite *_sprite;
                std::vector<geometry_ns::Rectangle> _rectanglePositionsOnImage;
                float _delayMs;
                std::vector<geometry_ns::Rectangle>::iterator _textureRectIt;
                sf::Clock *_clock;
            public:
                /**
                 * @brief Update sprite
                 * 
                 */
                void update();
                /**
                 * @brief Get the corresponding SFML Sprite
                 * 
                 * @return sf::Sprite* 
                 */
                sf::Sprite *getSFMLSprite() const;
                /**
                 * @brief Construct a new Sprite object
                 * 
                 * @param texture 
                 * @param rectanglePositionsOnImage 
                 * @param delayMs 
                 */
                Sprite(sf::Texture *texture, const std::vector<geometry_ns::Rectangle> &rectanglePositionsOnImage, float delayMs = 10);
                /**
                 * @brief Moove the sprite
                 * 
                 * @param vector 
                 */
                void moove(const gameEngine_ns::geometry_ns::Vector &vector);
                /**
                 * @brief Destroy the Sprite object
                 * 
                 */
                ~Sprite();
        };
    }
}
