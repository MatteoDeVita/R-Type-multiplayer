/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/

#include "Server.hpp"

int main()
{
    boost::asio::io_context io;
    UDP_Server serv(&io);
    return 0;
}