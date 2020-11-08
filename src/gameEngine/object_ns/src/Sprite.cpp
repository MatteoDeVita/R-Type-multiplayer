/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Sprite
*/

#include <iostream>

#include "Sprite.hpp"

gameEngine_ns::object_ns::Sprite::Sprite(sf::Texture *texture, const std::vector<geometry_ns::Rectangle> &rectanglePositionsOnImage, float delayMs)
{
    this->_texture = texture;
    this->_rectanglePositionsOnImage = rectanglePositionsOnImage;
    this->_sprite = new sf::Sprite;
    this->_sprite->setTexture(*this->_texture);
    this->_delayMs = delayMs;
    this->_textureRectIt = this->_rectanglePositionsOnImage.begin();
    this->_clock = new sf::Clock;    

    if (delayMs > 0) {
        this->_clock->restart();
        this->update();
    }
}

gameEngine_ns::object_ns::Sprite::~Sprite()
{
    delete this->_sprite;
    delete this->_clock;
}

sf::Sprite *gameEngine_ns::object_ns::Sprite::getSFMLSprite() const
{
    return this->_sprite;
}

void gameEngine_ns::object_ns::Sprite::update()
{
    if (this->_delayMs <= 0)
        return;
    if (this->_clock->getElapsedTime().asMilliseconds() < this->_delayMs)
        return;
    this->_sprite->setTextureRect((this->_textureRectIt++)->toSfIntRect());
    if (this->_textureRectIt == this->_rectanglePositionsOnImage.end())
        this->_textureRectIt = this->_rectanglePositionsOnImage.begin();
    this->_clock->restart();
}

void gameEngine_ns::object_ns::Sprite::moove(const gameEngine_ns::geometry_ns::Vector &vector)
{
    this->_sprite->move(vector.toSfVector2f());
}
