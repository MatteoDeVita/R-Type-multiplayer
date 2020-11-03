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
            public:               
                Sprite(const std::string &textureId, const std::vector<geometry_ns::Rectangle> &rectanglePositionsOnImage);
                ~Sprite();
        };
    }
}
