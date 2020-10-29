/*
** EPITECH PROJECT, 2020
** start [WSL: Ubuntu-20.04]
** File description:
** SERV_Network
*/

#include "Server.hpp"

udp_server::udp_server(boost::asio::io_context& io) : socket_(io, udp::endpoint(udp::v4(), 3000))
{
    this->start_receive();
}

void udp_server::start_receive()
{
    this->socket_.async_receive_from(boost::asio::buffer(this->recv_buffer_), this->remote_endpoint_, boost::bind(&udp_server::process, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void udp_server::process(const boost::system::error_code& error, std::size_t /*bytes_transferred*/)
{
    std::cout << this->remote_endpoint_.address() << std::endl;
    //traitement des infos recus et envoies des infos aux bons clients
    boost::shared_ptr<std::string> message(new std::string("suuuce"));
    std::cout << "datas received : "<< this->recv_buffer_.data() << std::endl;
    
    socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_, boost::bind(&udp_server::handle_send, this, message,boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    start_receive();
}

void udp_server::handle_send(boost::shared_ptr<std::string> /*message*/, const boost::system::error_code& /*error*/, std::size_t /*bytes_transferred*/){
    std::cout << "datas sended to " << this->remote_endpoint_.address() << std::endl;
}
