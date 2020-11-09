/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Audio
*/

#include <iostream>

#include "Audio.hpp"
#include "Error.hpp"

gameEngine_ns::audio_ns::Audio::Audio()
{
}

gameEngine_ns::audio_ns::Audio::~Audio()
{
    for (const std::pair<const std::string, gameEngine_ns::audio_ns::Music *> &pair : this->_musics) {
        if (pair.second != nullptr)
            delete pair.second;
    }
    for (const std::pair<const std::string, gameEngine_ns::audio_ns::FX *> &pair : this->_fxs) {
        if (pair.second != nullptr)
            delete pair.second;
    }
    this->_musics.clear();
    this->_fxs.clear();
}

int gameEngine_ns::audio_ns::Audio::addMusic(const std::string &id, gameEngine_ns::audio_ns::Music *music)
{
    if (this->_musics.insert(std::make_pair(id, music)).second == false) {
        std::cerr << "A music with id \"" << id << "\" already exists." << std::endl;
        return -1;
    }
    return 0;
}

int gameEngine_ns::audio_ns::Audio::addFX(const std::string &id, gameEngine_ns::audio_ns::FX *fx)
{
    if (this->_fxs.insert(std::make_pair(id, fx)).second == false) {
        std::cerr << "An FX with id \"" << id << "\" already exists." << std::endl;
        return -1;
    }
    return 0;
}

gameEngine_ns::audio_ns::Music *gameEngine_ns::audio_ns::Audio::getMusic(const std::string &id) const
{
    if (this->_musics.count(id) == false) {
        return nullptr;
    }   
    return this->_musics.at(id);
}

gameEngine_ns::audio_ns::FX *gameEngine_ns::audio_ns::Audio::getFX(const std::string &id) const
{
    if (this->_fxs.count(id) == false) {
        return nullptr;
    }   
    return this->_fxs.at(id);
}

void gameEngine_ns::audio_ns::Audio::removeMusic(const std::string &id)
{
    if (this->_fxs.count(id) == false) {
        throw Error(id + " FX doesn't exists");
    }
    delete this->_fxs[id];
}

void gameEngine_ns::audio_ns::Audio::removeFX(const std::string &id)
{
    if (this->_musics.count(id) == false) {
        throw Error(id + " music doesn't exists");
    }
    delete this->_musics[id];
}
