/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** FX
*/

#pragma once

#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

namespace gameEngine_ns {
    namespace audio_ns {
        class FX {
            public:
                FX(const std::string &filePath);
                ~FX();
                void play();
                void setVolume(const float &volume = 50);
                void stop();
            private:
                sf::Sound *_sound;
                sf::SoundBuffer *_buffer;
        };
    }
}
