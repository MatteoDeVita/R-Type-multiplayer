/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
      std::cerr << "Usage: client <host> <message>" << std::endl;
      return 1;
    }

    boost::asio::io_context io; //creation objet boost asio

    udp::resolver resolver(io);//creation d'un object resolver pour trouver le endpoint(le host distant)
    udp::endpoint receiver_endpoint = *resolver.resolve(udp::v4(), argv[1], "3000").begin(); //recuperation du endpoint


    udp::socket socket(io); //creation d'un socket UDP
    socket.open(udp::v4()); // ouverture du socket
    std::string message = argv[2];
    while (1)
    {
        boost::asio::steady_timer timer1_(io, boost::asio::chrono::seconds(1));
        timer1_.wait();
        socket.send_to(boost::asio::buffer(message), receiver_endpoint);//envoie d'une var sendbuf au endpoint
        //reception
        boost::array<char, 128> recv_buf;
        udp::endpoint sender_endpoint; //on devient un Endpoint a notre tour
        size_t len = socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);
        //affichage des donnes recus
        std::cout<< recv_buf.data() << std::endl;

    }
    return 0;
}