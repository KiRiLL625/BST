cmake_minimum_required(VERSION 3.27)
project(BST2)

set(CMAKE_CXX_STANDARD 17)

add_executable(BST2 main.cpp
        BST.h
        Set.h)

add_subdirectory(googletest)
add_subdirectory(testing)

install(TARGETS BST2 DESTINATION bin)
