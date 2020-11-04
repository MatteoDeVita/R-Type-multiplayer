/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** Network
*/

#include "Network.hpp"
#include "Debug_color.hpp"

void Threaded_Send(Network *ClassAccess)//envoie les actions du client -> A FAIRE : regler le tickRate 
{
    while(1) {
        boost::asio::steady_timer timer1_(*ClassAccess->_io, boost::asio::chrono::milliseconds(ClassAccess->ms_speed));//1000ms
        timer1_.wait();

        std::ostringstream archive_stream;
        boost::archive::text_oarchive archive(archive_stream);
        archive << ClassAccess->EnvClientData;
        ClassAccess->_socket->send_to(boost::asio::buffer(archive_stream.str()),ClassAccess->_server_endpoint);//envoie de la struct au serv
        std::cout << BOLDYELLOW << "[DATA SENT]" << RESET << " -> DEST=" << ClassAccess->_server_endpoint << std::endl;//DEBUG
    }
}

void Threaded_Receive(Network *ClassAccess) //recoit et met a jour les datas du client
{
    std::string str;
    str.resize(1024);

    while(1) {
        udp::endpoint client_endpoint;
        // size_t len = 

        ClassAccess->_socket->receive_from(boost::asio::buffer(str), client_endpoint);

        std::istringstream archive_stream(str);
        boost::archive::text_iarchive archive(archive_stream);
        archive >> ClassAccess->EnvClientData;


        std::cout << BOLDGREEN << "[DATA RECEIVED AND UPDATED]" << RESET <<  " -> FROM=" << ClassAccess->_server_endpoint << std::endl;//DEBUG

        std::cout << ClassAccess->EnvClientData.sprite_ids.size() << std::endl;
        std::cout << GREEN << "contenu de pos_y : " << ClassAccess->EnvClientData.pos_y.at(0) << std::endl; //TEST
        std::cout << "contenu de pos_x : " << ClassAccess->EnvClientData.pos_x.at(0) << std::endl; //TEST
        std::cout << "contenu de sprite_ids : " << ClassAccess->EnvClientData.sprite_ids.at(0) << RESET <<std::endl; //TEST
    }
}

Network::Network(char **argv) // //_resolver(_io), _io() _resolver(io) _socker(io)
{
    this->_io = new boost::asio::io_context;
    this->_resolver = new udp::resolver(*this->_io);
    this->_socket = new udp::socket(*this->_io);
    this->ms_speed = atoi(argv[2]);

    this->EnvClientData.pos_x.push_back(0);//test
    this->EnvClientData.pos_y.push_back(0);//test
    this->EnvClientData.sprite_ids.push_back("");//test

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
}
