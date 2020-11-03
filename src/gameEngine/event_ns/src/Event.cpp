/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Event
*/

#include "Event.hpp"

gameEngine_ns::event_ns::Event::Event(gameEngine_ns::window_ns::Window *window)
{
    this->_window = window;
}

gameEngine_ns::event_ns::Event::~Event()
{
}

void gameEngine_ns::event_ns::Event::setWindow(gameEngine_ns::window_ns::Window *window)
{
    this->_window = window;
}

void gameEngine_ns::event_ns::Event::handlePollEvent()
{
    while (this->_window->getSFMLWindow()->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            this->_window->getSFMLWindow()->close();
    }
}
