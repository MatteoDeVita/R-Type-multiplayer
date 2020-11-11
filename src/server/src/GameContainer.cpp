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
    ClientServerSide *newest = new ClientServerSide;

    newest->_endpoint = endpointer;
    this->_clients.push_back(newest);
    factory_ns::addAndCreatePlayer(this->_gameEngine, this->_clients.size(), gameEngine_ns::geometry_ns::Vector(0, rand() % 850));
    this->_spawnChrono = std::chrono::high_resolution_clock::now();
    this->_mooveChrono = std::chrono::high_resolution_clock::now();
    this->_monsterShootChrono = std::chrono::high_resolution_clock::now();
}

GameContainer::GameContainer()
{
    this->_gameEngine = new gameEngine_ns::GameEngine;

    srand(time(NULL));
    factory_ns::loadMonsterTextures(this->_gameEngine);
    factory_ns::loadPlayerTextures(this->_gameEngine);
    factory_ns::loadLasersTextures(this->_gameEngine);
    factory_ns::loadLaserObjects(this->_gameEngine, true);
    factory_ns::loadLaserObjects(this->_gameEngine, false);
    this->_laserSpawnginClock = new sf::Clock;
    this->_laserSpawnginClock->restart();
}

GameContainer::~GameContainer()
{
    if (this->_laserSpawnginClock != nullptr)
        delete this->_laserSpawnginClock;
    if (this->_gameEngine != nullptr)        
        delete this->_gameEngine;
}

void GameContainer::update_struct(const int &playerNb)
{
    
    std::ostringstream sstream;
    this->EnvServData.datas_send = "";

    this->updateGameObjects(playerNb);
    for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : this->_gameEngine->getObjects()) {
        if (pair.second != nullptr) {
            sstream << pair.second->getPos().x;
            this->EnvServData.datas_send += std::string(sstream.str()) + ' ';
            sstream.str("");
            sstream << pair.second->getPos().y;
            this->EnvServData.datas_send += std::string(sstream.str()) + ' ' + pair.first + '|';
            sstream.str("");
        }
    }
    // std::cout << "DATA SEND = " << this->EnvServData.datas_send << "[END]" << std::endl;
}

void GameContainer::_moovePlayer(const int &playerNb)
{
    const std::string &direction = this->EnvServData.datas_receive.substr(6, 8);
    gameEngine_ns::object_ns::IObject *player = factory_ns::getPlayers((*this->_gameEngine)).at(playerNb);
    
    if (direction == "up" && player->getPos().y > 5)
        player->moove(gameEngine_ns::geometry_ns::Vector(0, -5));
    if (direction == "down" && player->getPos().y < 895)
        player->moove(gameEngine_ns::geometry_ns::Vector(0, 5));
    if (direction == "right" && player->getPos().x < 1595)
        player->moove(gameEngine_ns::geometry_ns::Vector(5, 0));
    if (direction == "left" && player->getPos().x > 5)
        player->moove(gameEngine_ns::geometry_ns::Vector(-5, 0));

}

void GameContainer::_shootPlayer(const int &playerNb)
{
    gameEngine_ns::object_ns::IObject *player = factory_ns::getPlayers((*this->_gameEngine)).at(playerNb);
    std::vector<gameEngine_ns::object_ns::IObject *> validLasers = factory_ns::getValidLasers((*this->_gameEngine), true);

    if (validLasers.size() == 0)   
        return;
    gameEngine_ns::object_ns::IObject *laser = validLasers.at(rand() % validLasers.size());
    laser->setPos(player->getPos());
}


void GameContainer::updateGameObjects(const int &playerNb)
{
    int spawnRand = (rand() % 2000) + 1000;
    std::chrono::time_point<std::chrono::high_resolution_clock> currentSpawnChrono = std::chrono::high_resolution_clock::now();
    double spawnDiff = std::chrono::duration<double, std::milli>(currentSpawnChrono - this->_spawnChrono).count();
    double shootDiff = std::chrono::duration<double, std::milli>(currentSpawnChrono - this->_monsterShootChrono).count();
    std::vector<gameEngine_ns::object_ns::IObject *> validLasers = factory_ns::getValidLasers((*this->_gameEngine), false);

    if (spawnDiff >= spawnRand) {
        factory_ns::addAndCreateMonster(this->_gameEngine, (rand() % 8) + 1, gameEngine_ns::geometry_ns::Vector(1700, rand() % 850));
        this->_spawnChrono = std::chrono::high_resolution_clock::now();
    }

    if (this->EnvServData.datas_receive.substr(0, 5) == "moove")  {
        this->_moovePlayer(playerNb);
    }
    else if (this->_laserSpawnginClock->getElapsedTime().asMilliseconds() >= 1000 && this->EnvServData.datas_receive.substr(0, 5) == "shoot") {        
        this->_shootPlayer(playerNb);
        this->_laserSpawnginClock->restart();
    }
    for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : this->_gameEngine->getObjects()) {
        // std::cout << pair.first << std::endl;
        if (pair.first.substr(0, 7) == "monster") {
            pair.second->autoUpdatePos();
            if (shootDiff >= 20 && validLasers.size() > 0 && pair.second->getPos().x > 30 && rand() % 20 == 5) {
                validLasers.at(rand() % validLasers.size())->setPos(pair.second->getPos());
            }
        }
        if (pair.first.substr(0, 5) == "laser") {
            if (pair.first.substr(7, 6) == "player") {
                if (pair.second->getPos().x > 0) {
                    if (pair.second->getPos().x >= 1700)
                        pair.second->setPos(gameEngine_ns::geometry_ns::Vector(-100, 0));
                    else
                        pair.second->autoMoove();
                }
            }
            else if (pair.first.substr(7, 6) == "monste") {
                if (pair.second->getPos().x > 0) {
                    // if (pair.second->isFromMonster() && pair.second->getPos().x <= -50) {
                    //     pair.second->setPos(gameEngine_ns::geometry_ns::Vector(-100, 0));
                    // }
                    if (shootDiff >= 20) {
                        pair.second->autoMoove();
                        this->_monsterShootChrono = std::chrono::high_resolution_clock::now();
                    }
                }
            }
        }
    }
}

// précharger 100 lasers et les mettres de côtés, puis simplement changer leur posisitions quand ils doivent être utiliés
// ranger l'object quand plus utlisié (= quand atteint x > 1700)