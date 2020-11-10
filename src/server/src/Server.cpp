/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** Server
*/

#include "Server.hpp"
#include "factory.hpp"

UDP_Server::UDP_Server() : _socket(_io, udp::endpoint(udp::v4(), 3000))
{
    std::cout << BOLDMAGENTA << "[SERVER IS RUNNING]" << RESET << std::endl;//DEBUG

    this->NbofClientassign = 0;
    do_receive();
}

UDP_Server::~UDP_Server()
{
}

void UDP_Server::do_send()
{
    // std::ostringstream archive_stream;
    // boost::archive::text_oarchive archive(archive_stream);  
    std::string test;
    for (unsigned int i = 0; i < this->_gameContainers.size(); i++) {
        for (unsigned int y = 0; y <  this->_gameContainers.at(i)._clients.size(); y++) {
            if(this->_client_endpoint.address() == this->_gameContainers.at(i)._clients.at(y)._endpoint.address()) {
                this->_gameContainers.at(i).update_struct();//test
                /*archive <<*/ test =  this->_gameContainers.at(i).EnvServData.datas_send;
            //    std::cout << "DATAS CONTENT FIRST BOUCLE DO SEND() : " << this->_gameContainers.at(i).EnvServData.datas << std::endl;
            }
        }
    }
   // std::cout << "TEST CONTENT POST BOUCLE SEND : " << test << std::endl;
    this->_socket.async_send_to(
    boost::asio::buffer(/*archive_stream.str()*/ test), _client_endpoint,
    [this](boost::system::error_code /*ec*/, std::size_t /*bytes_sent*/)
    {
        std::cout << BOLDYELLOW << "[DATA SENT]" << RESET << " -> DEST=" << _client_endpoint << std::endl;//DEBUG
        do_receive();
    });
}

void UDP_Server::do_receive()
{    
    this->_socket.async_receive_from(boost::asio::buffer(_data, max_length), _client_endpoint,[this](boost::system::error_code ec, std::size_t bytes_recvd){
        if (!ec && bytes_recvd > 0) {
            this->set_user_info(_client_endpoint, _data );
            do_send();
        }
        else {
            do_receive();
        }
    });
}

void UDP_Server::set_user_info(udp::endpoint client_endpoint, std::string serielise_string)
{
    /*std::istringstream archive_stream(serielise_string);
    boost::archive::text_iarchive archive(archive_stream);*/
    for (unsigned int i = 0; i < this->_gameContainers.size(); i++) {
        for (unsigned int y = 0; y < this->_gameContainers.at(i)._clients.size(); y++) {
            if(client_endpoint.address() == this->_gameContainers.at(i)._clients.at(y)._endpoint.address()) {
                this->_gameContainers.at(i)._clients.at(y)._endpoint = client_endpoint;
                this->_gameContainers.at(i).EnvServData.datas_receive.clear();
                this->_gameContainers.at(i).EnvServData.datas_receive = serielise_string;

                std::cout << BOLDGREEN << "[DATA RECEIVED AND UPDATED]" << RESET << " -> USER=" << this->_gameContainers.at(i)._clients.at(y).ton_num << " CONTAINER=" << this->_gameContainers.at(i)._clients.at(y).ton_num / 4  << " FROM=" << client_endpoint << std::endl;//DEBUG
                std::cout << BOLDBLUE << "CONTENT : " << this->_gameContainers.at(i).EnvServData.datas_receive << RESET << std::endl; //TEST
            
                return;
            }
        }
    }
    ClientServerSide new_client;
    new_client._endpoint = client_endpoint;
    new_client.ton_num = this->NbofClientassign;
    if (this->NbofClientassign % 4 == 0) {
            std::cout << BOLDRED << "[NEW CONTAINER]" << RESET << " -> "<< "ID="<<NbofClientassign / 4 << std::endl;//DEBUG
            std::cout << BOLDBLUE << "[USER ADDED]" << RESET << " -> USER=" << this->NbofClientassign << " CONTAINER=" << NbofClientassign / 4 << " FROM=" << client_endpoint << std::endl;//DEBUG
            GameContainer newest;
            newest._clients.push_back(new_client);
            newest.EnvServData.datas_receive = serielise_string;
            this->_gameContainers.push_back(newest);
            factory_ns::addAndCreatePlayer(
                &this->_gameContainers.back()._gameEngine,
                this->_gameContainers.back()._clients.size(),
                gameEngine_ns::geometry_ns::Vector(0, rand() % 850)
            );
       }
       else {
           std::cout << BOLDBLUE << "[USER ADDED]" << RESET << " -> USER=" << this->NbofClientassign << " CONTAINER=" << NbofClientassign / 4 << " FROM=" << client_endpoint << std::endl;//DEBUG
           this->_gameContainers.at(_gameContainers.size() - 1).EnvServData.datas_receive = serielise_string;
           this->_gameContainers.at(_gameContainers.size() - 1)._clients.push_back(new_client);
           factory_ns::addAndCreatePlayer(
                &this->_gameContainers.back()._gameEngine,
                this->_gameContainers.back()._clients.size(),
                gameEngine_ns::geometry_ns::Vector(0, rand() % 850)
            );
       }
       this->NbofClientassign++;
      // std::cout << this->_gameContainers.at(_gameContainers.size() - 1).data_struct.a << std::endl;//test
      // std::cout << this->_gameContainers.at(_gameContainers.size() - 1).data_struct.b << std::endl;//test
      // std::cout << this->_gameContainers.at(_gameContainers.size() - 1).data_struct.c << std::endl;//test
}