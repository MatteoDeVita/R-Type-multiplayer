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
#include <iostream>


Test(GameEngineTests, addTexture)
{
    gameEngine_ns::GameEngine gameEngine;

    cr_expect(
        gameEngine.addTexture("id-monster-test-1", "../assets/monsters/monster1/assets/texture.gif") == 0,
        "Add Texture with an existing texture"
    );
    cr_expect(
        gameEngine.addTexture("id-monster-test-2", "../assets/monsters/monster1/assets/azazazzazad.gif") != 0,
        "Texture that doesn't exist"
    );
    cr_expect(
        gameEngine.addTexture("id-monster-test-1", "../assets/monsters/monster2/assets/texture.gif") != 0,
        "ID that already exists"
    );
}

Test(GameEngineTests, createSprite)
{
    gameEngine_ns::GameEngine gameEngine;

    cr_expect(
        gameEngine.addTexture("id-monster-test-1", "../assets/monsters/monster1/assets/texture.gif") == 0,
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
    gameEngine_ns::GameEngine gameEngine;

    cr_expect(
        gameEngine.addTexture("id-monster-test-1", "../assets/monsters/monster1/assets/texture.gif") == 0,
        "Sprite test create Texturetexture with an existing texture for addSprite test"
    );
    std::vector<gameEngine_ns::geometry_ns::Rectangle> rectanglePositionsOnImage;
    gameEngine_ns::object_ns::Sprite *sprite = gameEngine.createSprite("id-monster-test-1", rectanglePositionsOnImage);
    cr_expect(
        sprite != nullptr,
        "Sprite creation with existing texture ID for addSprite test"
    );
    cr_expect(
        gameEngine.addSprite("sprite-test-1", sprite) == 0,
        "Add basic existing sprite"
    );
    cr_expect(
        gameEngine.addSprite("sprite-test-1", sprite) != 0,
        "Add sprite with an existing id"
    );
}

Test(GameEngineTests, getSprite)
{
    gameEngine_ns::GameEngine gameEngine;

    cr_expect(
        gameEngine.addTexture("id-monster-test-1", "../assets/monsters/monster1/assets/texture.gif") == 0,
        "Sprite test create Texturetexture with an existing texture for getSprite test"
    );
    std::vector<gameEngine_ns::geometry_ns::Rectangle> rectanglePositionsOnImage;
    gameEngine_ns::object_ns::Sprite *sprite = gameEngine.createSprite("id-monster-test-1", rectanglePositionsOnImage);
    gameEngine_ns::object_ns::Sprite *sprite2 = gameEngine.createSprite("id-monster-test-1", rectanglePositionsOnImage);

    cr_expect(
        sprite != nullptr,
        "Sprite creation with existing texture ID for getSprite test"
    );
    cr_expect(
        sprite2 != nullptr,
        "Sprite2 creation with existing texture ID for getSprite test"
    );

    cr_expect(
        gameEngine.addSprite("sprite-test-1", sprite) == 0,
        "Add basic existing sprite for getSprite test"
    );

    cr_expect(
        gameEngine.addSprite("sprite-test-2", sprite2) == 0,
        "Add basic existing sprite for getSprite test"
    );

    cr_expect(
        gameEngine.getSprite("sprite-test-1") == sprite,
        "Get an existing sprite"
    );

    cr_expect(
        gameEngine.getSprite("sprite-test-2") == sprite2,
        "Get an second existing sprite"
    );

    cr_expect(
        gameEngine.getSprite("sprite-test-3") == nullptr,
        "Get an non existing sprite"
    );
}

Test(GameEngineTests, addObject)
{
    gameEngine_ns::GameEngine gameEngine;

    cr_expect(
        gameEngine.addTexture("id-monster-test-1", "../assets/monsters/monster1/assets/texture.gif") == 0,
        "Sprite test create Texturetexture with an existing texture for addSprite test"
    );
    std::vector<gameEngine_ns::geometry_ns::Rectangle> rectanglePositionsOnImage;
    gameEngine_ns::object_ns::Sprite *sprite = gameEngine.createSprite("id-monster-test-1", rectanglePositionsOnImage);
    cr_expect(
        sprite != nullptr,
        "Sprite creation with existing texture ID for addObject test"
    );
    cr_expect(
        gameEngine.addSprite("sprite-test-1", sprite) == 0,
        "Add basic existing sprite for addObject test"
    );   
    gameEngine_ns::object_ns::Object *object = new gameEngine_ns::object_ns::Object(sprite, gameEngine_ns::geometry_ns::Vector());
    
    cr_expect(
        gameEngine.addObject("object-test-id-1", object) == 0,
        "Add basic object"
    );
    cr_expect(
        gameEngine.addObject("object-test-id-1", object) == -1,
        "Add an already existing object"
    );
}
