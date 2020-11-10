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
        
        gameEngine.createWindow(gameEngine_ns::geometry_ns::Vector(1600, 900));

        factory_ns::loadMonsterTextures(&gameEngine);
        factory_ns::loadPlayerTextures(&gameEngine);
        factory_ns::loadEnvironment(&gameEngine);
        factory_ns::loadMusic(&gameEngine);
        Network net(argv, environment, &gameEngine);

        // gameEngine.audio->getMusic("music-main")->play();

        while (gameEngine.window->isOpen()) {
            gameEngine.event->handlePollEvent(&net.EnvClientData->datas_send);

            gameEngine.window->reset();
            gameEngine.window->addObject(gameEngine.getObject("background-object"));            
            for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : gameEngine.getObjects()) {
                pair.second->getSprite()->update();
                gameEngine.window->addObject(pair.second);
            }
            gameEngine.window->display();
        }
        return 0;
    }
    catch (std::exception const &e) {
        std::cerr << "ERROR: " << e.what() << std::endl; 
        return 84;
    }
}
