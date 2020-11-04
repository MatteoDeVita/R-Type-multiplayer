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

        gameEngine_ns::GameEngine gameEngine;

        std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 0, 64, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(70, 0, 56, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(196, 0, 64, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(262, 0, 64, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(333, 0, 52, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(457, 0, 64, 132));
        gameEngine_ns::object_ns::Sprite *sprite;
        gameEngine_ns::object_ns::Object *object;

        if (gameEngine.addTexture("monster1-texture", "../../assets/monsters/monster1.gif") != 0)
            throw Error("Can't load texture monster1.gif");
        if ((sprite = gameEngine.createSprite("monster1-texture", vec, 100)) == nullptr)
            throw Error("Can't load sprite");
        if (gameEngine.addSprite("monster1-sprite", sprite) != 0)
            throw Error("Can't add sprite");
        object = new gameEngine_ns::object_ns::Object(sprite, gameEngine_ns::geometry_ns::Vector());
        if (gameEngine.addObject("object-monster1", object) != 0)
            throw Error("Can't add object");
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}