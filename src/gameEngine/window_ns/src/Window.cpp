/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Window
*/

#include "Window.hpp"

gameEngine_ns::window_ns::Window::Window(const gameEngine_ns::geometry_ns::Vector &size)
{
    this->_window = new sf::RenderWindow(sf::VideoMode(size.x, size.y), "R-Type");
}

void gameEngine_ns::window_ns::Window::display()
{
    this->_window->display();
}

gameEngine_ns::window_ns::Window::~Window()
{
    delete this->_window;
}

bool gameEngine_ns::window_ns::Window::isOpen() const
{
    return this->_window->isOpen();
}

sf::Window *gameEngine_ns::window_ns::Window::getSFMLWindow() const
{
    return this->_window;
}

int gameEngine_ns::window_ns::Window::addObject(gameEngine_ns::object_ns::Object *object)
{
    this->_window->draw(*object->getSprite()->getSFMLSprite());
}

void gameEngine_ns::window_ns::Window::reset()
{
    this->_window->clear(sf::Color::Black);
}
