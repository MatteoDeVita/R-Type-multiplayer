/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** GameContainer
*/

#pragma once

#include "ClientServerSide.hpp"
#include "environment.hpp"
#include "GameEngine.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>

class GameContainer {
    public:
        GameContainer();
        ~GameContainer();
        void update_struct();
        void push_newclient(boost::asio::ip::udp::endpoint);
        std::vector<ClientServerSide> _clients;
        environment_t EnvServData;
        gameEngine_ns::GameEngine _gameEngine;
        void updateGameObjects();
    protected:
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> _spawnChrono;
        std::chrono::time_point<std::chrono::high_resolution_clock> _mooveChrono;
};
