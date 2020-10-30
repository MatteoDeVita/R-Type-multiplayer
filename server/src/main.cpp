/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/
#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include "Server.hpp"

int main()
{
    boost::asio::io_context io;
    UDP_Server serv(&io);
    while(1)
    {}
    return 0;
}