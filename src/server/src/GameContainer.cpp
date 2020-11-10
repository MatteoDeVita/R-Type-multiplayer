/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** GameContainer
*/

#include <vector>
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdlib.h>

#include "GameContainer.hpp"
#include "Sprite.hpp"
#include "Object.hpp"
#include "Error.hpp"
#include "factory.hpp"

void GameContainer::push_newclient(boost::asio::ip::udp::endpoint endpointer)
{
    ClientServerSide newest;

    newest._endpoint = endpointer;
    this->_clients.push_back(newest);
    factory_ns::addAndCreatePlayer(&this->_gameEngine, this->_clients.size(), gameEngine_ns::geometry_ns::Vector(0, rand() % 850));
    this->_spawnChrono = std::chrono::high_resolution_clock::now();
    this->_mooveChrono = std::chrono::high_resolution_clock::now();
}

GameContainer::GameContainer()
{
    srand(time(NULL));
    factory_ns::loadMonsterTextures(&this->_gameEngine);
    factory_ns::loadPlayerTextures(&this->_gameEngine);
}

GameContainer::~GameContainer()
{
}

void GameContainer::update_struct()
{
    
    std::ostringstream sstream;
    this->EnvServData.datas_send = "";

    std::cout << this->EnvServData.datas_receive << std::endl;

    this->updateGameObjects();
    for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : this->_gameEngine.getObjects()) {
        sstream << pair.second->getPos().x;
        this->EnvServData.datas_send += std::string(sstream.str()) + ' ';
        sstream.str("");
        sstream << pair.second->getPos().y;
        this->EnvServData.datas_send += std::string(sstream.str()) + ' ' + pair.first + '|';
        sstream.str("");
    }
}

void GameContainer::updateGameObjects()
{
    int spawnRand = (rand() % 2000) + 1000;
    std::chrono::time_point<std::chrono::high_resolution_clock> currentSpawnChrono = std::chrono::high_resolution_clock::now();
    double spawnDiff = std::chrono::duration<double, std::milli>(currentSpawnChrono - this->_spawnChrono).count();

    if (spawnDiff >= spawnRand) {
        factory_ns::addAndCreateMonster(&this->_gameEngine, (rand() % 8) + 1, gameEngine_ns::geometry_ns::Vector(1700, rand() % 850));
        this->_spawnChrono = std::chrono::high_resolution_clock::now();
    }

    for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : this->_gameEngine.getObjects()) {
        if (pair.first.substr(0, 7) == "monster") {
            pair.second->autoUpdatePos();
            if (pair.second->getPos().x <= -50)
                this->_gameEngine.removeObject(pair.first);
        }
    }
}
