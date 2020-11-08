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
#include "Window.hpp"
#include "Vector.hpp"
#include "Event.hpp"

namespace gameEngine_ns {
    class GameEngine {
        private:
            std::map<const std::string, sf::Texture *> _textures;
            std::map<const std::string, gameEngine_ns::object_ns::Sprite *> _sprites;
            std::map<const std::string, gameEngine_ns::object_ns::Object *> _objects;
        public:
            GameEngine();
            ~GameEngine();
            gameEngine_ns::window_ns::Window *window;
            gameEngine_ns::event_ns::Event *event;
            int addObject(const std::string &id, gameEngine_ns::object_ns::Object *object);
            // int addObject(const std::string &filePath, const std::string &id);
            int addTexture(const std::string &id, const std::string &filePath);
            int addSprite(const std::string &id, gameEngine_ns::object_ns::Sprite *sprite);
            gameEngine_ns::object_ns::Sprite *getSprite(const std::string &id) const;
            int loadFromConfigurationFile(const std::string &filePath);
            gameEngine_ns::object_ns::Sprite *createSprite(const std::string &textureId, const std::vector<gameEngine_ns::geometry_ns::Rectangle> rectanglePositionsOnImage, float updateDelayMs = -1);
            void createWindow(const gameEngine_ns::geometry_ns::Vector &vector);
            const std::map<const std::string, gameEngine_ns::object_ns::Object *> getObjects() const;
            gameEngine_ns::object_ns::Object *getObject(const std::string &id) const;
    };
}
