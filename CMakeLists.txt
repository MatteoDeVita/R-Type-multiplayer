cmake_minimum_required(VERSION 3.5)

project("r-type_server" LANGUAGES CXX)
project("r-type_client" LANGUAGES CXX)

add_definitions("-fPIC" "-lpthread" "-g" -"g3" "-Wall" "-Wextra")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CMAKE_INCLUDE_PATH})

file(GLOB ServerSourceFiles server/src/*.cpp)
file(GLOB ClientSourceFiles client/src/*.cpp)

add_executable("r-type_server" ${ServerSourceFiles})
add_executable("r-type_client" ${ClientSourceFiles})

target_include_directories("r-type_server" PUBLIC "${PROJECT_SOURCE_DIR}/server/include")
target_include_directories("r-type_client" PUBLIC "${PROJECT_SOURCE_DIR}/client/include")
