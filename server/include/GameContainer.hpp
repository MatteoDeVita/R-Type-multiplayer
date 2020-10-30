/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** GameContainer
*/

#pragma once

#include "ClientServerSide.hpp"

class GameContainer {
    public:
        GameContainer();
        ~GameContainer();
        void push_newclient(boost::asio::ip::udp::endpoint);
        std::vector<ClientServerSide> _clients;
    protected:
    private:
};
