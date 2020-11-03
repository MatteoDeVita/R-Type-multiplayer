/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** GameEngine.test
*/

#include <criterion/criterion.h>
#include "GameEngine.hpp"

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

}

Test(GameEngineTests, addSprite)
{

}