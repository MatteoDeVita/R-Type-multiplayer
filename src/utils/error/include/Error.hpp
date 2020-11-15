/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Error
*/

#pragma once

#include <exception>
#include <string>

class Error : public std::exception {
    private:
        std::string _message;
    public:
        /**
         * @brief Construct a new Error object
         * 
         * @param message 
         */
        Error(const std::string &message) throw();
        virtual ~Error();
        virtual const char* what() const throw();
};
