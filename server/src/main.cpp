/*
** EPITECH PROJECT, 2020
** testasioudp [WSL: Ubuntu-20.04]
** File description:
** Main
*/
#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include "Server.hpp"

int main()
{
    UDP_Server serv;
    while(1)
    {}
    return 0;


  //  boost::asio::io_service io_service;

   // udp::socket socket(io_service, udp::endpoint(udp::v4(), 3000));

   // for (;;)
   // {
   //   boost::array<char, 126> recv_buf;
  //    udp::endpoint remote_endpoint;
   //   boost::system::error_code error;
    //  socket.receive_from(boost::asio::buffer(recv_buf),
     //     remote_endpoint, 0, error);
//std::cout << "recu: " <<recv_buf.data() << std::endl;
  //    if (error && error != boost::asio::error::message_size)
   //     throw boost::system::system_error(error);

   //   std::string message = "suce";

  //    boost::system::error_code ignored_error;
  //    socket.send_to(boost::asio::buffer(message),
  //        remote_endpoint, 0, ignored_error);
  //  }
  }
