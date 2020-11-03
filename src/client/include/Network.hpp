/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** Network
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
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include "environment.hpp"

using boost::asio::ip::udp;

class Network {
    public:
        /**
         * @brief Construct a new Network object
         * 
         * @param argv 
         */
        Network(char **argv);
        /**
         * @brief Destroy the Network object
         * 
         */
        ~Network();
        environment_t EnvClientData;
        boost::asio::io_context *_io;
        udp::socket *_socket;
        int ms_speed;
        udp::resolver *_resolver;
        udp::endpoint _server_endpoint;
    protected:
    private:
};