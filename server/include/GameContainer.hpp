/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** GameContainer
*/

#pragma once

#include "ClientServerSide.hpp"

class GameContainer {
    public:
        GameContainer();
        ~GameContainer();
        void push_newclient(boost::asio::ip::udp::endpoint);
        std::vector<ClientServerSide> _clients;
        typedef struct send_struct_t {
            std::string a;
            char b;
            int c;
            template<typename Ar> void serialize(Ar& ar, unsigned) { ar & a & b & c; }
        } sample;
        sample data_struct;
        void update_struct();
    protected:
    private:
};
