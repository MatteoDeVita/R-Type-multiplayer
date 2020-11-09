/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Music
*/

#include <Error.hpp>

#include "Music.hpp"

gameEngine_ns::audio_ns::Music::Music(const std::string &filePath)
{
   
    if ((this->_music = new sf::Music) == nullptr)
        throw Error("Can't allocate memory for music.");
    if (this->_music->openFromFile(filePath) == false)
        throw Error("Can't load music from file: " + filePath + ".");
}

gameEngine_ns::audio_ns::Music::~Music()
{  
    if (this->_music != nullptr)
        delete this->_music;
}

void gameEngine_ns::audio_ns::Music::play()
{
    this->_music->play();
}

void gameEngine_ns::audio_ns::Music::setVolume(const float &volume)
{
    this->_music->setVolume(volume);
}

void gameEngine_ns::audio_ns::Music::stop()
{
    this->_music->stop();
}

void gameEngine_ns::audio_ns::Music::setLoop(const bool &loop)
{
    this->_music->setLoop(loop);
}
