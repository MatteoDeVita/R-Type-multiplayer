/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Window
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <Vector.hpp>

#include "Object.hpp"

namespace gameEngine_ns {
    namespace window_ns {
        class Window {
            private:
                sf::RenderWindow *_window;
            public:        
                Window(const gameEngine_ns::geometry_ns::Vector &size);
                bool isOpen() const;
                sf::Window *getSFMLWindow() const;
                int addObject(gameEngine_ns::object_ns::Object *object);
                void display();
                void reset();
                ~Window();
        };
    }
}
