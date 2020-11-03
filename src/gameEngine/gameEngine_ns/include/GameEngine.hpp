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

#include "Object.hpp"
#include "Sprite.hpp"

namespace gameEngine_ns {
    class GameEngine {
        private:
            std::map<const std::string, sf::Texture *> _textures;
            std::map<const std::string, gameEngine_ns::object_ns::Sprite *> _sprites;
        public:
            GameEngine();
            ~GameEngine();
            int addObject(gameEngine_ns::object_ns::Object *object, const std::string &id);
            int addObject(const std::string &filePath, const std::string &id);
            int addTexture(const std::string &filePath, const std::string &id);
            int addSprite(const std::string &id, gameEngine_ns::object_ns::Sprite *sprite, const std::string &textureId);
            int loadFromConfigurationFile(const std::string &filePath);
            gameEngine_ns::object_ns::Sprite *createSprite(const std::string &textureId, const std::vector<gameEngine_ns::geometry_ns::Rectangle> rectanglePositionsOnImage);
    };
}
