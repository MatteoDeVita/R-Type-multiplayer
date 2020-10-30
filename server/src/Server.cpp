/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** Server
*/

#include "Server.hpp"

UDP_Server::UDP_Server(boost::asio::io_context *io)
{
    this->NbofClientassign = 0;
    boost::thread t1(this->receive, &io);
    boost::thread t2(this->send, &io);

    t1.detach();
    t2.detach();
    t1.join();
    t2.join();
    std::cout << "[SERVER IS READY]" << std::endl;
}

UDP_Server::~UDP_Server()
{
}

std::string UDP_Server::get_user_is_know(udp::endpoint remote_endpoint)
{
    for (unsigned int i = 0; i < this->_gameContainers.size(); i++) {
        for (unsigned int y = 0; this->_gameContainers.at(i)._clients.size(); y++) {
            if(remote_endpoint.address() == this->_gameContainers.at(i)._clients.at(y)._endpoint.address()) {
                this->_gameContainers.at(i)._clients.at(y)._endpoint = remote_endpoint;
                return "il existait deja connard";
            }
        }
    }
    ClientServerSide new_client;
    new_client._endpoint = remote_endpoint;
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

void UDP_Server::receive(boost::asio::io_context *io)
{
    udp::resolver resolver(*io);
    udp::socket socket(*io, udp::endpoint(udp::v4(), 3000));

    udp::endpoint client_endpoint;
    while(1) {
        size_t len = socket.receive_from(boost::asio::buffer(this->_recv_buffer), client_endpoint);
        std::cout << get_user_is_know(client_endpoint) << std::endl;
    }
}

void UDP_Server::send(boost::asio::io_context *io)
{
    udp::socket socket(*io, udp::endpoint(udp::v4(), 3000));
    std::cout << "test" << std::endl;
    for (unsigned int i = 0; i < this->_gameContainers.size(); i++) {
        for (unsigned int y = 0; this->_gameContainers.at(i)._clients.size(); y++) {
            std::string message = std::to_string(this->_gameContainers.at(i)._clients.at(y).ton_num);
            std::cout << this->_gameContainers.at(i)._clients.at(y)._endpoint.address()<< std::endl;
            socket.send_to(boost::asio::buffer(message), this->_gameContainers.at(i)._clients.at(y)._endpoint);
        }
    }
}












/*
void udp_server::send_data_game_to_clients()
{
    for (unsigned int i = 0; i < this->_gameContainers.size(); i++) {
        for (unsigned int y = 0; this->_gameContainers.at(i)._clients.size(); y++) {
            boost::shared_ptr<std::string> message(new std::string(this->_gameContainers.at(i).message));
            socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_, boost::bind(&udp_server::handle_send, this, message,boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
        }
    }
}

bool udp_server::get_user_is_know()
{
    for (unsigned int i = 0; i < this->_gameContainers.size(); i++) {
        for (unsigned int y = 0; this->_gameContainers.at(i)._clients.size(); y++) {
            if(this->remote_endpoint_.address() == this->_gameContainers.at(i)._clients.at(y)._endpoint.address())
                return true;
        }²
    }
    return false;
}

void udp_server::game_container_load_balancer()
{
    if (get_user_is_know() == false) {
        if (this->NbofClientassign % 1 == 0) {
            GameContainer newest;
            newest.push_newclient(this->remote_endpoint_);
            newest.message = this->NbofClientassign;//debug
            this->_gameContainers.push_back(newest);
        }
        else {
            this->_gameContainers.at(_gameContainers.size()-1).push_newclient(this->remote_endpoint_);
        }
        this->NbofClientassign++;
    }
}*/


