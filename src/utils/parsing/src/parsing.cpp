/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** parsing
*/

#include <algorithm>
#include <locale>

#include "parsing.hpp"

bool parsing::strIsNumber(const std::string &str) {
    return (
        !str.empty() &&
        std::find_if(str.begin(), str.end(), [](unsigned char c) {
            return !std::isdigit(c);
        }
    ) == str.end());
}
