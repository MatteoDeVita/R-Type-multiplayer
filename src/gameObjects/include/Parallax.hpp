/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Parallax
*/

#pragma once

#include <SFML/Graphics.hpp>

#include "Object.hpp"

class Parallax : public gameEngine_ns::object_ns::Object {
    public:
        Parallax();
        ~Parallax();
        Parallax(
            gameEngine_ns::object_ns::Sprite *sprite,
            const unsigned int &speed,
            const gameEngine_ns::geometry_ns::Vector &position = gameEngine_ns::geometry_ns::Vector()
        );
        /**
         * @brief Automaticly moove parallax object
         * 
         */
        void autoMoove();
        /**
         * @brief Automaticly moove parallax object from a given vector
         * 
         * @param vector 
         */
        void autoMoove(const gameEngine_ns::geometry_ns::Vector &vector);
        /**
         * @brief Set the parallax object speed
         * 
         * @param speed 
         */
        void setSpeed(const unsigned int &speed);
    protected:
    private:
        int _speed;
        sf::Clock *_mooveClock;
};
