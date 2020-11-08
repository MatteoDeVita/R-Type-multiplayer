/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** GameContainer
*/

#include <vector>
#include <iostream>
#include <sstream>

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
    this->_spawnChrono = std::chrono::high_resolution_clock::now();
}

GameContainer::GameContainer()
{
    factory_ns::loadTextures(&this->_gameEngine);
    // factory_ns::addAndCreateMonster(&this->_gameEngine, 2, gameEngine_ns::geometry_ns::Vector(500, 500));
}

GameContainer::~GameContainer()
{
}

void GameContainer::update_struct()
{
    
    std::ostringstream sstream;
    this->EnvServData.datas_send = "";
   
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
    int randms = (rand() % 3000) + 2000;
    std::chrono::time_point<std::chrono::high_resolution_clock> currentChrono = std::chrono::high_resolution_clock::now();
    double diff = std::chrono::duration<double, std::milli>(currentChrono - this->_spawnChrono).count();

    if (diff >= randms) {
        factory_ns::addAndCreateMonster(&this->_gameEngine, (rand() % 8) + 1, gameEngine_ns::geometry_ns::Vector(rand() % 1000, rand() % 1000));
        this->_spawnChrono = std::chrono::high_resolution_clock::now();
    }
    for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : this->_gameEngine.getObjects()) {
        pair.second->setPos(
            gameEngine_ns::geometry_ns::Vector(
                pair.second->getPos().x - 1,
                pair.second->getPos().y
            )
        );        
    }
}
