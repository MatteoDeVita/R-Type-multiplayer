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
#include <vector>

#include "Server.hpp"
#include "GameEngine.hpp"
#include "Sprite.hpp"
#include "Object.hpp"
#include "Error.hpp"

int main()
{
    try {
        UDP_Server s;
        s._io.run();
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}