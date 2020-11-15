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

#include "IObject.hpp"
#include "Sprite.hpp"
#include "Window.hpp"
#include "Vector.hpp"
#include "Event.hpp"
#include "Audio.hpp"

namespace gameEngine_ns {

    class GameEngine {
        private:
            std::map<const std::string, sf::Texture *> _textures;
            std::map<const std::string, gameEngine_ns::object_ns::Sprite *> _sprites;
            std::map<const std::string, gameEngine_ns::object_ns::IObject *> _objects;
        public:
            /**
             * @brief Construct a new Game Engine object
             * 
             */
            GameEngine();
            /**
             * @brief Destroy the Game Engine object
             * 
             */
            ~GameEngine();
            gameEngine_ns::window_ns::Window *window;
            gameEngine_ns::event_ns::Event *event;
            gameEngine_ns::audio_ns::Audio *audio;
            /**
             * @brief Add an object with given id
             * 
             * @param id 
             * @param object 
             * @return  0 if everything is ok. -1 if an error occured.
             */
            int addObject(const std::string &id, gameEngine_ns::object_ns::IObject *object);
            // int addObject(const std::string &filePath, const std::string &id);
            /**
             * @brief Add a texture with given id
             * 
             * @param id 
             * @param filePath 
             * @return  0 if everything is ok. -1 if an error occured.
             */
            int addTexture(const std::string &id, const std::string &filePath);
            /**
             * @brief Add a sprite with given id
             * 
             * @param id 
             * @param sprite 
             * @return  0 if everything is ok. -1 if an error occured.
             */
            int addSprite(const std::string &id, gameEngine_ns::object_ns::Sprite *sprite);
            /**
             * @brief Get the Sprite object
             * 
             * @param id sprite id
             * @return gameEngine_ns::object_ns::Sprite* 
             */
            gameEngine_ns::object_ns::Sprite *getSprite(const std::string &id) const;
            // int loadFromConfigurationFile(const std::string &filePath);
            /**
             * @brief Create a Sprite object
             * 
             * @param textureId 
             * @param rectanglePositionsOnImage 
             * @param updateDelayMs 
             * @return gameEngine_ns::object_ns::Sprite* 
             */
            gameEngine_ns::object_ns::Sprite *createSprite(const std::string &textureId, const std::vector<gameEngine_ns::geometry_ns::Rectangle> rectanglePositionsOnImage, float updateDelayMs = -1);
            /**
             * @brief Create a Window object
             * 
             * @param vector winwow size
             */
            void createWindow(const gameEngine_ns::geometry_ns::Vector &vector);
            /**
             * @brief Get the all objects
             * 
             * @return const std::map<const std::string, gameEngine_ns::object_ns::IObject *> 
             */
            const std::map<const std::string, gameEngine_ns::object_ns::IObject *> getObjects() const;
            /**
             * @brief Get the Object
             * 
             * @param id object id
             * @return gameEngine_ns::object_ns::IObject* 
             */
            gameEngine_ns::object_ns::IObject *getObject(const std::string &id) const;
            /**
             * @brief Remove an object and free memory
             * 
             * @param id object id
             */
            void removeObject(const std::string &id);
    };
}
