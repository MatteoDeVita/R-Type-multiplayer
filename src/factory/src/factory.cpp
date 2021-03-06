/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui
** File description:
** factory
*/

#include <iostream>
#include <string>
#include <sstream>
#include <time.h>

#include "factory.hpp"
#include "Error.hpp"
#include "Vector.hpp"
#include "Monster.hpp"
#include "Audio.hpp"
#include "FX.hpp"
#include "Music.hpp"
#include "Player.hpp"
#include "parsing.hpp"
#include "Laser.hpp"
#include "Parallax.hpp"
#include "Explosion.hpp"

void factory_ns::loadMonsterTextures(gameEngine_ns::GameEngine *gameEngine)
{
    if (gameEngine->addTexture("monster1-texture", "../../assets/monsters/monster1.gif") != 0)
        throw Error("Can't load texture monster1.gif");
    if (gameEngine->addTexture("monster2-texture", "../../assets/monsters/monster2.gif") != 0)
        throw Error("Can't load texture monster2.gif");
    if (gameEngine->addTexture("monster3-texture", "../../assets/monsters/monster3.gif") != 0)
        throw Error("Can't load texture monster3.gif");
    if (gameEngine->addTexture("monster4-texture", "../../assets/monsters/monster4.gif") != 0)
        throw Error("Can't load texture monster4.gif");
    if (gameEngine->addTexture("monster5-texture", "../../assets/monsters/monster5.gif") != 0)
        throw Error("Can't load texture monster5.gif");
    if (gameEngine->addTexture("monster6-texture", "../../assets/monsters/monster6.gif") != 0)
        throw Error("Can't load texture monster6.gif");
    if (gameEngine->addTexture("monster7-texture", "../../assets/monsters/monster7.png") != 0)
        throw Error("Can't load texture monster7.gif");
    if (gameEngine->addTexture("monster8-texture", "../../assets/monsters/monster8.gif") != 0)
        throw Error("Can't load texture monster8.gif");  
}

void factory_ns::loadPlayerTextures(gameEngine_ns::GameEngine *gameEngine)
{
    if (gameEngine->addTexture("player1-texture", "../../assets/player/player1.gif") != 0)
        throw Error("Can't load texture player1.gif");
    if (gameEngine->addTexture("player2-texture", "../../assets/player/player2.gif") != 0)
        throw Error("Can't load texture player2.gif");
    if (gameEngine->addTexture("player3-texture", "../../assets/player/player3.gif") != 0)
        throw Error("Can't load texture player3.gif");
    if (gameEngine->addTexture("player4-texture", "../../assets/player/player4.gif") != 0)
        throw Error("Can't load texture player4.gif");
}

void factory_ns::loadEnvironment(gameEngine_ns::GameEngine *gameEngine)
{
    if (gameEngine->addTexture("background-texture1", "../../assets/environment/Nebula_Red.png") != 0)
        std::cerr << "Can't load texture Nebula_Red.png" << std::endl;
    std::vector<gameEngine_ns::geometry_ns::Rectangle> backgroundVec;
    backgroundVec.push_back(gameEngine_ns::geometry_ns::Rectangle(0, 0, 1920, 1080));
    gameEngine_ns::object_ns::Sprite *backgroundSprite = gameEngine->createSprite(
        "background-texture1",
        backgroundVec
    );
    if (backgroundSprite == nullptr)
        std::cerr << "Can't load sprite" << std::endl;
    backgroundSprite->getSFMLSprite()->scale(
        gameEngine_ns::geometry_ns::Vector(
            0.833, 0.833
        ).toSfVector2f()
    );
    if (gameEngine->addSprite("background-sprite", backgroundSprite) != 0)
        std::cerr << "Can't add sprite" << std::endl;
    gameEngine_ns::object_ns::Object *backgroundObject = new Parallax(
        backgroundSprite,
        1,
        gameEngine_ns::geometry_ns::Vector()
    );
    if (backgroundObject == nullptr)
        std::cerr << "Can't create object" << std::endl;
    if (gameEngine->addObject("background-object1", backgroundObject) != 0)
        std::cerr << "Can't add object" << std::endl;

    if (gameEngine->addTexture("background-texture2", "../../assets/environment/Stars Small_1.png") != 0)
        std::cerr << "Can't load texture Stars Small_1.png" << std::endl;
    if (gameEngine->addTexture("background-texture3", "../../assets/environment/Stars Small_2.png") != 0)
        std::cerr << "Can't load texture Stars Small_2.png" << std::endl;
    if (gameEngine->addTexture("background-texture4", "../../assets/environment/Stars-Big_1_1_PC.png") != 0)
        std::cerr << "Can't load texture Stars-Big_1_1_PC.png" << std::endl;
    if (gameEngine->addTexture("background-texture5", "../../assets/environment/Stars-Big_1_2_PC.png") != 0)
        std::cerr << "Can't load texture Stars-Big_1_2_PC.png" << std::endl;
    gameEngine_ns::object_ns::Sprite *backgroundSprite2 = gameEngine->createSprite("background-texture2", backgroundVec);
    gameEngine_ns::object_ns::Sprite *backgroundSprite3 = gameEngine->createSprite("background-texture3", backgroundVec);
    gameEngine_ns::object_ns::Sprite *backgroundSprite4 = gameEngine->createSprite("background-texture4", backgroundVec);
    gameEngine_ns::object_ns::Sprite *backgroundSprite5 = gameEngine->createSprite("background-texture5", backgroundVec);
    gameEngine_ns::object_ns::Sprite *backgroundSprite6 = gameEngine->createSprite("background-texture2", backgroundVec);
    gameEngine_ns::object_ns::Sprite *backgroundSprite7 = gameEngine->createSprite("background-texture3", backgroundVec);
    gameEngine_ns::object_ns::Sprite *backgroundSprite8 = gameEngine->createSprite("background-texture4", backgroundVec);
    gameEngine_ns::object_ns::Sprite *backgroundSprite9 = gameEngine->createSprite("background-texture5", backgroundVec);

    gameEngine_ns::object_ns::Object *backgroundObject2 = new Parallax(backgroundSprite2, 2, gameEngine_ns::geometry_ns::Vector());
    gameEngine_ns::object_ns::Object *backgroundObject3 = new Parallax(backgroundSprite3, 3, gameEngine_ns::geometry_ns::Vector());
    gameEngine_ns::object_ns::Object *backgroundObject4 = new Parallax(backgroundSprite4, 5, gameEngine_ns::geometry_ns::Vector());
    gameEngine_ns::object_ns::Object *backgroundObject5 = new Parallax(backgroundSprite5, 7, gameEngine_ns::geometry_ns::Vector());
    gameEngine_ns::object_ns::Object *backgroundObject6 = new Parallax(backgroundSprite6, 2, gameEngine_ns::geometry_ns::Vector(1600, 0));
    gameEngine_ns::object_ns::Object *backgroundObject7 = new Parallax(backgroundSprite7, 3, gameEngine_ns::geometry_ns::Vector(1600, 0));
    gameEngine_ns::object_ns::Object *backgroundObject8 = new Parallax(backgroundSprite8, 5, gameEngine_ns::geometry_ns::Vector(1600, 0));
    gameEngine_ns::object_ns::Object *backgroundObject9 = new Parallax(backgroundSprite9, 7, gameEngine_ns::geometry_ns::Vector(1600, 0));
    gameEngine->addObject("background-object2", backgroundObject2);
    gameEngine->addObject("background-object3", backgroundObject3);
    gameEngine->addObject("background-object4", backgroundObject4);
    gameEngine->addObject("background-object5", backgroundObject5);
    gameEngine->addObject("background-object6", backgroundObject6);
    gameEngine->addObject("background-object7", backgroundObject7);
    gameEngine->addObject("background-object8", backgroundObject8);
    gameEngine->addObject("background-object9", backgroundObject9);
    
}

void factory_ns::loadLasersTextures(gameEngine_ns::GameEngine *gameEngine)
{
    if (gameEngine->addTexture("lasers-texture", "../../assets/bullets/lasers.png") != 0)
        std::cerr << "Can't load texture lasers.png" << std::endl;
}

void factory_ns::loadMusic(gameEngine_ns::GameEngine *gameEngine)
{
    gameEngine_ns::audio_ns::Music *music = new gameEngine_ns::audio_ns::Music("../../assets/sound/music.wav");
    if (music == nullptr)
        std::cerr << "Can't load music" << std::endl;
    music->setLoop();
    music->setVolume();    
    if (gameEngine->audio->addMusic("music-main", music) != 0)
        std::cerr << "Can't add music" << std::endl;
}

void factory_ns::loadLaserObjects(gameEngine_ns::GameEngine *gameEngine, const bool &leftToRight)
{
    for (int i = 1; i <= 10; i++) {
        addAndCreateLaser(
            gameEngine,
            gameEngine_ns::geometry_ns::Vector(-100, 0),
            i,
            leftToRight,
            1
        );
    }
    for (int i = 1; i <= 10; i++) {
        addAndCreateLaser(
            gameEngine,
            gameEngine_ns::geometry_ns::Vector(-100, 0),
            i,
            leftToRight,
            2
        );
    }
    for (int i = 1; i <= 10; i++) {
        addAndCreateLaser(
            gameEngine,
            gameEngine_ns::geometry_ns::Vector(-100, 0),
            i,
            leftToRight,
            3
        );
    }
}

void factory_ns::loadExplosionTexture(gameEngine_ns::GameEngine *gameEngine)
{
    if (gameEngine->addTexture("boumboum-texture", "../../assets/boum/boumboum.gif") != 0)
        std::cerr << "Can't load texture boumboum.gif" << std::endl;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster1Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 0, 64, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(70, 0, 56, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(196, 0, 64, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(262, 0, 64, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(333, 0, 52, 132));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(457, 0, 64, 132));
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster2Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 1, 63, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(66, 1, 63, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(131, 1, 63, 48));
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster3Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 1, 32, 31));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(34, 1, 32, 31));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(67, 1, 32, 31));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(101, 1, 32, 31));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(134, 1, 32, 31));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(167, 1, 32, 31));
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster4Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(5, 6, 22, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(38, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(71, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(104, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(137, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(170, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(203, 6, 21, 24));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(236, 6, 21, 24));
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster5Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 2, 31, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(34, 2, 32, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(37, 2, 32, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(67, 2, 32, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(100, 2, 31, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(133, 2, 31, 25));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(166, 2, 32, 25));
   
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster6Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(34, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(34, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(67, 6, 31, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(67, 6, 31, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(100, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(133, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(133, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(166, 6, 32, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(199, 6, 31, 22));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(232, 6, 32, 22));
   
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster7Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 9, 48, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 74, 48, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 139, 48, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 204, 48, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 204, 48, 48));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(9, 269, 48, 48));
    
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonster8Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 102, 32, 30));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(35, 102, 32, 30));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(69, 102, 32, 30));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(103, 102, 29, 30));
    
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getPlayerVec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 3, 32, 14));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(34, 3, 32, 13));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(67, 3, 32, 12));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(100, 3, 32, 13));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(133, 2, 32, 14));
    
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getLaser1Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(2, 0, 64, 14));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(67, 0, 64, 14));
    
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getLaser2Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(2, 34, 32, 10));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(35, 33, 32, 12));
    
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getLaser3Vec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(2, 61, 16, 12));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(19, 63, 16, 8));
    
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getLaser1InverseVec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 15, 64, 14));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(66, 15, 64, 14));
    
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getLaser2InverseVec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 46, 32, 12));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(34, 47, 32, 10));
    
    return vec;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getLaser3InverseVec()
{
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 76, 16, 8));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(18, 74, 16, 12));
    
    return vec;
}

void factory_ns::updateObjectsFromNetworkData(gameEngine_ns::GameEngine *gameEngine, const std::string &data)
{
    std::stringstream ss(data);
    std::string tmp;
    std::vector<std::string> ids;
    std::size_t firstSpaceIndex = 0;
    std::size_t secondSpaceIndex = 0;
    std::string x_str, y_str, id_str;
    float x = 0;
    float y = 0;

    while (std::getline(ss, tmp, '|')) {
        if (tmp == "" || tmp.length() <= 5)
            continue;
        
        // std::cout << "TMP = " << tmp << '|' << std::endl;
        firstSpaceIndex = tmp.find(" ");
        x_str = tmp.substr(0, firstSpaceIndex);

        secondSpaceIndex = tmp.find(" ", x_str.length() + 1);
        y_str = tmp.substr(firstSpaceIndex + 1, secondSpaceIndex - firstSpaceIndex - 1);

        id_str = tmp.substr(secondSpaceIndex + 1, tmp.length() - firstSpaceIndex - 1);
       
        ids.push_back(id_str);

        if (!parsing::strIsNumber(x_str) || !parsing::strIsNumber(y_str))
            continue;
        x = std::stoi(x_str);
        y = std::stoi(y_str);


        if (gameEngine->getObject(id_str) == nullptr) {
            if (id_str.substr(0, 6) == "player") {
                factory_ns::addAndCreatePlayer(
                    gameEngine,
                    std::stoi(id_str.substr(6, 7)),
                    gameEngine_ns::geometry_ns::Vector(x, y)
                );                
            }
            else if (id_str.substr(0, id_str.find('-')).substr(0, 7) == "monster") {
                factory_ns::addAndCreateMonster(
                    gameEngine,
                    std::stoi(id_str.substr(7, 1)),
                    gameEngine_ns::geometry_ns::Vector(x, y)
                );
            }            
        }
        else {
            gameEngine->getObject(id_str)->setPos(gameEngine_ns::geometry_ns::Vector(x, y));
        }
    }
    for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : gameEngine->getObjects()) {
        if (pair.first.substr(0, 7) == "monster" && std::find(ids.begin(), ids.end(), pair.first) == ids.end()) {
            gameEngine->removeObject(pair.first);
        }
    }
}

int factory_ns::getMonsterHp(const int &monsterNb)
{
    switch (monsterNb) {
        case 1:
            return 5;
        case 2:
            return 4;
        case 3:
            return 2;
        case 4:
            return 1;
        case 5:
            return 1;
        case 6:
            return 1;
        case 7:
            return 3;
        case 8:
            return 2;
        default:
            throw Error("Wrong monster number.");
    }
}

void factory_ns::addAndCreateMonster(gameEngine_ns::GameEngine *gameEngine, const int &monsterNb, const gameEngine_ns::geometry_ns::Vector &position)
{
    std::string timestamp(std::to_string(time(nullptr)));
    gameEngine_ns::object_ns::Sprite *sprite = gameEngine->createSprite(
        std::string("monster" + std::to_string(monsterNb) + "-texture"),
        factory_ns::getMonsterVec(monsterNb),
        (float ((rand() % 100) + 100))
    );
    if (sprite == nullptr)
        std::cerr << "Can't load sprite" << std::endl;
    if (gameEngine->addSprite(std::string("sprite-" + timestamp + std::to_string(rand() % 100000)),sprite) != 0)
        std::cerr << "Can't add monster sprite" << std::endl;
    Monster *monster = new Monster(
        sprite,
        getMonsterHp(monsterNb),
        position
    );
    monster->setPos(position);
    if (monster == nullptr)
        std::cerr << "Can't create object" << std::endl;
    if (gameEngine->addObject(std::string("monster" + std::to_string(monsterNb) + "-" + timestamp), monster) != 0)
        std::cerr << "Can't add monster object" << std::endl;
}

void factory_ns::addAndCreatePlayer(gameEngine_ns::GameEngine *gameEngine, const int &playerNb, const gameEngine_ns::geometry_ns::Vector &position)
{
    std::string timestamp(std::to_string(time(nullptr)));
        gameEngine_ns::object_ns::Sprite *sprite = gameEngine->createSprite(
        std::string("player" + std::to_string(playerNb) + "-texture"),
        factory_ns::getPlayerVec(),
        75
    );
    if (sprite == nullptr)
        std::cerr << "Can't load sprite" << std::endl;
    if (gameEngine->addSprite(std::string("sprite" + std::to_string(playerNb) + "-" + timestamp + std::to_string(rand() % 100000)), sprite) != 0)
        std::cerr << "Can't add player sprite" << std::endl;
    Player *player = new Player(
        sprite,
        position
    );
    player->setPos(position);
    player->getSprite()->getSFMLSprite()->scale(gameEngine_ns::geometry_ns::Vector(2, 2).toSfVector2f());
    if (player == nullptr)
        std::cerr << "Can't create object" << std::endl;
    if (gameEngine->addObject(std::string("player" + std::to_string(playerNb) + "-" + timestamp), player) != 0)
        std::cerr << "Can't add player object" << std::endl;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getMonsterVec(const int &monsterNb)
{
    switch (monsterNb) {
        case 1:
            return getMonster1Vec();
        case 2:
            return getMonster2Vec();
        case 3:
            return getMonster3Vec();
        case 4:
            return getMonster4Vec();
        case 5:
            return getMonster5Vec();
        case 6:
            return getMonster6Vec();
        case 7:
            return getMonster7Vec();
        case 8:
            return getMonster8Vec();
        default:
            throw Error("Wrong monster number (must be beetween 1 and 8).");
    }
}

std::vector<gameEngine_ns::object_ns::IObject *> factory_ns::getPlayers(const gameEngine_ns::GameEngine &gameEngine)
{
    std::vector<gameEngine_ns::object_ns::IObject *> players;

    for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : gameEngine.getObjects())
        if (pair.first.substr(0, 6) == "player")
            players.push_back(pair.second);
    return players;
}

void factory_ns::addAndCreateLaser(gameEngine_ns::GameEngine *gameEngine, const gameEngine_ns::geometry_ns::Vector &position, const int &laserNb, const bool &leftToRight, const int &laserType)
{
    std::string timestamp(std::to_string(time(nullptr)));
        gameEngine_ns::object_ns::Sprite *sprite = gameEngine->createSprite(
        std::string("lasers-texture"),
        getLaserVec(leftToRight, laserType),
        20
    );
    std::string id("");
    id += "laser";
    id += std::to_string(laserType);
    id += leftToRight ? "-player-" : "-monster-";
    id += std::to_string(laserNb);
    if (sprite == nullptr)
        std::cerr << "Can't load sprite" << std::endl;
    if (gameEngine->addSprite(std::string("sprite-" + id), sprite) != 0)
        std::cerr << "Can't add laser sprite" << std::endl;

    Laser *laser = new Laser(
        sprite,
        leftToRight,
        position
    );
    laser->setPos(position);
    if (laser == nullptr)
        std::cerr << "Can't create object" << std::endl;
    if (gameEngine->addObject(id, laser) != 0)
        std::cerr << "Can't add laser object" << std::endl;
}

std::vector<gameEngine_ns::geometry_ns::Rectangle> factory_ns::getLaserVec(const bool leftToRight, const int &laserType)
{
    if (leftToRight) {
        switch (laserType) {
            case 1:
                return getLaser1Vec();
            case 2:
                return getLaser2Vec();
            case 3:
                return getLaser3Vec();
            default:
                throw Error("Wrong laser number");
        }
    }
    else {
        switch (laserType) {
            case 1:
                return getLaser1InverseVec();
            case 2:
                return getLaser2InverseVec();
            case 3:
                return getLaser3InverseVec();
            default:
                throw Error("Wrong laser number");
        }
    }
}

std::vector<gameEngine_ns::object_ns::IObject *> factory_ns::getValidLasers(const gameEngine_ns::GameEngine &gameEngine, const bool &leftToRight)
{
    std::vector<gameEngine_ns::object_ns::IObject *> vec;
    const std::string validStr = leftToRight ? "player" : "monste";

    for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : gameEngine.getObjects()) {
        if (
            pair.first.substr(0, 5) == "laser" &&
            pair.first.substr(7, 6) == validStr &&
            pair.second->getPos().x < 0 
        ) {
            vec.push_back(pair.second);
        }
    }
    return vec;
}

std::vector<gameEngine_ns::object_ns::IObject *> factory_ns::getActiveLasers(const gameEngine_ns::GameEngine &gameEngine, const bool &leftToRight)
{
    std::vector<gameEngine_ns::object_ns::IObject *> vec;
    const std::string validStr = leftToRight ? "player" : "monste";

    for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : gameEngine.getObjects()) {
        if (
            pair.first.substr(0, 5) == "laser" &&
            pair.first.substr(7, 6) == validStr &&
            pair.second->getPos().x > 10
        ) {
            vec.push_back(pair.second);
        }
    }
    return vec;
}

void factory_ns::laodExplosionObjects(gameEngine_ns::GameEngine *gameEngine)
{
    for (int i = 0; i < 20; i++)
        addAndCreateExplosion(gameEngine, gameEngine_ns::geometry_ns::Vector(-100, 0), i);
}

void factory_ns::addAndCreateExplosion(gameEngine_ns::GameEngine *gameEngine, const gameEngine_ns::geometry_ns::Vector &position, const unsigned int &nb)
{    
    std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(0, 0, 33, 32));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(33, 0, 33, 32));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(66, 0, 33, 32));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(99, 0, 33, 32));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(132, 0, 33, 32));
    vec.push_back(gameEngine_ns::geometry_ns::Rectangle(165, 0, 33, 32));
    gameEngine_ns::object_ns::Sprite *sprite = gameEngine->createSprite(
        "boumboum-texture",
        vec,
        50
    );
    if (sprite == nullptr)
        std::cerr << "Can't load sprite" << std::endl;
    sprite->getSFMLSprite()->scale(gameEngine_ns::geometry_ns::Vector(2, 2).toSfVector2f());
    if (gameEngine->addSprite("boumboum-sprite-" + std::to_string(nb), sprite) != 0)
        std::cerr << "Can't add boumboum sprite" << std::endl;
    Explosion *object = new Explosion(sprite, position);
    if (object == nullptr)
        std::cerr << "Can't create object" << std::endl;
    if (gameEngine->addObject("explosion-" + std::to_string(nb), object) != 0)
        std::cerr << "Can't add object" << std::endl;
}

std::vector<gameEngine_ns::object_ns::IObject *> factory_ns::getValidExplosions(const gameEngine_ns::GameEngine &gameEngine)
{
    std::vector<gameEngine_ns::object_ns::IObject *> vec;

    for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : gameEngine.getObjects()) {
        if (pair.first.substr(0, 9) == "explosion" && pair.second->getPos().x <= -100)
            vec.push_back(pair.second);
    }
    return vec;
}

std::vector<gameEngine_ns::object_ns::IObject *> factory_ns::getActiveExplosions(const gameEngine_ns::GameEngine &gameEngine)
{
    std::vector<gameEngine_ns::object_ns::IObject *> vec;

    for (const std::pair<const std::string, gameEngine_ns::object_ns::IObject *> &pair : gameEngine.getObjects()) {
        if (pair.first.substr(0, 9) == "explosion" && pair.second->getPos().x > -100)
            vec.push_back(pair.second);
    }
    return vec;
}