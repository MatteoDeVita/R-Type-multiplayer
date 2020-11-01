cmake_minimum_required(VERSION 3.5)

project("r-type_server" LANGUAGES CXX)
project("r-type_client" LANGUAGES CXX)

add_definitions("-fPIC" "-g" -"g3" "-Wall" "-Wextra" "-lboost_serialization" "-lboost_system" "-lboost_thread" "-lpthread" "-lboost_date_time" )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
SET(includes 
    "${PROJECT_SOURCE_DIR}/src/server/include"
    "${PROJECT_SOURCE_DIR}/src/gameEngine/gameEngine_ns/include"
    "${PROJECT_SOURCE_DIR}/src/gameEngine/geometry_ns/include"
    "${PROJECT_SOURCE_DIR}/src/client/include"
)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_INCLUDE_PATH})

file(GLOB ServerSourceFiles src/server/src/*.cpp)
file(GLOB ClientSourceFiles src/client/src/*.cpp)
file(GLOB GameEnigneSourceFiles src/gameEngine/*/src/*.cpp)

add_executable("r-type_server" ${ServerSourceFiles} ${GameEnigneSourceFiles})
add_executable("r-type_client" ${ClientSourceFiles} ${GameEnigneSourceFiles})

target_link_libraries("r-type_server" Boost::thread Boost::serialization)
target_link_libraries("r-type_client" Boost::thread Boost::serialization)

target_include_directories("r-type_server" PUBLIC ${includes})
target_include_directories("r-type_client" PUBLIC ${includes})

find_package(Boost 1.71.0 COMPONENTS thread system filesystem serialization REQUIRED)
