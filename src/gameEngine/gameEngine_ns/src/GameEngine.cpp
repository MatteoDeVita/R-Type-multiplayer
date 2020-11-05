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
    this->window = nullptr;
    this->event = new gameEngine_ns::event_ns::Event(this->window);
}

gameEngine_ns::GameEngine::~GameEngine()
{
    if (this->window != nullptr)
        delete this->window;
    delete this->event;
}

int gameEngine_ns::GameEngine::addTexture(const std::string &id, const std::string &filePath)
{
    sf::Texture *newTexture = new sf::Texture;

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

int gameEngine_ns::GameEngine::addSprite(const std::string &id, gameEngine_ns::object_ns::Sprite *sprite)
{
    if (this->_sprites.insert(std::make_pair(id, sprite)).second == false) {
        std::cerr << "A sprite with id \"" << id << "\" already exists." << std::endl;
        return -1;
    }
    return 0;
}

gameEngine_ns::object_ns::Sprite *gameEngine_ns::GameEngine::createSprite(const std::string &textureId, const std::vector<gameEngine_ns::geometry_ns::Rectangle> rectanglePositionsOnImage, float updateDelayMs)
{
    if (this->_textures.count(textureId) == false) {
        std::cerr << "The texture id \"" << textureId << "\" doesn't exists." << std::endl;
        return nullptr;
    }
    gameEngine_ns::object_ns::Sprite *sprite;
    if (updateDelayMs <= 0)
        sprite = new gameEngine_ns::object_ns::Sprite(this->_textures[textureId], rectanglePositionsOnImage);
    else        
        sprite = new gameEngine_ns::object_ns::Sprite(this->_textures[textureId], rectanglePositionsOnImage, updateDelayMs);    
    return sprite;
}

void gameEngine_ns::GameEngine::createWindow(const gameEngine_ns::geometry_ns::Vector &vector)
{
    this->window = new gameEngine_ns::window_ns::Window(vector);
    this->event->setWindow(this->window);
}

int gameEngine_ns::GameEngine::addObject(const std::string &id, gameEngine_ns::object_ns::Object *object)
{
    if (this->_objects.insert(std::make_pair(id, object)).second == false) {
        std::cerr << "An object with id \"" << id << "\" already exists." << std::endl;
        return -1;
    }
    return 0;
}

gameEngine_ns::object_ns::Sprite *gameEngine_ns::GameEngine::getSprite(const std::string &id) const
{
    if (this->_sprites.count(id) == false)
        return nullptr;
    return this->_sprites.at(id);
}

const std::map<const std::string, gameEngine_ns::object_ns::Object *> gameEngine_ns::GameEngine::getObjects() const
{
    return this->_objects;
}

gameEngine_ns::object_ns::Object *gameEngine_ns::GameEngine::getObject(const std::string &id) const
{
    if (this->_objects.count(id) == false) {
        return nullptr;
    }   
    return this->_objects.at(id);
}
