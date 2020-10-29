#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

#include "GameContainer.hpp"


using boost::asio::ip::udp;
class udp_server
{
    public:
      //  std::vector<Parts>
        udp_server(boost::asio::io_context& io);
        bool get_user_is_know();
    private:
        void start_receive();
        void process(const boost::system::error_code& error, std::size_t /*bytes_transferred*/);
        void handle_send(boost::shared_ptr<std::string> /*message*/, const boost::system::error_code& /*error*/, std::size_t /*bytes_transferred*/);
        udp::socket socket_;
        void send_data_game_to_clients();
        udp::endpoint remote_endpoint_;
        boost::array<char, 128> recv_buffer_;
        std::vector<GameContainer> _gameContainers;
        int NbofClientassign;
        void game_container_load_balancer();

};