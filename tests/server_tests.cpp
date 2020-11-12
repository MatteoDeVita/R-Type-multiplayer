/*
** EPITECH PROJECT, 2020
** romain triozon
** File description:
** test_send_command
*/

/** 
  * NE SURTOUT PAS METTRE DE MAIN : Criterion va automatiquement créer une fonction main
  * Pour voir toute les assert et leurs options : https://github.com/Snaipe/Criterion/blob/514b4d820e2f8fb4daa2b95b69c981853656cb73/include/criterion/assert.h
  * la compilation devra étre rajouté au cmake : g++ -o unit_tests test_send_command.cpp  --coverage -lcriterion
  * Avec la compilation sité au dessus pour tester vous pouvez utiliser : "./unit_test"
**/

#include <criterion/criterion.h>
#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/thread/thread.hpp>

typedef struct {
    std::string datas_receive;
    std::string datas_send;
} environment_t;

class ClientServerSide {
    public:
        ClientServerSide(){};
        ~ClientServerSide(){};
        boost::asio::ip::udp::endpoint _endpoint;
        int ton_num; //debug

    protected:
    private:
        
};

class GameContainer {
    public:
        GameContainer()
        {};
        ~GameContainer(){

        };
        void push_newclient(boost::asio::ip::udp::endpoint endpointer){
            ClientServerSide *newest = new ClientServerSide;
            newest->_endpoint = endpointer;
            this->_clients.push_back(newest);
        };
        std::vector<ClientServerSide *> _clients;
        environment_t EnvServData;
    protected:
    private:
};

std::vector<GameContainer> set_vector_for_test()//criterion test func
{
    boost::system::error_code ec; 
    boost::asio::ip::udp::endpoint ep1(boost::asio::ip::address::from_string("84.5.5.6", ec), 3333);
    boost::asio::ip::udp::endpoint ep2(boost::asio::ip::address::from_string("136.1.12.78", ec), 3333);
    boost::asio::ip::udp::endpoint ep3(boost::asio::ip::address::from_string("124.58.1.36", ec), 3333);

    std::vector<GameContainer> _gameVector;
    GameContainer game1;
    GameContainer game2;
    GameContainer game3;
    for (int i = 0; i < 4 ; i++){
        game1.push_newclient(ep1);
        game2.push_newclient(ep1);
    }
    game3.push_newclient(ep1);
    game3.push_newclient(ep2);
    game3.push_newclient(ep3);
    game1.EnvServData.datas_send = "data sended game 1";
    game2.EnvServData.datas_send = "data sended game 2";
    game3.EnvServData.datas_send = "data sended game 3";
    _gameVector.push_back(game1);
    _gameVector.push_back(game2);
    _gameVector.push_back(game3);
    return _gameVector;
}

Test(server, take_value_to_send)
{
    std::vector<GameContainer> _gameVector = set_vector_for_test();//criterion test Var
    std::string test;

    boost::system::error_code ec; //criterion test Var
    boost::asio::ip::udp::endpoint target_endpoint(boost::asio::ip::address::from_string("124.58.1.36", ec), 3333);//criterion test Var
    
    for (unsigned int i = 0; i < _gameVector.size(); i++) {
        for (unsigned int y = 0; y < _gameVector.at(i)._clients.size(); y++) {
            if(target_endpoint.address() == _gameVector.at(i)._clients.at(y)->_endpoint.address()) {
               test = _gameVector.at(i).EnvServData.datas_send;
                //std::cout << _gameVector.at(i)._clients.at(y)->_endpoint.address() <<std::endl;
                cr_assert(test == "data sended game 3");
            }
        }
    }
}

Test(server, new_client_store_info_new_container)
{
    std::vector<GameContainer> _gameVector = set_vector_for_test();//criterion test Var
    std::string test;
    int NbofClientassign = 12;//criterion test Var
    boost::system::error_code ec; //criterion test Var
    boost::asio::ip::udp::endpoint client_endpoint(boost::asio::ip::address::from_string("124.58.1.36", ec), 3333);//criterion test Var


    ClientServerSide *new_client = new ClientServerSide;
    new_client->_endpoint = client_endpoint;
    new_client->ton_num = NbofClientassign;

    if (NbofClientassign % 4 == 0) {
            GameContainer *newest = new GameContainer;
            newest->_clients.push_back(new_client);
            newest->EnvServData.datas_receive = "serielise_string";
            _gameVector.push_back(*newest);
       }
       NbofClientassign++;
       cr_assert("serielise_string" == _gameVector.at(_gameVector.size() - 1).EnvServData.datas_receive);
}

Test(server, new_client_store_info_in_last_container_slot)
{
    std::vector<GameContainer> _gameVector = set_vector_for_test();//criterion test Var
    std::string test = "serielise_string2" ;
    int NbofClientassign = 11;//criterion test Var
    boost::system::error_code ec; //criterion test Var
    boost::asio::ip::udp::endpoint client_endpoint(boost::asio::ip::address::from_string("124.58.1.36", ec), 3333);//criterion test Var


    ClientServerSide *new_client = new ClientServerSide;
    new_client->_endpoint = client_endpoint;
    new_client->ton_num = NbofClientassign;

    if (NbofClientassign % 4 != 0) {
           _gameVector.at(_gameVector.size() - 1).EnvServData.datas_receive = test;
           _gameVector.at(_gameVector.size() - 1)._clients.push_back(new_client);
       }
       NbofClientassign++;
       cr_assert(test == _gameVector.at(_gameVector.size() - 1).EnvServData.datas_receive);
}

Test(server, exist_client_store_info)
{
    std::vector<GameContainer> _gameVector = set_vector_for_test();//criterion test Var
    std::string test = "serielise_string";

    boost::system::error_code ec; //criterion test Var
    boost::asio::ip::udp::endpoint target_endpoint(boost::asio::ip::address::from_string("124.58.1.36", ec), 3333);//criterion test Var

    for (unsigned int i = 0; i < _gameVector.size(); i++) {
        for (unsigned int y = 0; y < _gameVector.at(i)._clients.size(); y++) {
            if(target_endpoint.address() == _gameVector.at(i)._clients.at(y)->_endpoint.address()) {
                _gameVector.at(i)._clients.at(y)->_endpoint = target_endpoint;
                _gameVector.at(i).EnvServData.datas_receive.clear();
                _gameVector.at(i).EnvServData.datas_receive = test;
                cr_assert(_gameVector.at(i).EnvServData.datas_receive == test);
                break;
            }
        }
    }
}