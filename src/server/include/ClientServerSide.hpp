/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** ClientServerSide
*/

#pragma once

#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

class ClientServerSide {
    public:
        ClientServerSide();
        ~ClientServerSide();
        boost::asio::ip::udp::endpoint _endpoint;
        int num; //debug

    protected:
    private:
        
};
