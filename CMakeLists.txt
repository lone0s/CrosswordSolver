cmake_minimum_required(VERSION 3.16)
project(AbrSyntaxique)

set(CMAKE_CXX_STANDARD 14)

add_executable(AbrSyntaxique main.cpp SyntaxicTree.cpp SyntaxicTree.h Node.cpp Node.h Chrono.cpp Chrono.h)
