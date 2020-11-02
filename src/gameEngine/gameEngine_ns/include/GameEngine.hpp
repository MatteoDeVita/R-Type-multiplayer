/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** GameEngine
*/

#pragma once

#include <vector>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

namespace gameEngine_ns {
    class GameEngine {
        private:
            std::map<const std::string, sf::Texture *> _textures;
        public:
            GameEngine();
            ~GameEngine();
            int addTexture(const std::string &filePath, const std::string &id);
        protected:
    };

}

