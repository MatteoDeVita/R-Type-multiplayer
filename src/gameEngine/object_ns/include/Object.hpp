/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Object
*/

#pragma once

#include <map>
#include <string>

#include "Sprite.hpp"
#include "Vector.hpp"
#include "Sprite.hpp"
#include "IAction.hpp"

namespace gameEngine_ns {
    namespace object_ns {
        class Object {
            private:
                gameEngine_ns::object_ns::Sprite *_sprite;
                gameEngine_ns::geometry_ns::Vector _position;
                std::map<const std::string, gameEngine_ns::action_ns::IAction *> _actions;
            public:
                Object(gameEngine_ns::object_ns::Sprite *sprite, const gameEngine_ns::geometry_ns::Vector &position = gameEngine_ns::geometry_ns::Vector());
                ~Object();
                gameEngine_ns::geometry_ns::Vector getPos() const;
                void setPos(const gameEngine_ns::geometry_ns::Vector &vector);
                gameEngine_ns::object_ns::Sprite *getSprite() const;
                int addAction(const std::string &id, gameEngine_ns::action_ns::IAction *action);
                gameEngine_ns::action_ns::IAction *getAction(const std::string &id) const;
                std::map<const std::string, gameEngine_ns::action_ns::IAction *> getActions() const;
        }; 
    }
}
