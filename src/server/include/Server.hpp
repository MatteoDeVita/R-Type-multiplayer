#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread/thread.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include "Debug_color.hpp"
#include "GameContainer.hpp"

using boost::asio::ip::udp;

class UDP_Server
{
    public:
        UDP_Server();
        ~UDP_Server();
        void do_send();
        void do_receive();
        void set_user_info(udp::endpoint remote_endpoint, std::string serielise_string);
        bool get_user_is_know();
        std::vector<GameContainer> _gameContainers;
        int NbofClientassign;
        boost::asio::io_context _io;
    private:
        udp::socket _socket;
        udp::endpoint _client_endpoint;
        enum { max_length = 4096 };
        char _data[max_length];
};