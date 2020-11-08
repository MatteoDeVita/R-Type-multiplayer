/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Monster
*/

#include "Monster.hpp"

Monster::Monster()
{

}

Monster::Monster(
    gameEngine_ns::object_ns::Sprite *sprite,
    const gameEngine_ns::geometry_ns::Vector &position
) : gameEngine_ns::object_ns::Object(sprite, position)
{

}

Monster::~Monster()
{

}
