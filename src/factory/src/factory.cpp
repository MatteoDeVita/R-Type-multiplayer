/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** factory
*/

#include <iostream>
#include <string>
#include <sstream>

#include "factory.hpp"
#include "Error.hpp"
#include "Vector.hpp"

void factory_ns::loadTextures(gameEngine_ns::GameEngine *gameEngine)
{
    if (gameEngine->addTexture("monster1-texture", "../../assets/monsters/monster1.gif") != 0)
        throw Error("Can't load texture monster1.gif");
    if (gameEngine->addTexture("monster2-texture", "../../assets/monsters/monster2.gif") != 0)
        throw Error("Can't load texture monster2.gif");
    if (gameEngine->addTexture("monster3-texture", "../../assets/monsters/monster3.gif") != 0)
        throw Error("Can't load texture monster3.gif");
    if (gameEngine->addTexture("monster4-texture", "../../assets/monsters/monster4.gif") != 0)
        throw Error("Can't load texture monster4.gif");
    if (gameEngine->addTexture("monster5-texture", "../../assets/monsters/monster5.gif") != 0)
        throw Error("Can't load texture monster5.gif");
    if (gameEngine->addTexture("monster6-texture", "../../assets/monsters/monster6.gif") != 0)
        throw Error("Can't load texture monster6.gif");
    if (gameEngine->addTexture("monster7-texture", "../../assets/monsters/monster7.png") != 0)
        throw Error("Can't load texture monster7.gif");
    if (gameEngine->addTexture("monster8-texture", "../../assets/monsters/monster8.gif") != 0)
        throw Error("Can't load texture monster8.gif");  
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster1Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 0, 64, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(70, 0, 56, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(196, 0, 64, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(262, 0, 64, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(333, 0, 52, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(457, 0, 64, 132));
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster2Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 1, 63, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(66, 1, 63, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(131, 1, 63, 48));
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster3Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 1, 32, 31));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(34, 1, 32, 31));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(67, 1, 32, 31));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(101, 1, 32, 31));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(134, 1, 32, 31));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(167, 1, 32, 31));
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster4Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(5, 6, 22, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(38, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(71, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(104, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(137, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(170, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(203, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(236, 6, 21, 24));
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster5Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 2, 31, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(34, 2, 32, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(37, 2, 32, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(67, 2, 32, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(100, 2, 31, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(133, 2, 31, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(166, 2, 32, 25));
   
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster6Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(34, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(34, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(67, 6, 31, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(67, 6, 31, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(100, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(133, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(133, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(166, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(199, 6, 31, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(232, 6, 32, 22));
   
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster7Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 9, 48, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 74, 48, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 139, 48, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 204, 48, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 204, 48, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 269, 48, 48));
    
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster8Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 102, 32, 30));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(35, 102, 32, 30));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(69, 102, 32, 30));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(103, 102, 29, 30));
    
    return vec;
}

void factory_ns::updateObjectsFromNetworkData(gameEngine_ns::GameEngine *gameEngine, const std::string &data)
{
    std::stringstream ss(data);
    std::string tmp;
    gameEngine_ns::object_ns::Sprite *sprite;


    std::size_t firstSpaceIndex = 0;
    std::size_t secondSpaceIndex = 0;
    std::string x_str, y_str, id_str;
    float x = 0;
    float y = 0;
    while (std::getline(ss, tmp, '|')) {
        firstSpaceIndex = tmp.find(" ");
        x_str = tmp.substr(0, firstSpaceIndex);

        secondSpaceIndex = tmp.find(" ", x_str.length() + 1);
        y_str = tmp.substr(firstSpaceIndex + 1, secondSpaceIndex - firstSpaceIndex - 1);

        id_str = tmp.substr(secondSpaceIndex + 1, tmp.length() - firstSpaceIndex - 1);

        x = std::stof(x_str);
        y = std::stof(y_str);

        if (gameEngine->getObject(id_str) == nullptr) {
            if ((sprite = gameEngine->createSprite("monster8-texture", factory_ns::getMonster8Vec() , 100)) == nullptr)
                throw Error("Can't load sprite");
            if (gameEngine->addSprite("monster8-sprite", sprite) != 0)
                throw Error("Can't add sprite");
            gameEngine->addObject(
                id_str, new gameEngine_ns::object_ns::Object(
                    gameEngine->getSprite("monster8-sprite"),
                    gameEngine_ns::geometry_ns::Vector(x, y)
                )
            );
        }
        else {
            gameEngine->getObject(id_str)->setPos(gameEngine_ns::geometry_ns::Vector(x, y));
        }        
    }
}
