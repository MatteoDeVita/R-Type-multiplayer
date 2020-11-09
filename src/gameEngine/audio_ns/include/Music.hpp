/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Music
*/

#pragma once

#include <string>
#include <SFML/Audio.hpp>

namespace gameEngine_ns {
    namespace audio_ns {
        class Music {
            public:
                Music(const std::string &filePath);
                ~Music();
                void play();
                void setVolume(const float &volume = 50);
                void stop();
            private:
                sf::Music *_music;
        };
    }
}

