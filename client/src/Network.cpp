/*
** EPITECH PROJECT, 2020
** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
** File description:
** Network
*/

#include "Network.hpp"
#include "Debug_color.hpp"

void Threaded_Send(Network *ClassAccess)//envoie les actions du client -> A FAIRE : regler le tickRate 
{
    while(1) {
        boost::asio::steady_timer timer1_(ClassAccess->_io, boost::asio::chrono::milliseconds(ClassAccess->ms_speed));//1000ms
        timer1_.wait();

        ClassAccess->NetStruct.a = "lorris est gay";
        ClassAccess->NetStruct.b = 'a';
        ClassAccess->NetStruct.c += 1;

        std::ostringstream archive_stream;
        boost::archive::text_oarchive archive(archive_stream);  
        archive << ClassAccess->NetStruct;
       
        ClassAccess->_socket.send_to(boost::asio::buffer(archive_stream.str()),ClassAccess->_server_endpoint);//envoie de la struct au serv
        std::cout << BOLDYELLOW << "[DATA SENDED]" << RESET << " -> DEST=" << ClassAccess->_server_endpoint << std::endl;//DEBUG
    }
}

void Threaded_Receive(Network *ClassAccess) //recoit et met a jour les datas du client
{
    std::string str;
    str.resize(1024);

    while(1) {
        udp::endpoint client_endpoint;
        size_t len = ClassAccess->_socket.receive_from(boost::asio::buffer(str), client_endpoint);

        std::istringstream archive_stream(str);
        boost::archive::text_iarchive archive(archive_stream);
        archive >> ClassAccess->NetStruct;
        std::cout << BOLDGREEN << "[DATA RECEIVED AND UPDATED]" << RESET <<  " -> FROM=" << ClassAccess->_server_endpoint << std::endl;//DEBUG

     //   std::cout << "contenu de a : " << ClassAccess->NetStruct.a << std::endl; //TEST
     //   std::cout << "contenu de b : " << ClassAccess->NetStruct.b << std::endl;//TEST
     //   std::cout << "contenu de c : " << ClassAccess->NetStruct.c << std::endl;//TEST
    }
}

Network::Network(int argc, char **argv) : _io(), _resolver(_io), _socket(_io)
{
    if (argc != 3) {
        std::cerr << "Usage: client <host> <UDP packets speed in MS>" << std::endl;
        exit(84);
    }
    this->ms_speed = atoi(argv[2]);
    this->NetStruct.c = 0; //exemple

    this->_server_endpoint = *_resolver.resolve(udp::v4(), argv[1], "3000").begin(); //recuperation du endpoint
    this->_socket.open(udp::v4()); // ouverture du socket

    boost::thread t1(Threaded_Send, this);
    boost::thread t2(Threaded_Receive, this);
    t1.detach();
    t2.detach();
    t1.join();
    t2.join();
}

Network::~Network()
{
}