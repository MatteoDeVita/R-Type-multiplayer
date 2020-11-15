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
                /**
                 * @brief Construct a new FX object
                 * 
                 * @param filePath 
                 */
                FX(const std::string &filePath);
                /**
                 * @brief Destroy the FX object
                 * 
                 */
                ~FX();
                /**
                 * @brief Play fx sound
                 * 
                 */
                void play();
                /**
                 * @brief Set the fx volume object
                 * 
                 * @param volume 
                 */
                void setVolume(const float &volume = 50);
                /**
                 * @brief Stop FX
                 * 
                 */
                void stop();
            private:
                sf::Sound *_sound;
                sf::SoundBuffer *_buffer;
        };
    }
}
