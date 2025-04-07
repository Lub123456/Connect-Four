cmake_minimum_required(VERSION 3.30)
project(Connect_Four)

set(CMAKE_CXX_STANDARD 23)

add_executable(Connect_Four main.cpp
        Player.cpp
        Player.h
        Game.cpp
        Game.h
        Board.cpp
        Board.h
        HumanPlayer.cpp
        HumanPlayer.h
        AIPlayer.cpp
        AIPlayer.h)
