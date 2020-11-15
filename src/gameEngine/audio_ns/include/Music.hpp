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
                /**
                 * @brief Construct a new Music object
                 * 
                 * @param filePath 
                 */
                Music(const std::string &filePath);
                /**
                 * @brief Destroy the Music object
                 * 
                 */
                ~Music();
                /**
                 * @brief PPlay music
                 * 
                 */
                void play();
                /**
                 * @brief Set the music volume
                 * 
                 * @param volume 
                 */
                void setVolume(const float &volume = 50);
                /**
                 * @brief Stop music
                 * 
                 */
                void stop();
                /**
                 * @brief Set if the music should repeat itself
                 * 
                 * @param loop 
                 */
                void setLoop(const bool &loop = true);
            private:
                sf::Music *_music;
        };
    }
}
