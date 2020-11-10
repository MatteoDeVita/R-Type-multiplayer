cmake_minimum_required(VERSION 3.5)

project("r-type_server" LANGUAGES CXX)
project("r-type_client" LANGUAGES CXX)

add_definitions(
    "-fPIC"
    "-g"
    "-g3"
    "-Wall"
    "-Wextra"
    "-lboost_date_time"
    "-lsfml-graphics"
    "-lsfml-window"
    "-lsfml-system"
    "-lboost_serialization"
    "-lboost_system"
    "-lboost_thread"
    "-lpthread"
)

set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

SET(CMAKE_CXX_FLAGS 
    "${CMAKE_CXX_FLAGS} -pthread -fPIC -g -g3 -Wall -Wextra -lboost_date_time -lsfml-graphics -lsfml-window -lsfml-system -lboost_serialization -lboost_system -lboost_thread -lpthread"
)

SET(
    includes
    "${PROJECT_SOURCE_DIR}/src/server/include"
    "${PROJECT_SOURCE_DIR}/src/gameEngine/gameEngine_ns/include"
    "${PROJECT_SOURCE_DIR}/src/gameEngine/geometry_ns/include"
    "${PROJECT_SOURCE_DIR}/src/gameEngine/object_ns/include"
    "${PROJECT_SOURCE_DIR}/src/gameEngine/window_ns/include"
    "${PROJECT_SOURCE_DIR}/src/gameEngine/event_ns/include"
    "${PROJECT_SOURCE_DIR}/src/gameEngine/action_ns/include"
    "${PROJECT_SOURCE_DIR}/src/gameEngine/audio_ns/include"
    "${PROJECT_SOURCE_DIR}/src/gameObjects/include"
    "${PROJECT_SOURCE_DIR}/src/client/include"
    "${PROJECT_SOURCE_DIR}/src/utils/error/include"
    "${PROJECT_SOURCE_DIR}/src/utils/parsing/include"
    "${PROJECT_SOURCE_DIR}/src/utils/models"
    "${PROJECT_SOURCE_DIR}/src/factory/include"
)

include_directories(${CMAKE_INCLUDE_PATH})

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB ServerSourceFiles src/server/src/*.cpp)
file(GLOB ClientSourceFiles src/client/src/*.cpp)
file(GLOB GameEnigneSourceFiles src/gameEngine/*/src/*.cpp)
file(GLOB UtilsSourceFiles src/utils/*/src/*.cpp)
file(GLOB FactoryrSourceFiles src/factory/src/*.cpp)
file(GLOB gameObjectsSourceFiles src/gameObjects/src/*.cpp)

add_executable("r-type_server" ${ServerSourceFiles} ${GameEnigneSourceFiles} ${UtilsSourceFiles} ${FactoryrSourceFiles} ${gameObjectsSourceFiles})
add_executable("r-type_client" ${ClientSourceFiles} ${GameEnigneSourceFiles} ${UtilsSourceFiles} ${FactoryrSourceFiles} ${gameObjectsSourceFiles})

find_package(Boost 1.69.0 COMPONENTS system serialization thread REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries("r-type_server" ${Boost_LIBRARIES})
    target_link_libraries("r-type_client" ${Boost_LIBRARIES})
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5.1 REQUIRED window audio network graphics system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries("r-type_server" ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
  target_link_libraries("r-type_client" ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

install(TARGETS "r-type_server" DESTINATION bin)
install(TARGETS "r-type_client" DESTINATION bin)

target_include_directories("r-type_server" PUBLIC ${includes})
target_include_directories("r-type_client" PUBLIC ${includes})

target_include_directories("r-type_server" PUBLIC ${includes})
target_include_directories("r-type_client" PUBLIC ${includes})
