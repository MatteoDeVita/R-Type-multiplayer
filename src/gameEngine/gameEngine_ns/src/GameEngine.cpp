/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** GameEngine
*/

#include <iostream>

#include "GameEngine.hpp"
#include "Rectangle.hpp"

gameEngine_ns::GameEngine::GameEngine()
{

}

gameEngine_ns::GameEngine::~GameEngine()
{

}

int gameEngine_ns::GameEngine::addTexture(const std::string &filePath, const std::string &id)
{
    sf::Texture *newTexture = new sf::Texture;

    std::cout << "ID = " << id << std::endl;
    if (newTexture->loadFromFile(filePath) != true) {
        std::cerr << "Can't load texture " << filePath << '.' << std::endl;
        return -1;
    }
    if (this->_textures.insert(std::make_pair(id, newTexture)).second == false) {
        std::cerr << "A texture with id \"" << id << "\" already exists." << std::endl;
        return -1;
    }
    return 0;
}

int gameEngine_ns::GameEngine::addSprite(const std::string &id, gameEngine_ns::object_ns::Sprite *sprite, const std::string &textureId)
{
    if (this->_sprites.insert(std::make_pair(id, sprite)).second == false) {
        std::cerr << "A sprite with id \"" << id << "\" already exists." << std::endl;
        return -1;
    }
    return 0;
}

gameEngine_ns::object_ns::Sprite *gameEngine_ns::GameEngine::createSprite(const std::string &textureId, const std::vector<gameEngine_ns::geometry_ns::Rectangle> rectanglePositionsOnImage)
{
    if (this->_textures.count(textureId) == false) {
        std::cerr << "The texture id \"" << textureId << "\" doesn't exists." << std::endl;
        return nullptr;
    }
    gameEngine_ns::object_ns::Sprite *sprite = new gameEngine_ns::object_ns::Sprite(this->_textures[textureId], rectanglePositionsOnImage);
    return sprite;
}
