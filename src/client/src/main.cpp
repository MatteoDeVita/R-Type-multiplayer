/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

//#include "Network.hpp"
using boost::asio::ip::udp;

typedef struct sample_t {
    std::string a;
    char b;
    int c;
    template<typename Ar> void serialize(Ar& ar, unsigned) { ar & a & b & c; }
} sample;
sample Networkstruct;
void StartMessage(int argc) {
    if (argc != 2) {
        std::cerr << "Usage: client <host>" << std::endl;
        exit(84);
    }
}

void Receive(udp::socket *socket) //recoit et met a jour les datas du client -> A FAIRE : regler le tickRate 
{
    std::string str;
    str.resize(1024);

    while(1) {
        udp::endpoint client_endpoint;
        size_t len = socket->receive_from(boost::asio::buffer(str), client_endpoint);

        std::istringstream archive_stream(str);
        sample mystruct;
        boost::archive::text_iarchive archive(archive_stream);
        archive >> mystruct;

        std::cout << "contenu de a : " << mystruct.a  << std::endl;
         std::cout << "contenu de b : " << mystruct.b << std::endl;
          std::cout << "contenu de c : " << mystruct.c  << std::endl;
    }
}

void Send(boost::asio::io_context *io, udp::endpoint *serverEndpoint, udp::socket *socket)//envoie les actions du client -> A FAIRE : regler le tickRate 
{
    while(1) {
        boost::asio::steady_timer timer1_(*io, boost::asio::chrono::seconds(1));
        timer1_.wait();

        
        Networkstruct.a = "lorris est gay";
        Networkstruct.b = 'a';
        Networkstruct.c += 1;

        std::ostringstream archive_stream;
        boost::archive::text_oarchive archive(archive_stream);  
        archive << Networkstruct;

        socket->send_to(boost::asio::buffer(archive_stream.str()), *serverEndpoint);//envoie de la struct au serv
    }
}

int main(int argc, char* argv[])
{
    StartMessage(argc);
    Networkstruct.c = 0;
    boost::asio::io_context io;
    udp::resolver resolver(io);
    udp::endpoint serverEndpoint = *resolver.resolve(udp::v4(), argv[1], "3000").begin(); //recuperation du endpoint
    udp::socket socket(io); //creation d'un socket UDP
    socket.open(udp::v4()); // ouverture du socket

    boost::thread t1(Send, &io, &serverEndpoint, &socket);
    boost::thread t2(Receive, &socket);
    t1.detach();
    t2.detach();

    while (1) { //Gameloop
    
    }

    t1.join();
    t2.join();
    return 0;
}