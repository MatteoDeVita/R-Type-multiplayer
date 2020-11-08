/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** IAction
*/

#pragma once

// #include "Object.hpp"

namespace gameEngine_ns {

    namespace geometry_ns {
        class Vector;
    }

    namespace object_ns {
        class Object;
    }

    namespace action_ns {
        class IAction {
            public:
                IAction();
                IAction(gameEngine_ns::object_ns::Object *relatedObject);
                ~IAction();
                virtual void setActionObject(gameEngine_ns::object_ns::Object *object) = 0;
                virtual void setRelatedObject(gameEngine_ns::object_ns::Object *relatedObject) = 0;
                virtual void act() = 0;
                virtual void disable() = 0;
                virtual bool isEnable() = 0;
                // virtual void setVector(const gameEngine_ns::geometry_ns::Vector &vector = gameEngine_ns::geometry_ns::Vector(1, 1)) = 0;
            protected:
                gameEngine_ns::object_ns::Object *_relatedObject;
                gameEngine_ns::object_ns::Object *_actionObject;
                bool _isEnable;
        };
    }
}
