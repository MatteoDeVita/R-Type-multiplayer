/*
** EPITECH PROJECT, 2020
** start [WSL: Ubuntu-20.04]
** File description:
** SERV_Network
*/

#include "Network.hpp"

udp_server::udp_server(boost::asio::io_context& io_context) : socket_(io_context, udp::endpoint(udp::v4(), 3000))
{
    this->start_receive();
}

 void udp_server::start_receive()
  {
    this->socket_.async_receive_from(
        boost::asio::buffer(this->recv_buffer_), this->remote_endpoint_, boost::bind(&udp_server::handle_receive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
  }

  void udp_server::handle_receive(const boost::system::error_code& error, std::size_t /*bytes_transferred*/)
  {
        boost::shared_ptr<std::string> message(new std::string("suuuce"));
        std::cout << this->recv_buffer_.data() << std::endl;
        this->socket_.async_send_to(boost::asio::buffer(*message), this->remote_endpoint_,boost::bind(&udp_server::handle_send, this, message, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

        start_receive();
  }

  void udp_server::handle_send(boost::shared_ptr<std::string> /*message*/, const boost::system::error_code& /*error*/, std::size_t /*bytes_transferred*/)
  {
  }
