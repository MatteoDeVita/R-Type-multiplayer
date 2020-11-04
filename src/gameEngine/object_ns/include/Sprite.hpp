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

namespace gameEngine_ns {
    namespace object_ns {
        class Sprite {
            private:
                sf::Texture *_texture;
                sf::Sprite *_sprite;
                std::vector<geometry_ns::Rectangle> _rectanglePositionsOnImage;
                float _delayMs;
                std::vector<geometry_ns::Rectangle>::iterator _textureRectIt;
            public:
                void update();
                sf::Sprite *getSFMLSprite() const;
                Sprite(sf::Texture *texture, const std::vector<geometry_ns::Rectangle> &rectanglePositionsOnImage, float delayMs = 10);
                ~Sprite();
        };
    }
}
