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
    
        /**
         * @brief Construct a new udp server object
         * 
         */
        UDP_Server();

        /**
         * @brief Destroy the udp server object
         * 
         */
        ~UDP_Server();

        /**
         * @brief send your informations where stock in game
         * 
        */
        void do_send();
        /**
         * @brief call this function to receive information 
         * 
         */
        void do_receive();

        /**
         * @brief set the receive information on the gamer where the player is  connected
         * 
         * @param client_endpoint  information of incoming communication
         * @param serielise_string the binary where serializing in a string
         */
        void set_user_info(udp::endpoint remote_endpoint, std::string serielise_string);
        std::vector<GameContainer> _gameContainers;
        int NbofClientassign;
        boost::asio::io_context _io;
    private:
        udp::socket _socket;
        udp::endpoint _client_endpoint;
        enum { max_length = 1024 };
        char _data[max_length];
};