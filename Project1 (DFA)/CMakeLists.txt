cmake_minimum_required(VERSION 3.21)
project(tema1)

set(CMAKE_CXX_STANDARD 14)

add_executable(dfa_acceptance_engine DFA.h dfa_acceptance_engine.cpp)
add_executable(dfa_parser_engine DFA.h dfa_parser_engine.cpp)
