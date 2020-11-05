/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/

#include <iostream>
#include <filesystem>
#include <vector>

#include "Network.hpp"
#include "GameEngine.hpp"
#include "Error.hpp"
#include "Vector.hpp"
#include "Rectangle.hpp"
#include "Object.hpp"
#include "factory.hpp"

int main(int argc, char **argv)
{
    try {        
        if (argc != 3) {
            std::cerr << "Usage: client <host> <UDP packets speed in MS>" << std::endl;
            throw Error("Bad usage.");
        }
        environment_t *environment = new environment_t;
        gameEngine_ns::GameEngine gameEngine;
        Network net(argv, environment, &gameEngine);
        std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 0, 64, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(70, 0, 56, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(196, 0, 64, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(262, 0, 64, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(333, 0, 52, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(457, 0, 64, 132));
        gameEngine_ns::object_ns::Sprite *sprite;
        gameEngine_ns::object_ns::Object *object;
        
        gameEngine.createWindow(gameEngine_ns::geometry_ns::Vector(1600, 900));

        factory_ns::loadTextures(&gameEngine);

        while (gameEngine.window->isOpen()) {
            gameEngine.event->handlePollEvent();

            gameEngine.window->reset();
            for (const std::pair<const std::string, gameEngine_ns::object_ns::Object *> &pair : gameEngine.getObjects()) { 
                pair.second->getSprite()->update();
                gameEngine.window->addObject(pair.second);                
            }
            // gameEngine.window->addObject(object);
            gameEngine.window->display();
        }
        return 0;
    }
    catch (std::exception const &e) {
        std::cerr << "ERROR: " << e.what() << std::endl; 
        return 84;
    }
}
