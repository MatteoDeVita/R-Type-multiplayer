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
                /**
                * @brief Construct a new Object object
                * 
                */
                Object();
                /**
                 * @brief Construct a new Object object
                 * 
                 * @param sprite 
                 * @param position 
                 */
                Object(gameEngine_ns::object_ns::Sprite *sprite, const gameEngine_ns::geometry_ns::Vector &position = gameEngine_ns::geometry_ns::Vector());
                /**
                 * @brief Destroy the Object object
                 * 
                 */
                ~Object();
                /**
                 * @brief automaticly update object position
                 * 
                 */
                void autoUpdatePos();
                /**
                 * @brief Get the object position
                 * 
                 * @return gameEngine_ns::geometry_ns::Vector 
                 */
                gameEngine_ns::geometry_ns::Vector getPos() const;
                /**
                 * @brief Set the object position
                 * 
                 * @param vector position
                 */
                void setPos(const gameEngine_ns::geometry_ns::Vector &vector);
                /**
                 * @brief Moove object position with the given moove vector
                 * 
                 * @param vector moove vector
                 */
                void moove(const gameEngine_ns::geometry_ns::Vector &vector);
                /**
                 * @brief Get the associated sprite object
                 * 
                 * @return gameEngine_ns::object_ns::Sprite* 
                 */
                gameEngine_ns::object_ns::Sprite *getSprite() const;
                /**
                 * @brief automaticly moove
                 * 
                 */
                void autoMoove();
                /**
                 * @brief automaticly moove with the given vector
                 * 
                 * @param vector 
                 */
                void autoMoove(const gameEngine_ns::geometry_ns::Vector &vector);
                /**
                 * @brief Set the object speed
                 * 
                 * @param speed 
                 */
                void setSpeed(const unsigned int &speed);
                /**
                 * @brief Tell if the object is comming from a monster
                 * 
                 * @return true if the object is comming from a monster
                 * @return false otherwise
                 */
                bool isFromMonster() const;
                /**
                 * @brief Tell if the oject is active
                 * 
                 * @return true if the obect is active
                 * @return false otherwise
                 */
                bool isActive();
                /**
                 * @brief Set if the object is active or not
                 * 
                 * @param active 
                 */
                void setActive(const bool &active = true);
                /**
                 * @brief Take damage
                 * 
                 */
                void damage();
                /**
                 * @brief Get the object current hp
                 * 
                 * @return int HP
                 */
                int getHp() const;
                sf::Clock *activeClock;
        };
    }
}
