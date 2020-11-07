/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** Network
*/

#include <sstream>
#include <vector>
#include <string>

#include "Network.hpp"
#include "Debug_color.hpp"
#include "Object.hpp"
#include "Error.hpp"
#include "factory.hpp"

void Threaded_Send(Network *ClassAccess)//envoie les actions du client -> A FAIRE : regler le tickRate 
{
    while(1) {
        boost::asio::steady_timer timer1_(*ClassAccess->_io, boost::asio::chrono::milliseconds(ClassAccess->ms_speed));//1000ms
        timer1_.wait();

        ClassAccess->_socket->send_to(boost::asio::buffer(ClassAccess->EnvClientData->datas_send/*archive_stream.str()*/),ClassAccess->_server_endpoint);//envoie de la struct au serv
        std::cout << BOLDYELLOW << "[DATA SENT]" << RESET << " -> DEST=" << ClassAccess->_server_endpoint << std::endl;//DEBUG
    }
}

void Threaded_Receive(Network *ClassAccess) //recoit et met a jour les datas du client
{
    boost::array<char, 4096>_test_recv;
    while(1) {
        udp::endpoint client_endpoint;

        ClassAccess->_socket->receive_from(boost::asio::buffer(_test_recv), client_endpoint);

        ClassAccess->EnvClientData->datas_receive = _test_recv.data();

        std::cout << BOLDGREEN << "[DATA RECEIVED AND UPDATED]" << RESET <<  " -> FROM=" << ClassAccess->_server_endpoint << std::endl;//DEBUG
        std::cout << BOLDBLUE << "CONTENT : " << ClassAccess->EnvClientData->datas_receive <<  "\nSIZE :" << ClassAccess->EnvClientData->datas_receive.size() <<RESET << std::endl; //TEST
        if (ClassAccess->EnvClientData->datas_receive == "")
            return;
        factory_ns::updateObjectsFromNetworkData(ClassAccess->_gameEngine, ClassAccess->EnvClientData->datas_receive);
    }
        
}

Network::Network(char **argv, environment_t *EnvClientData, gameEngine_ns::GameEngine *gameEngine) // //_resolver(_io), _io() _resolver(io) _socker(io)
{
    this->_io = new boost::asio::io_context;
    this->_resolver = new udp::resolver(*this->_io);
    this->_socket = new udp::socket(*this->_io);
    this->ms_speed = atoi(argv[2]);
    this->EnvClientData = EnvClientData;
    this->EnvClientData->datas_send = "INIT";//test
    this->_gameEngine = gameEngine;
    
    this->_server_endpoint = *_resolver->resolve(udp::v4(), argv[1], "3000").begin(); //recuperation du endpoint
    this->_socket->open(udp::v4()); // ouverture du socket

    boost::thread t1(Threaded_Send, this);
    boost::thread t2(Threaded_Receive, this);
    t1.detach();
    t2.detach();
    t1.join();
    t2.join();
}

Network::~Network()
{
    delete this->_io;
    delete this->_resolver;
    delete this->_socket;
}
