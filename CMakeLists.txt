cmake_minimum_required(VERSION 3.19)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 20)

add_executable(tic_tac_toe main.cpp lib.hpp lib.cpp move.hpp move.cpp user.hpp User.cpp plane.hpp Plane.cpp Game.hpp Game.cpp)