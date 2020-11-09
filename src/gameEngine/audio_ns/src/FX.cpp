/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** FX
*/

#include "FX.hpp"
#include "Error.hpp"

gameEngine_ns::audio_ns::FX::FX(const std::string &filePath)
{
    this->_buffer = new sf::SoundBuffer;
    if (this->_buffer->loadFromFile(filePath) == false)
        throw Error("Can't load sound buffer: " + filePath + ".");
    if ((this->_sound = new sf::Sound(*this->_buffer)) == nullptr)
        throw Error("Can't load sound.");
}

gameEngine_ns::audio_ns::FX::~FX()
{
    if (this->_buffer != nullptr)
        delete this->_buffer;
    if (this->_sound != nullptr)
        delete this->_sound;
}


void gameEngine_ns::audio_ns::FX::play()
{
    this->_sound->play();
}

void gameEngine_ns::audio_ns::FX::setVolume(const float &volume)
{
    this->_sound->setVolume(volume);
}

void gameEngine_ns::audio_ns::FX::stop()
{
    this->_sound->stop();
}
