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
                Event(gameEngine_ns::window_ns::Window *window);
                void handlePollEvent(std::string *networkData);
                void setWindow(gameEngine_ns::window_ns::Window *window);
                ~Event();
        };
    }
}
