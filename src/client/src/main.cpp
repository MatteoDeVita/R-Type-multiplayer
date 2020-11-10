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
        sleep(2);
        Network net(argv, environment, &gameEngine);

        // gameEngine.audio->getMusic("music-main")->play();
        // int frame = 0;
        // sf::Clock clock;
        // clock.restart();
        while (gameEngine.window->isOpen()) {
            gameEngine.event->handlePollEvent(&net.EnvClientData->datas_send);
            gameEngine.window->reset();
            gameEngine.window->addObject(gameEngine.getObject("background-object"));
            for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : gameEngine.getObjects()) {
                // std::cout << "id = " << pair.first << " x = " << pair.second->getPos().x << " y = " << pair.second->getPos().y << std::endl;
                if (pair.first != "background-object" && pair.second->getPos().y <= 15)
                    pair.second->setPos(gameEngine_ns::geometry_ns::Vector(
                        pair.second->getPos().x,
                        pair.second->getPos().y + 5
                    ));
                if (pair.first.substr(0, 6) != "player" && pair.second->getPos().x <= 17)
                    continue;
                if (pair.second == nullptr)
                    continue;
                if (pair.second->getSprite() == nullptr)
                    continue;
                pair.second->getSprite()->update(); //ICI
                gameEngine.window->addObject(pair.second);
            }
            gameEngine.window->display();
            // frame++;
            // if (clock.getElapsedTime().asSeconds() >= 1) {
            //     std::cout << "FRAME = " << frame << std::endl;
            //     frame = 0;
            //     clock.restart();
            // }
        }
        return 0;
    }
    catch (std::exception const &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        return 84;
    }
}
