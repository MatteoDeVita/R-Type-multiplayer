/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** IAction
*/

#pragma once

#include "Object.hpp"

namespace gameEngine_ns {
    namespace action_ns {
        class IAction {
            public:
                IAction(gameEngine_ns::object_ns::Object *related_object);
                ~IAction();
                virtual void setObject() = 0;
            protected:
                gameEngine_ns::object_ns::Object *_related_object;
        };
    }
}

