/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Sprite
*/

#include "Sprite.hpp"

gameEngine_ns::object_ns::Sprite::Sprite(sf::Texture *texture, const std::vector<geometry_ns::Rectangle> &rectanglePositionsOnImage, float delayMs)
{
    this->_texture = texture;
    this->_rectanglePositionsOnImage = rectanglePositionsOnImage;
    this->_sprite = new sf::Sprite;
    this->_sprite->setTexture(*this->_texture);
    this->_delayMs = delayMs;
    this->_textureRectIt = this->_rectanglePositionsOnImage.begin(); 
    this->update();
}

gameEngine_ns::object_ns::Sprite::~Sprite()
{
    delete this->_sprite;
}

sf::Sprite *gameEngine_ns::object_ns::Sprite::getSFMLSprite() const
{
    return this->_sprite;
}

void gameEngine_ns::object_ns::Sprite::update()
{
    this->_sprite->setTextureRect(this->_textureRectIt->toSfIntRect());    
}