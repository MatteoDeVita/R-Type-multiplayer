/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Vector.test
*/

#include "Vector.hpp"

#include <criterion/criterion.h>

Test(VectorTests, Constructor)
{
    gameEngine_ns::geometry_ns::Vector vec(5, 2);

    cr_expect(
        vec.x == 5 &&
        vec.y == 2,
        "Vector constructor"
    );
}

Test(VectorTests, Operations)
{
    gameEngine_ns::geometry_ns::Vector vec1(5, 2);
    gameEngine_ns::geometry_ns::Vector vec2(3, 4);
    
    gameEngine_ns::geometry_ns::Vector testVec = vec1 + vec2;

    cr_expect(
        testVec.x = 8 &&
        testVec.y == 6,
        "Vector addition"
    );

    testVec = vec1 - vec2;

    cr_expect(
        testVec.x = 2 &&
        testVec.y == -2,
        "Vector substraction"
    );

    testVec = vec1 * vec2;

    cr_expect(
        testVec.x = 15 &&
        testVec.y == 8,
        "Vector multiplication"
    );

    testVec = vec1 / vec2;

    cr_expect(
        testVec.x = (5/3) &&
        testVec.y == 0.5,
        "Vector division"
    );

    cr_expect(
        vec1 == gameEngine_ns::geometry_ns::Vector(5, 2),
        "Vector equality"
    );
}