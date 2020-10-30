/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** Thread
*/

#include "Network.hpp"

using boost::asio::ip::udp;

Network::Network()
{
    
}

Network::~Network()
{
    delete this->_thread;
}

void Network::send(std::string message, udp::socket *socket)
{
    while(1) {
        boost::asio::steady_timer timer1_(this->io, boost::asio::chrono::seconds(1));
        timer1_.wait();
        socket->send_to(boost::asio::buffer(message), this->serverEndpoint);//envoie d'une var sendbuf au endpoint
    }
}

void Network::receive(udp::socket *socket) {
    while(1) {
        udp::endpoint client_endpoint;
        size_t len = socket->receive_from(boost::asio::buffer(this->recv_buf), client_endpoint);
        std::cout << "Data received : " << this->recv_buf.data() << std::endl;
    }
}
