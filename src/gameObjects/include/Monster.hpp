/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Monster
*/

#pragma once

#include "Sprite.hpp"
#include "Object.hpp"
#include "Vector.hpp"

class Monster : public gameEngine_ns::object_ns::Object {
    public:
        Monster(gameEngine_ns::object_ns::Sprite *sprite, const gameEngine_ns::geometry_ns::Vector &position = gameEngine_ns::geometry_ns::Vector());
        ~Monster();
};
