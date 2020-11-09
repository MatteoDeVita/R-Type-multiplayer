/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Player
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Object.hpp"
#include "Sprite.hpp"
#include "Vector.hpp"

class Player : public  gameEngine_ns::object_ns::Object {
    public:
        Player(gameEngine_ns::object_ns::Sprite *sprite, const gameEngine_ns::geometry_ns::Vector &position = gameEngine_ns::geometry_ns::Vector());
        Player();
        ~Player();    
    private:
        sf::Clock *_mooveClock;
};
