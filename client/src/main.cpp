/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include "Network.hpp"
#include <thread>

using boost::asio::ip::udp;

void StartMessage(int argc) {
  if (argc != 3)
    {
      std::cerr << "Usage: client <host> <message>" << std::endl;
      exit(84);
    }
}

int main(int argc, char* argv[])
{
    StartMessage(argc);
    Network *network;
    udp::resolver resolver(network->io);//creation d'un object resolver pour trouver le endpoint(le host distant)
    network->serverEndpoint = *resolver.resolve(udp::v4(), argv[1], "3000").begin(); //recuperation du endpoint
    udp::socket socket(network->io); //creation d'un socket UDP
    socket.open(udp::v4()); // ouverture du socket

    std::string message = argv[2];//message

    network->_thread = new std::thread(&Network::send, network, message, &socket); //thread send
    network->_thread->detach();

    network->_thread = new std::thread(&Network::receive, network, &socket); //thread receive
    network->_thread->detach();

    while (1) { }
    return 0;
}