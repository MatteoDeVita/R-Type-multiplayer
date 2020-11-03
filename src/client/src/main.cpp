/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/

#include <iostream>

#include "Network.hpp"
#include "GameEngine.hpp"

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "Usage: client <host> <UDP packets speed in MS>" << std::endl;
        exit(84);
    }
    Network net(argv);
    
    sf::RenderWindow window(sf::VideoMode(200, 200, 32), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
