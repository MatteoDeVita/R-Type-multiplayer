/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Event
*/

#pragma once

#include <string>

#include "Window.hpp"

namespace gameEngine_ns {
    namespace event_ns {
        class Event {
            private:
                sf::Event _event;
                gameEngine_ns::window_ns::Window *_window;
                sf::Clock *_eventClock;
                sf::Clock *_shootingClock;
            public:
                /**
                 * @brief Construct a new Event object
                 * 
                 * @param window 
                 */
                Event(gameEngine_ns::window_ns::Window *window);
                /**
                 * @brief Handle poll event
                 * 
                 * @param networkData network data string
                 */
                void handlePollEvent(std::string *networkData);
                /**
                 * @brief Set the related window
                 * 
                 * @param window 
                 */
                void setWindow(gameEngine_ns::window_ns::Window *window);
                /**
                 * @brief Destroy the Event object
                 * 
                 */
                ~Event();
        };
    }
}
