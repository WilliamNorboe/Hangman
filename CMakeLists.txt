hcmake_minimum_required(VERSION 3.15)
project(Hangman)
set(CMAKE_CXX_STANDARD 14)

add_executable(Hangman main.cpp function.cpp function.h game.cpp game.h)