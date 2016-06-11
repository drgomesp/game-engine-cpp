cmake_minimum_required(VERSION 3.4)
project(Demo-game)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

find_library(FIBULA_LIBRARY
        NAMES Fibula
        HINTS ../libs/include/)

include_directories(
    ../libs/include/Fibula
    Core
    Listeners
    Listeners/SDL
)

file(GLOB SOURCE_LIST
    *.cpp
    Core/*.cpp
    Listeners/SDL/*.cpp
)

add_executable(Demo-game ${SOURCE_LIST})
target_link_libraries(Demo-game Fibula)

add_custom_target(valgrind)
