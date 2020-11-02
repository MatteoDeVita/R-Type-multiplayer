/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Sprite
*/

#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>


#include "Rectangle.hpp"

namespace gameEngine_ns {
    namespace object_ns {
        class Sprite {
            private:
                
            public:
                Sprite(const std::string &filePath, std::vector<geometry_ns::Rectangle> rectanglePositionsOnImage);
                ~Sprite();            
        };
    }
}

