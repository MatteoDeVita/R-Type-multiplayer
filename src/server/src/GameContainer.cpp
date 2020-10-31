/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** GameContainer
*/

#include "GameContainer.hpp"

void GameContainer::push_newclient(boost::asio::ip::udp::endpoint endpointer)
{
    ClientServerSide newest;

    newest._endpoint = endpointer;
    this->_clients.push_back(newest);
}

GameContainer::GameContainer()
{

}

GameContainer::~GameContainer()
{
}

void GameContainer::update_struct()
{
    this->data_struct.c += 1;
}