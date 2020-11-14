/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Explosion
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Object.hpp"

class Explosion : public gameEngine_ns::object_ns::Object {
    public:
        Explosion();
        ~Explosion();
        Explosion(
            gameEngine_ns::object_ns::Sprite *sprite,
            const gameEngine_ns::geometry_ns::Vector &position = gameEngine_ns::geometry_ns::Vector()
        );        
        sf::Clock *activeClock;
    private:
        bool _isActive;

};
