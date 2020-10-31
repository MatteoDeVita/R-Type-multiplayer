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

void UDP_Server::do_send()
{
    std::ostringstream archive_stream;
    boost::archive::text_oarchive archive(archive_stream);  
    
    for (unsigned int i = 0; i < this->_gameContainers.size(); i++) {
        for (unsigned int y = 0; y <  this->_gameContainers.at(i)._clients.size(); y++) {
            if(this->_client_endpoint.address() == this->_gameContainers.at(i)._clients.at(y)._endpoint.address()) {
                this->_gameContainers.at(i).update_struct();//test
                archive << this->_gameContainers.at(i).data_struct;
                
            }
        }
    }


    this->_socket.async_send_to(
    boost::asio::buffer(archive_stream.str()), _client_endpoint,
    [this](boost::system::error_code /*ec*/, std::size_t /*bytes_sent*/)
    {
        std::cout << YELLOW << "[DATA SENDED]" << RESET << " -> DEST=" << _client_endpoint << std::endl;//DEBUG
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
    std::istringstream archive_stream(serielise_string);
    boost::archive::text_iarchive archive(archive_stream);
    for (unsigned int i = 0; i < this->_gameContainers.size(); i++) {
        for (unsigned int y = 0; y < this->_gameContainers.at(i)._clients.size(); y++) {
            if(client_endpoint.address() == this->_gameContainers.at(i)._clients.at(y)._endpoint.address()) {
                this->_gameContainers.at(i)._clients.at(y)._endpoint = client_endpoint;
                archive >> this->_gameContainers.at(i).data_struct;


                std::cout << GREEN << "[DATA RECEIVED AND UPDATED]" << RESET << " -> USER=" << this->_gameContainers.at(i)._clients.at(y).ton_num << " CONTAINER=" << this->_gameContainers.at(i)._clients.at(y).ton_num / 4  << " FROM=" << client_endpoint << std::endl;//DEBUG


             //   std::cout << this->_gameContainers.at(i).data_struct.a << std::endl;//test
             //   std::cout << this->_gameContainers.at(i).data_struct.b << std::endl;//test
             //   std::cout << this->_gameContainers.at(i).data_struct.c << std::endl;//test
                return;
            }
        }
    }
    ClientServerSide new_client;
    new_client._endpoint = client_endpoint;
    new_client.ton_num = this->NbofClientassign;
    if (this->NbofClientassign % 4 == 0) {
           std::cout << RED << "[NEW CONTAINER]" << RESET << " -> "<< "ID="<<NbofClientassign / 4 << std::endl;//DEBUG
           std::cout << BLUE << "[USER ADDED]" << RESET << " -> USER=" << this->NbofClientassign << " CONTAINER=" << NbofClientassign / 4 << " FROM=" << client_endpoint << std::endl;//DEBUG
           GameContainer newest;
           newest._clients.push_back(new_client);
           archive >> newest.data_struct;
           this->_gameContainers.push_back(newest);
       }
       else {
           std::cout << BLUE << "[USER ADDED]" << RESET << " -> USER=" << this->NbofClientassign << " CONTAINER=" << NbofClientassign / 4 << " FROM=" << client_endpoint << std::endl;//DEBUG
           archive >> this->_gameContainers.at(_gameContainers.size() - 1).data_struct;
           this->_gameContainers.at(_gameContainers.size() - 1)._clients.push_back(new_client);
       }
       this->NbofClientassign++;
      // std::cout << this->_gameContainers.at(_gameContainers.size() - 1).data_struct.a << std::endl;//test
      // std::cout << this->_gameContainers.at(_gameContainers.size() - 1).data_struct.b << std::endl;//test
      // std::cout << this->_gameContainers.at(_gameContainers.size() - 1).data_struct.c << std::endl;//test
}