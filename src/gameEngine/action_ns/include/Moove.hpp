/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Moove
*/

#pragma once

#include "Action.hpp"
#include "Object.hpp"
#include "Vector.hpp"

namespace gameEngine_ns {
    namespace action_ns {
        class Moove : public Action {
            public:
                Moove(gameEngine_ns::object_ns::Object *relatedObject, const gameEngine_ns::geometry_ns::Vector &speed);
                Moove();
                ~Moove();
            private:
                gameEngine_ns::geometry_ns::Vector _speed;
        };
    }
}
