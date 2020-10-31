// /*
// ** EPITECH PROJECT, 2020
// ** B-CPP-501-LYN-5-1-rtype-lorris.hamdaoui [WSL: Ubuntu-20.04]
// ** File description:
// ** Thread
// */

// #pragma once

// #include <mutex>
// #include <iostream>
// #include <unistd.h>
// #include <boost/array.hpp>
// #include <boost/asio.hpp>
// #include <thread> 

// using boost::asio::ip::udp;

// class Network {
//     public:
//         Network();
//         ~Network();
//         void receive(udp::socket *socket);
//         void send(std::string message, udp::socket *socket);
//         void create_thread_send(std::string message);
//         std::thread *thread_receive;
//         std::thread *thread_send;
//       //  boost::asio::io_context io;
//     //    udp::resolver resolver;
//         boost::array<char, 128> recv_buf;
//         udp::endpoint serverEndpoint;
//     protected:
//     private:
// };