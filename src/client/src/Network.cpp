/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** Network
*/

#include <sstream>
#include <vector>
#include <string>

#include "Network.hpp"
#include "Debug_color.hpp"
#include "Object.hpp"
#include "Error.hpp"

void Threaded_Send(Network *ClassAccess)//envoie les actions du client -> A FAIRE : regler le tickRate 
{
    while(1) {
        boost::asio::steady_timer timer1_(*ClassAccess->_io, boost::asio::chrono::milliseconds(ClassAccess->ms_speed));//1000ms
        timer1_.wait();

        /*std::ostringstream archive_stream;
        boost::archive::text_oarchive archive(archive_stream);
        archive << ClassAccess->EnvClientData;*/
        //ClassAccess->EnvClientData->datas = "UP";//test
        ClassAccess->_socket->send_to(boost::asio::buffer(ClassAccess->EnvClientData->datas_send/*archive_stream.str()*/),ClassAccess->_server_endpoint);//envoie de la struct au serv
        std::cout << BOLDYELLOW << "[DATA SENT]" << RESET << " -> DEST=" << ClassAccess->_server_endpoint << std::endl;//DEBUG
    }
}

void Threaded_Receive(Network *ClassAccess) //recoit et met a jour les datas du client
{
    boost::array<char, 4096>_test_recv;
    while(1) {
        udp::endpoint client_endpoint;
        std::vector<std::string> strVec;
        gameEngine_ns::object_ns::Sprite *sprite;
        // size_t len = 
        //ClassAccess->EnvClientData->datas.clear();

        ClassAccess->_socket->receive_from(boost::asio::buffer(_test_recv), client_endpoint);


        /*std::istringstream archive_stream(str);
        boost::archive::text_iarchive archive(archive_stream);
        archive >> ClassAccess->EnvClientData;*/
        ClassAccess->EnvClientData->datas_receive = _test_recv.data();

        std::cout << BOLDGREEN << "[DATA RECEIVED AND UPDATED]" << RESET <<  " -> FROM=" << ClassAccess->_server_endpoint << std::endl;//DEBUG
        std::cout << BOLDBLUE << "CONTENT : " << ClassAccess->EnvClientData->datas_receive <<  "\nSIZE :" << ClassAccess->EnvClientData->datas_receive.size() <<RESET << std::endl; //TEST
        std::stringstream ss(ClassAccess->EnvClientData->datas_receive);
        std::string tmp;

        std::vector<gameEngine_ns::geometry_ns::Rectangle> vec;

        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(1, 0, 64, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(70, 0, 56, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(196, 0, 64, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(262, 0, 64, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(333, 0, 52, 132));
        vec.push_back(gameEngine_ns::geometry_ns::Rectangle(457, 0, 64, 132));

        std::size_t firstSpaceIndex = 0;
        std::size_t secondSpaceIndex = 0;
        std::string x_str, y_str, id_str;
        float x = 0;
        float y = 0;
        while (std::getline(ss, tmp, '|')) {
            firstSpaceIndex = tmp.find(" ");
            x_str = tmp.substr(0, firstSpaceIndex);

            secondSpaceIndex = tmp.find(" ", x_str.length() + 1);
            y_str = tmp.substr(firstSpaceIndex + 1, secondSpaceIndex - firstSpaceIndex - 1);

            id_str = tmp.substr(secondSpaceIndex + 1, tmp.length() - firstSpaceIndex - 1);

            x = std::stof(x_str);
            y = std::stof(y_str);

            if (ClassAccess->_gameEngine->getObject(id_str) == nullptr) {
                if ((sprite = ClassAccess->_gameEngine->createSprite("monster1-texture", vec, 100)) == nullptr)
                    throw Error("Can't load sprite");
                if (ClassAccess->_gameEngine->addSprite("monster1-sprite", sprite) != 0)
                    throw Error("Can't add sprite");               
                ClassAccess->_gameEngine->addObject(
                    id_str, new gameEngine_ns::object_ns::Object(
                        ClassAccess->_gameEngine->getSprite("monster1-sprite"),
                        gameEngine_ns::geometry_ns::Vector(x, y)
                    )
                );
            }
            else {
                ClassAccess->_gameEngine->getObject(id_str)->setPos(gameEngine_ns::geometry_ns::Vector(x, y));
            }
           
        }
    }
        
}

Network::Network(char **argv, environment_t *EnvClientData, gameEngine_ns::GameEngine *gameEngine) // //_resolver(_io), _io() _resolver(io) _socker(io)
{
    this->_io = new boost::asio::io_context;
    this->_resolver = new udp::resolver(*this->_io);
    this->_socket = new udp::socket(*this->_io);
    this->ms_speed = atoi(argv[2]);
    this->EnvClientData = EnvClientData;
    this->EnvClientData->datas_send = "INIT";//test
    this->_gameEngine = gameEngine;
    
    this->_server_endpoint = *_resolver->resolve(udp::v4(), argv[1], "3000").begin(); //recuperation du endpoint
    this->_socket->open(udp::v4()); // ouverture du socket

    boost::thread t1(Threaded_Send, this);
    boost::thread t2(Threaded_Receive, this);
    t1.detach();
    t2.detach();
    t1.join();
    t2.join();
}

Network::~Network()
{
    delete this->_io;
    delete this->_resolver;
    delete this->_socket;
}
