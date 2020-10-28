/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/

#include "Network.hpp"

int main()
{
    boost::asio::io_context io_context;
    udp_server server(io_context);
    io_context.run();
    return 0;
}