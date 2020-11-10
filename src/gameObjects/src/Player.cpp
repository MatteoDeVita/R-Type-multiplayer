/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Player
*/

#include <iostream>

#include "Player.hpp"

Player::Player(
    gameEngine_ns::object_ns::Sprite *sprite,
    const gameEngine_ns::geometry_ns::Vector &position
) : gameEngine_ns::object_ns::Object(sprite, position)
{
    this->_mooveClock = new sf::Clock;
}

Player::Player()
{
    this->_mooveClock = new sf::Clock;
}

Player::~Player()
{
    if (this->_mooveClock != nullptr) {
        delete this->_mooveClock;
    }
}
