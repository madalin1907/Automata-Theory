cmake_minimum_required(VERSION 3.21)
project(tema1)

set(CMAKE_CXX_STANDARD 14)

add_executable(dfa_minimization_engine AFD.h dfa_minimization_engine.cpp)
add_executable(adv_dfa_minimization_engine AFD.h adv_dfa_minimization_engine.cpp)