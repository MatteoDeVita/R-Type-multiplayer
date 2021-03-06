/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Laser
*/

#pragma once

#include "Object.hpp"

class Laser : public gameEngine_ns::object_ns::Object {
    public:
        Laser();
        Laser(
            gameEngine_ns::object_ns::Sprite *sprite,
            const bool &leftToRight,
            const gameEngine_ns::geometry_ns::Vector &position = gameEngine_ns::geometry_ns::Vector()
        );
        ~Laser();
        /**
         * @brief auto moove laser
         * 
         */
        void autoMoove();
        /**
         * @brief 
         * 
         * @return true if the laser is from a monster
         * @return false if the laser is from a player
         */
        bool isFromMonster() const;
    private:
        int _yValue;
        int _xValue;
        sf::Clock *_laserClock;
        bool _leftToRight;
};
