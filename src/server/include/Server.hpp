/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Server
*/

#pragma once

#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread/thread.hpp>
#include "Debug_color.hpp"
#include "GameContainer.hpp"

using boost::asio::ip::udp;

class UDP_Server
{
    public:
    
        /**
         * @brief Construct a new udp server object
         * 
         */
        UDP_Server();

        /**
         * @brief Destroy the udp server object
         * 
         */
        ~UDP_Server();

        /**
         * @brief send your informations (where are stocked in gamecontainer) to a client
         * 
        */
        void do_send();

        /**
         * @brief call this function to receive informations from a client
         * 
         */
        void do_receive();

        /**
         * @brief set the received informations on the gamecontainer where the player is connected or will be connect
         * 
         * @param client_endpoint  informations of incoming client's communication
         * @param serielise_string the incoming client's data_string
         */
        void set_user_info(udp::endpoint remote_endpoint, std::string serielise_string);
        std::vector<GameContainer *> _gameContainers;
        int NbofClientassign;
        boost::asio::io_context _io;
    private:
        udp::socket _socket;
        udp::endpoint _client_endpoint;
        enum { max_length = 10000 };
        char _data[max_length];
};