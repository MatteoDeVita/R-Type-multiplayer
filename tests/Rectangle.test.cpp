/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** Rectangle.test
*/

#include "Rectangle.hpp"

#include <criterion/criterion.h>

Test(RectangleTests, Constructors)
{
    gameEngine_ns::geometry_ns::Rectangle rec1;
    gameEngine_ns::geometry_ns::Rectangle rec2(1, 7, 8, 4);

    cr_expect(
        rec1.origin.x == 0 &&
        rec1.origin.y == 0 &&
        rec1.size.x == 0 &&
        rec1.size.y == 0,
        "Constructor without parameters"
    );
    cr_expect(
        rec2.origin.x == 1 &&
        rec2.origin.y == 7 &&
        rec2.size.x == 8 &&
        rec2.size.y == 4,
        "Constructor with paramters"
    );
}

Test(RectangleTests, Operations)
{
    gameEngine_ns::geometry_ns::Rectangle rec1(1, 2, 3, 1);
    gameEngine_ns::geometry_ns::Rectangle rec2(5, 3, 3, 4);

    gameEngine_ns::geometry_ns::Rectangle testRect = rec1 + rec2;

    cr_expect(
        testRect.origin.x == 6 &&
        testRect.origin.y == 5 &&
        testRect.size.x == 6 &&
        testRect.size.y == 5,
        "Rectangle addition"
    );
    
    testRect = rec1 - rec2;

    cr_expect(
        testRect.origin.x == -4 &&
        testRect.origin.y == -1 &&
        testRect.size.x == 0 &&
        testRect.size.y == -3,
        "Rectangle substraction"
    );

    testRect = rec1 * rec2;

    cr_expect(
        testRect.origin.x == 5 &&
        testRect.origin.y == 6 &&
        testRect.size.x == 9 &&
        testRect.size.y == 4,
        "Rectangle multiplication"
    );

    testRect = rec1 / rec2;

    cr_expect(
        testRect.size.x == 1 &&
        testRect.size.y == 0.25,
        "Rectangle division"
    );

    cr_expect(
        rec1 == gameEngine_ns::geometry_ns::Rectangle(1, 2, 3, 1),
        "Rectangle equality"
    );
}

Test(RectangleTests, GeometricMethods)
{
    gameEngine_ns::geometry_ns::Rectangle rec(5, 6, 7, 2);

    cr_expect(
        rec.area() == 14,
        "Rectangle area"
    );
    cr_expect(
        rec.perimeter() == 20,
        "Rectangle perimeter"
    );
}
