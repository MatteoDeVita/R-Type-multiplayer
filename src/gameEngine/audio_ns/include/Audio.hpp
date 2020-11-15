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
            /**
             * @brief Add a music and set music id to id param.
             * 
             * @param id new music id
             * @param music music to add
             * @return 0 if everything is ok. -1 if an error occured.
             */
                int addMusic(const std::string &id, gameEngine_ns::audio_ns::Music *music);
                /**
                 * @brief Add a new FX and set id to id param
                 * 
                 * @param id  new FX id
                 * @param fx FX to add
                 * @return 0 if everything is ok. -1 if an error occured.
                 */
                int addFX(const std::string &id, gameEngine_ns::audio_ns::FX *fx);
                /**
                 * @brief Get the Music object
                 * 
                 * @param id music id
                 * @return gameEngine_ns::audio_ns::Music* 
                 */
                gameEngine_ns::audio_ns::Music *getMusic(const std::string &id) const;
                /**
                 * @brief get the FX object
                 * 
                 * @param id fx id
                 * @return gameEngine_ns::audio_ns::FX* 
                 */
                gameEngine_ns::audio_ns::FX *getFX(const std::string &id) const;
                /**
                 * @brief Remove a music from registered music list
                 * 
                 * @param id music id
                 */
                void removeMusic(const std::string &id);
                /**
                 * @brief remove an FX from FX list
                 * 
                 * @param id fx id
                 */
                void removeFX(const std::string &id);
                /**
                 * @brief Construct a new Audio object
                 * 
                 */
                Audio();
                /**
                 * @brief Destroy the Audio object
                 * 
                 */
                ~Audio();
        };

    }
}

