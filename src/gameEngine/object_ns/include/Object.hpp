/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Object
*/

#pragma once

#include "Sprite.hpp"
#include "Vector.hpp"
#include "Sprite.hpp"

namespace gameEngine_ns {
    namespace object_ns {
        class Object {
            private:
                gameEngine_ns::object_ns::Sprite *_sprite;
                gameEngine_ns::geometry_ns::Vector _position;
            public:
                Object(gameEngine_ns::object_ns::Sprite *sprite, const gameEngine_ns::geometry_ns::Vector &position = gameEngine_ns::geometry_ns::Vector());
                ~Object();
        }; 
    }
}
