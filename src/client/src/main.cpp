/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/

#include "Network.hpp"

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "Usage: client <host> <UDP packets speed in MS>" << std::endl;
        exit(84);
    }
    Network net(argc, argv);

    while (1) { //Gameloop
    
    }
    return 0;
}