cmake_minimum_required(VERSION 3.8)
project(EX4)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Server.h MySerialServer.cpp MySerialServer.h)
add_executable(EX4 ${SOURCE_FILES})