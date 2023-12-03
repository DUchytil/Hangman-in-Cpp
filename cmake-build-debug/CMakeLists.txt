cmake_minimum_required(VERSION 3.26)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 20)

add_executable(HelloWorld main.cpp
        PlayerStats.cpp
        PlayerStats.h
)
