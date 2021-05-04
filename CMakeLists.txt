cmake_minimum_required(VERSION 3.19)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 20)

add_executable(tic_tac_toe main.cpp User.cpp inc/User.h Plane.cpp inc/Plane.h Player.cpp inc/Player.h Bot.cpp inc/Bot.h)