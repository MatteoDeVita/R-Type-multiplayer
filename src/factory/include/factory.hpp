/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** factory
*/

#pragma once

#include <vector>
#include <string>

#include "GameEngine.hpp"
#include "Rectangle.hpp"
#include "IObject.hpp"

namespace factory_ns {
    void loadMonsterTextures(gameEngine_ns::GameEngine *gameEngine);
    void loadPlayerTextures(gameEngine_ns::GameEngine *gameEngine);
    void loadEnvironment(gameEngine_ns::GameEngine *gameEngine);
    void loadMusic(gameEngine_ns::GameEngine *gameEngine);
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster1Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster2Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster3Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster4Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster5Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster6Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster7Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonster8Vec();
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getPlayerVec();
    void updateObjectsFromNetworkData(gameEngine_ns::GameEngine *gameEngine, const std::string &data);
    void addAndCreateMonster(gameEngine_ns::GameEngine *gameEngine, const int &monsterNb, const gameEngine_ns::geometry_ns::Vector &position);
    void addAndCreatePlayer(gameEngine_ns::GameEngine *gameEngine, const int &playerNb, const gameEngine_ns::geometry_ns::Vector &position);    
    std::vector<gameEngine_ns::geometry_ns::Rectangle> getMonsterVec(const int &monsterNb);    
    std::vector<gameEngine_ns::object_ns::IObject *> getPlayers(const gameEngine_ns::GameEngine &gameEngine);
}
