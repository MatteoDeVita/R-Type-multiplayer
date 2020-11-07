/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Action
*/

#pragma once

#include "Object.hpp"
#include "IAction.hpp"

namespace gameEngine_ns {
    namespace action_ns {
        class Action : public IAction {
            public:
                Action();
                Action(gameEngine_ns::object_ns::Object *relateObject);
                virtual ~Action();
                void setActionObject(gameEngine_ns::object_ns::Object *actionObject);
                void setRelatedObject(gameEngine_ns::object_ns::Object *relatedObject);
                virtual void enable() = 0;
                virtual void disable() = 0;
                bool isEnable();
        };
    }
}

