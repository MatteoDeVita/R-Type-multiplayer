/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** Server
*/

#include "Server.hpp"

void Sender(boost::asio::io_context *io, UDP_Server *the_serv)
{
    udp::socket socket(*io, udp::endpoint(udp::v4(), 3000));
    boost::system::error_code ignored_error;
    /*while(1) {
       for (unsigned int i = 0; i < the_serv->_gameContainers.size(); i++) {
           for (unsigned int y = 0; the_serv->_gameContainers.at(i)._clients.size(); y++) {
               boost::asio::steady_timer timer1_(*io, boost::asio::chrono::seconds(1));
               timer1_.wait();
               std::string message = std::to_string(the_serv->_gameContainers.at(i)._clients.at(y).ton_num);
               std::cout << the_serv->_gameContainers.at(i)._clients.at(y)._endpoint.address() << std::endl;
               socket.send_to(boost::asio::buffer(message), the_serv->_gameContainers.at(i)._clients.at(y)._endpoint, 0, ignored_error);
           }
       }
    }*/
}

void receive(UDP_Server *the_serv, boost::asio::io_context *io)
{
    /*udp::resolver resolver(*io);*/
    udp::socket socket(*io, udp::endpoint(udp::v4(), 3000));

    udp::endpoint client_endpoint;
    boost::system::error_code error;
    while(1) {
        size_t len = socket.receive_from(boost::asio::buffer(the_serv->_recv_buffer), client_endpoint, 0, error);
        std::cout << the_serv->get_user_is_know(client_endpoint) << std::endl;
    }
}

UDP_Server::UDP_Server()
{
    this->NbofClientassign = 0;
    boost::asio::io_context io;
    //udp::socket socket(io, udp::endpoint(udp::v4(), 3000));
    
    boost::thread t1(receive, this, &io);
    boost::thread t2(Sender, &io, this);
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