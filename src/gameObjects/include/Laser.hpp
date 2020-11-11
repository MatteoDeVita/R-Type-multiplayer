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
        void autoMoove();
        bool isFromMonster() const;
    private:
        int _yValue;
        int _xValue;
        sf::Clock *_laserClock;
        bool _leftToRight;
};
