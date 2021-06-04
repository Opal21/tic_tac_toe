cmake_minimum_required(VERSION 3.19)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 20)

add_executable(tic_tac_toe main.cpp Lib.hpp Lib.cpp move.hpp move.cpp User.hpp User.cpp Plane.hpp Plane.cpp Game.hpp Game.cpp)