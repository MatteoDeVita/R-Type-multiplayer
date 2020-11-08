/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** IObject
*/

#pragma once

#include <map>

#include "Sprite.hpp"

namespace gameEngine_ns {
    namespace object_ns {
        class IObject {
            public:
                IObject();
                ~IObject();
                virtual gameEngine_ns::geometry_ns::Vector getPos() const = 0;
                virtual void setPos(const gameEngine_ns::geometry_ns::Vector &vector) = 0;
                virtual void moove(const gameEngine_ns::geometry_ns::Vector &vector) = 0;
                virtual gameEngine_ns::object_ns::Sprite *getSprite() const = 0;
            protected:
                gameEngine_ns::object_ns::Sprite *_sprite;
                gameEngine_ns::geometry_ns::Vector _position;
                
        };
    }
}

