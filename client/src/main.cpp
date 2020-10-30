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
//#include "Network.hpp"
using boost::asio::ip::udp;

void StartMessage(int argc) {
  if (argc != 3)
    {
      std::cerr << "Usage: client <host> <message>" << std::endl;
      exit(84);
    }
}

void Receive(udp::socket *socket)
{
    boost::array<char, 128> recv_buf;
    while(1) {
        udp::endpoint client_endpoint;
        size_t len = socket->receive_from(boost::asio::buffer(recv_buf), client_endpoint);
        std::cout << "Data received : " << recv_buf.data() << std::endl;
    }
}

void Send(boost::asio::io_context *io, std::string message, udp::endpoint *serverEndpoint, udp::socket *socket)
{
  while(1) {
      boost::asio::steady_timer timer1_(*io, boost::asio::chrono::seconds(1));
      timer1_.wait();
      socket->send_to(boost::asio::buffer(message), *serverEndpoint);//envoie d'une var sendbuf au endpoint
  }
}

int main(int argc, char* argv[])
{
    StartMessage(argc);
    
    boost::asio::io_context io;
    udp::resolver resolver(io);
    udp::endpoint serverEndpoint = *resolver.resolve(udp::v4(), argv[1], "3000").begin(); //recuperation du endpoint
    udp::socket socket(io); //creation d'un socket UDP
    socket.open(udp::v4()); // ouverture du socket

    std::string message = argv[2];//message

    boost::thread t1(Send, &io, message, &serverEndpoint, &socket);
    boost::thread t2(Receive, &socket);
    t1.detach();
    t2.detach();

    while (1) { //Gameloop
    
    }

    t1.join();
    t2.join();
    return 0;
}