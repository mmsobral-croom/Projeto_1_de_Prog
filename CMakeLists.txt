cmake_minimum_required(VERSION 3.14)
project(Projeto_1_de_Prog)

set(CMAKE_CXX_STANDARD 11)
include_directories(.)

add_executable(Projeto_1_de_Prog main.cpp interface_do_usuario.cpp interface_do_usuario.h processamento.cpp processamento.h)