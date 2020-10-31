/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** Server
*/

#include "Server.hpp"

UDP_Server::UDP_Server(boost::asio::io_context &io) : _socket(io, udp::endpoint(udp::v4(), 3000))
{
    this->NbofClientassign = 0;
    do_receive();
}

UDP_Server::~UDP_Server()
{
}

void UDP_Server::do_send(std::size_t length)
{
    for (unsigned int i = 0; i < this->_gameContainers.size(); i++) {
        for (unsigned int y = 0; y <  this->_gameContainers.at(i)._clients.size(); y++) {
            // std::cout << this->_gameContainers.at(i)._clients.at(y)._endpoint.address() << std::endl;
            if(this->_client_endpoint.address() == this->_gameContainers.at(i)._clients.at(y)._endpoint.address()) {
                std::cout << "testiboules" << std::endl;
                std::string message = std::to_string(this->_gameContainers.at(i)._clients.at(y).ton_num);;//test = std::to_string(this->_gameContainers.at(i)._clients.at(y).ton_num); // std::styring
                strcpy(_data, message.c_str());
                
            }
        }
    }
    GameContainer::sample testStruct;
    testStruct.a = 'x';
    testStruct.b = 'e';
    testStruct.c = 3;

    std::ostringstream archive_stream;
    boost::archive::text_oarchive archive(archive_stream);  
    archive << testStruct;

    this->_socket.async_send_to(
    boost::asio::buffer(archive_stream.str()), _client_endpoint,
    [this](boost::system::error_code /*ec*/, std::size_t /*bytes_sent*/)
    {
      do_receive();
    });
}

void UDP_Server::do_receive()
{
    this->_socket.async_receive_from(boost::asio::buffer(_data, max_length), _client_endpoint,[this](boost::system::error_code ec, std::size_t bytes_recvd){
        if (!ec && bytes_recvd > 0) {
            std::cout << this->get_user_is_know(_client_endpoint) << std::endl;
            do_send(bytes_recvd);
        }
        else {
            do_receive();
        }
    });
}

std::string UDP_Server::get_user_is_know(udp::endpoint client_endpoint)
{
    for (unsigned int i = 0; i < this->_gameContainers.size(); i++) {
        for (unsigned int y = 0; y < this->_gameContainers.at(i)._clients.size(); y++) {
            if(client_endpoint.address() == this->_gameContainers.at(i)._clients.at(y)._endpoint.address()) {
                this->_gameContainers.at(i)._clients.at(y)._endpoint = client_endpoint;
                return "il existe deja connard";
            }
        }
    }
    ClientServerSide new_client;
    new_client._endpoint = client_endpoint;
    new_client.ton_num = NbofClientassign;
    if (this->NbofClientassign % 4 == 0) {
           GameContainer newest;
           newest._clients.push_back(new_client);
           this->_gameContainers.push_back(newest);
       }
       else {
           this->_gameContainers.at(_gameContainers.size() - 1)._clients.push_back(new_client);
       }
       this->NbofClientassign++;
       return "Ce noob d'alexis est toujours pas platine";
}