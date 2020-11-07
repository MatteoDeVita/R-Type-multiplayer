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
                IAction();
                IAction(gameEngine_ns::object_ns::Object *relatedObject);
                ~IAction();
                virtual void setActionObject(gameEngine_ns::object_ns::Object *object) = 0;
                virtual void setRelatedObject(gameEngine_ns::object_ns::Object *relatedObject) = 0;
                virtual void enable() = 0;
                virtual void disable() = 0;
                virtual bool isEnable() = 0;
            protected:
                gameEngine_ns::object_ns::Object *_relatedObject;
                gameEngine_ns::object_ns::Object *_actionObject;
                bool _isEnable;
        };
    }
}
