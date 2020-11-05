/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** environment
*/

// pos x
// pos y
// uuid sprite_id

#include <vector>
#include <string>

#include "object.hpp"
#include <boost/serialization/vector.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

typedef struct {
    std::string datas_receive;
    std::string datas_send;
    //template<typename Ar> void serialize(Ar& ar, unsigned) { ar & datas;}
} environment_t;
