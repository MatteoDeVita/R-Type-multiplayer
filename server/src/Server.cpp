/*
** EPITECH PROJECT, 2020
** start [WSL: Ubuntu-20.04]
** File description:
** SERV_Network
*/

#include "Server.hpp"
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
        }
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
  //  this->game_container_load_balancer();
    std::cout << this->remote_endpoint_.address() << std::endl;
    //traitement des infos recus et envoies des infos aux bons clients
    boost::shared_ptr<std::string> message(new std::string("suuuce"));
    std::cout << "datas received : "<< this->recv_buffer_.data() << std::endl;
    //this->send_data_game_to_clients();//peut etre bloquant BUG
    std::cout << "test" << std::endl;
    socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_, boost::bind(&udp_server::handle_send, this, message,boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
    start_receive();
}

void udp_server::handle_send(boost::shared_ptr<std::string> /*message*/, const boost::system::error_code& /*error*/, std::size_t /*bytes_transferred*/) {
    std::cout << "datas sended to " << this->remote_endpoint_.address() << std::endl;
}
