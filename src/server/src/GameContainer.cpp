/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** GameContainer
*/

#include <vector>

#include "GameContainer.hpp"
#include "Sprite.hpp"
#include "Object.hpp"
#include "Error.hpp"

void GameContainer::push_newclient(boost::asio::ip::udp::endpoint endpointer)
{
    ClientServerSide newest;

    newest._endpoint = endpointer;
    this->_clients.push_back(newest);
}

GameContainer::GameContainer()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;
        
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 0, 64, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(70, 0, 56, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(196, 0, 64, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(262, 0, 64, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(333, 0, 52, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(457, 0, 64, 132));
    gameEngine_ns::object_ns::Sprite *sprite;
    gameEngine_ns::object_ns::Object *object;

    if (this->_gameEngine.addTexture("monster1-texture", "../../assets/monsters/monster1.gif") != 0)
        throw Error("Can't load texture monster1.gif");
    if ((sprite = this->_gameEngine.createSprite("monster1-texture", vec, 100)) == nullptr)
        throw Error("Can't load sprite");
    if (this->_gameEngine.addSprite("monster1-sprite", sprite) != 0)
        throw Error("Can't add sprite");
    object = new gameEngine_ns::object_ns::Object(sprite, gameEngine_ns::geometry_ns::Vector());
    if (this->_gameEngine.addObject("object-monster1", object) != 0)
        throw Error("Can't add object");
}

GameContainer::~GameContainer()
{

}

void GameContainer::update_struct()
{
    this->EnvServData.pos_x.clear();
    this->EnvServData.pos_y.clear();
    this->EnvServData.sprite_ids.clear();
    for (const std::pair<const std::string, gameEngine_ns::object_ns::Object *> &pair : this->_gameEngine.getObjects()) {
        this->EnvServData.pos_x.push_back(pair.second->getPos().x);
        this->EnvServData.pos_x.push_back(pair.second->getPos().y);
        this->EnvServData.sprite_ids.push_back(pair.first);
    }
}
