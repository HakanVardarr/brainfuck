cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 11)
project(brainfuck)

include_directories(src)
aux_source_directory(src SOURCES)

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})