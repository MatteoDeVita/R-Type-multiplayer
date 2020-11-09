/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Audio
*/

#pragma once

#include <map>
#include <SFML/Audio.hpp>

#include "Music.hpp"
#include "FX.hpp"

namespace gameEngine_ns {
    namespace audio_ns {
        class Audio {
            private:
                std::map<const std::string, gameEngine_ns::audio_ns::Music *> _musics;
                std::map<const std::string,  gameEngine_ns::audio_ns::FX *> _fxs;
            public:
                int addMusic(const std::string &id, gameEngine_ns::audio_ns::Music *music);
                int addFX(const std::string &id, gameEngine_ns::audio_ns::FX *fx);
                gameEngine_ns::audio_ns::Music *getMusic(const std::string &id) const;
                gameEngine_ns::audio_ns::FX *getFX(const std::string &id) const;
                void removeMusic(const std::string &id);
                void removeFX(const std::string &id);
                Audio();
                ~Audio();
        };

    }
}

