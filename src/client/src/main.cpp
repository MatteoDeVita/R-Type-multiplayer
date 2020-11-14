/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/

#include <iostream>
#include <filesystem>
#include <vector>
#include <stdlib.h>
#include <time.h>

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
        if (argc != 2) {
            std::cerr << "Usage: client <host>" << std::endl;
            throw Error("Bad usage.");
        }
        srand(time(NULL));
        environment_t *environment = new environment_t;
        gameEngine_ns::GameEngine gameEngine;

        gameEngine.createWindow(gameEngine_ns::geometry_ns::Vector(1600, 900));

        factory_ns::loadMonsterTextures(&gameEngine);
        factory_ns::loadPlayerTextures(&gameEngine);
        factory_ns::loadLasersTextures(&gameEngine);
        factory_ns::loadExplosionTexture(&gameEngine);
        factory_ns::loadLaserObjects(&gameEngine, true);
        factory_ns::loadLaserObjects(&gameEngine, false);
        factory_ns::laodExplosionObjects(&gameEngine);
        factory_ns::loadEnvironment(&gameEngine);
        // factory_ns::loadMusic(&gameEngine);
        sleep(2);
        Network net(argv[1], environment, &gameEngine);

        // gameEngine.audio->getMusic("music-main")->play();

        while (gameEngine.window->isOpen()) {
            gameEngine.event->handlePollEvent(&net.EnvClientData->datas_send);
            gameEngine.window->reset();
            gameEngine.window->addObject(gameEngine.getObject("background-object1"));
            gameEngine.getObject("background-object2")->autoMoove();
            gameEngine.getObject("background-object3")->autoMoove();
            gameEngine.getObject("background-object4")->autoMoove();
            gameEngine.getObject("background-object5")->autoMoove();
            gameEngine.getObject("background-object6")->autoMoove();
            gameEngine.getObject("background-object7")->autoMoove();
            gameEngine.getObject("background-object8")->autoMoove();
            gameEngine.getObject("background-object9")->autoMoove();
            gameEngine.window->addObject(gameEngine.getObject("background-object2"));
            gameEngine.window->addObject(gameEngine.getObject("background-object3"));
            gameEngine.window->addObject(gameEngine.getObject("background-object4"));
            gameEngine.window->addObject(gameEngine.getObject("background-object5"));
            gameEngine.window->addObject(gameEngine.getObject("background-object6"));
            gameEngine.window->addObject(gameEngine.getObject("background-object7"));
            gameEngine.window->addObject(gameEngine.getObject("background-object8"));
            gameEngine.window->addObject(gameEngine.getObject("background-object9"));
            for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : gameEngine.getObjects()) {                
                if (pair.second == nullptr)
                    continue;
                // if (pair.first.substr(0, 9) == "explosion")
                //     std::cout << "x = " << pair.second->getPos().x << " y = " << pair.second->getPos().y << std::endl;
                if (pair.first.substr(0, 5) == "laser" && (pair.second->getPos().x <= 30 || pair.second->getPos().y <= 10 ))
                    continue;
                if (pair.first != "background-object1" && pair.second->getPos().y <= 15)
                    pair.second->setPos(gameEngine_ns::geometry_ns::Vector(
                        pair.second->getPos().x,
                        pair.second->getPos().y + 5
                    ));
                if (
                    pair.first.substr(0, 6) != "player" &&
                    pair.first.substr(0, 5) != "laser" &&
                    pair.second->getPos().x <= 17
                ) {
                    
                    continue;
                }
                // if (pair.first.substr(0, 9) == "explosion" && pair.second->getPos().x <= 0)
                //     continue;
                if (pair.second->getSprite() == nullptr)
                    continue;
                if (pair.second->getPos().x > -50) {
                    pair.second->getSprite()->update();
                    gameEngine.window->addObject(pair.second);
                }
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
