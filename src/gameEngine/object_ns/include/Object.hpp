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
#include "IObject.hpp"

namespace gameEngine_ns {
    namespace object_ns {
        class Object : public IObject {
            private:
                gameEngine_ns::object_ns::Sprite *_sprite;
                gameEngine_ns::geometry_ns::Vector _position;
            public:
                Object();
                Object(gameEngine_ns::object_ns::Sprite *sprite, const gameEngine_ns::geometry_ns::Vector &position = gameEngine_ns::geometry_ns::Vector());
                ~Object();
                void autoUpdatePos();
                gameEngine_ns::geometry_ns::Vector getPos() const;
                void setPos(const gameEngine_ns::geometry_ns::Vector &vector);
                void moove(const gameEngine_ns::geometry_ns::Vector &vector);
                gameEngine_ns::object_ns::Sprite *getSprite() const;
                void autoMoove();
                void autoMoove(const gameEngine_ns::geometry_ns::Vector &vector);
                void setSpeed(const unsigned int &speed);
                bool isFromMonster() const;
                bool isActive();
                void setActive(const bool &active = true);
                void damage();
                int getHp() const;
                sf::Clock *activeClock;
        };
    }
}
