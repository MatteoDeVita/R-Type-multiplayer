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
    std::vector<float> pos_x;
    std::vector<float> pos_y;
    std::vector<std::string> sprite_ids;
    template<typename Ar> void serialize(Ar& ar, unsigned) { ar & pos_x & pos_y & sprite_ids;}
} environment_t;
