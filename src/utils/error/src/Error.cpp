/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Error
*/

#include "Error.hpp"

/**
 * @brief Construct a new Error:: Error object
 * 
 * @param message messsage to display
 */

Error::Error(const std::string &message) throw()
{
    this->_message = message;
}

/**
 * @brief Destroy the Error:: Error object
 * 
 */
Error::~Error()
{
}

/**
 * @brief Print the error message
 * 
 * @return const char* 
 */
const char *Error::what() const throw()
{
    return this->_message.c_str();
    exit(84);
}