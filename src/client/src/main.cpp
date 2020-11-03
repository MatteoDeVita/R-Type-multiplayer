/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/

#include <iostream>

#include "Network.hpp"
#include "GameEngine.hpp"
#include "Error.hpp"
#include "Vector.hpp"

int main(int argc, char **argv)
{
    try {
        if (argc != 3) {
            std::cerr << "Usage: client <host> <UDP packets speed in MS>" << std::endl;
            throw Error("Bad usage.");
        }
        Network net(argv);
        gameEngine_ns::GameEngine gameEngine;

        gameEngine.createWindow(gameEngine_ns::geometry_ns::Vector(1600, 900));
        
        while (gameEngine.window->isOpen()) {
            gameEngine.event->handlePollEvent();
        }
        return 0;
    }
    catch (std::exception const &e) {
        std::cerr << "ERROR: " << e.what() << std::endl; 
        return 84;
    }
}
