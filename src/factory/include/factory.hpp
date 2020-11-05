/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** factory
*/

#pragma once

#include <vector>

#include "GameEngine.hpp"
#include "Rectangle.hpp"

namespace factory_ns {
    void loadTextures(gameEngine_ns::GameEngine *gameEngine);
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster1Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster2Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster3Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster4Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster5Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster6Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster7Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster8Vec();
    void updateObjectsFromNetworkData(gameEngine_ns::GameEngine *gameEngine, const std::string &data);
}
