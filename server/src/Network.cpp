/*
** EPITECH PROJECT, 2020
** start [WSL: Ubuntu-20.04]
** File description:
** SERV_Network
*/

#include "Network.hpp"

udp_server::udp_server(boost::asio::io_context& io) : socket_(io, udp::endpoint(udp::v4(), 3000))
{
    this->start_receive();
}

void udp_server::start_receive()
{
    this->socket_.async_receive_from(boost::asio::buffer(this->recv_buffer_), this->remote_endpoint_, boost::bind(&udp_server::process, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void udp_server::process(const boost::system::error_code& error, std::size_t bytes_transferred)
{
    std::cout << this->remote_endpoint_.address() << std::endl;

    boost::shared_ptr<std::string> message(new std::string("suuuce"));


    std::cout << std::string(this->recv_buffer_.begin(), this->recv_buffer_.begin()+ bytes_transferred) << std::endl;


    boost::bind(&udp_server::handle_send, this, message, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred);
    start_receive();
}

void udp_server::handle_send(boost::shared_ptr<std::string> /*message*/, const boost::system::error_code& /*error*/, std::size_t /*bytes_transferred*/){}
