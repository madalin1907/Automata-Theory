cmake_minimum_required(VERSION 3.21)
project(tema1)

set(CMAKE_CXX_STANDARD 14)

add_executable(nfa_parser_engine NFA.h nfa_parser_engine.cpp)
add_executable(nfa_acceptance_engine NFA.h nfa_acceptance_engine.cpp)