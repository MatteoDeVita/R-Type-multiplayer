/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Moove
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Action.hpp"
#include "Object.hpp"
#include "Vector.hpp"

namespace gameEngine_ns {
    namespace action_ns {
        class Moove : public Action {
            public:
                Moove(
                    gameEngine_ns::object_ns::Object *relatedObject,
                    const gameEngine_ns::geometry_ns::Vector &vector = gameEngine_ns::geometry_ns::Vector(1, 1),
                    const float &speed = 50
                );
                Moove();
                ~Moove();
                void setVector(const gameEngine_ns::geometry_ns::Vector &vector = gameEngine_ns::geometry_ns::Vector(1, 1));
                void enable();
                void disable();
            private:
                gameEngine_ns::geometry_ns::Vector _vector;
                sf::Clock *_clock;
                float _speed;
        };
    }
}
