/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** GameEngine.test
*/

#include "GameEngine.hpp"
#include "Rectangle.hpp"

#include <criterion/criterion.h>
#include <vector>

Test(GameEngineTests, addTexture)
{
    gameEngine_ns::GameEngine gameEngine;

    cr_expect(
        gameEngine.addTexture("../assets/monsters/monster1/assets/texture.gif", "id-monster-test-1") == 0,
        "Add Texture with an existing texture"
    );
    cr_expect(
        gameEngine.addTexture("../assets/monsters/monster1/assets/azazazzazad.gif", "id-monster-test-2") != 0,
        "Texture that doesn't exist"
    );
    cr_expect(
        gameEngine.addTexture("../assets/monsters/monster2/assets/texture.gif", "id-monster-test-1") != 0,
        "ID that already exists"
    );
}

Test(GameEngineTests, createSprite)
{
    gameEngine_ns::GameEngine gameEngine;

    cr_expect(
        gameEngine.addTexture("../assets/monsters/monster1/assets/texture.gif", "id-monster-test-1") == 0,
        "Sprite test create Texturetexture with an existing texture"
    );
    std::vector<gameEngine_ns::geometry_ns::Rectangle> rectanglePositionsOnImage;
    gameEngine_ns::object_ns::Sprite *sprite = gameEngine.createSprite("id-monster-test-1", rectanglePositionsOnImage);

    cr_expect(
        sprite != nullptr,
        "Sprite creation with existing texture ID"
    );
    sprite = gameEngine.createSprite("WRONG-ID", rectanglePositionsOnImage);
    cr_expect(
        sprite == nullptr,
        "Sprite creation with wrong texture ID"
    );
}

Test(GameEngineTests, addSprite)
{

}