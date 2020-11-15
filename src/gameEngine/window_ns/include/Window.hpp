/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Window
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <Vector.hpp>

#include "IObject.hpp"

namespace gameEngine_ns {
    namespace window_ns {
        class Window {
            private:
                sf::RenderWindow *_window;
            public:
                /**
                 * @brief Construct a new Window object
                 * 
                 * @param size 
                 */
                Window(const gameEngine_ns::geometry_ns::Vector &size);
                /**
                 * @brief Tell if the window is opened or not
                 * 
                 * @return true if the window is currentlty opened
                 * @return false otherwise
                 */
                bool isOpen() const;
                /**
                 * @brief Get the corresponding SFML window
                 * 
                 * @return sf::Window* 
                 */
                sf::Window *getSFMLWindow() const;
                /**
                 * @brief Add an object to draw
                 * 
                 * @param object 
                 */
                void addObject(gameEngine_ns::object_ns::IObject *object);
                /**
                 * @brief Display
                 * 
                 */
                void display();
                /**
                 * @brief Reset window with a black screen
                 * 
                 */
                void reset();
                ~Window();
        };
    }
}
