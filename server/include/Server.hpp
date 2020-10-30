#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <boost/asio.hpp>

#include "GameContainer.hpp"

using boost::asio::ip::udp;

class UDP_Server
{
    public:
        UDP_Server(boost::asio::io_context *io);
        ~UDP_Server();
        void send(boost::asio::io_context *io);
        void receive(boost::asio::io_context *io);
        std::string get_user_is_know(udp::endpoint remote_endpoint);
    private:
        bool get_user_is_know();
        boost::asio::io_context _io;
        boost::array<char, 128> _recv_buffer;
        std::vector<GameContainer> _gameContainers;
        int NbofClientassign;

};