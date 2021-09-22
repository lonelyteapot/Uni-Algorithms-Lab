cmake_minimum_required(VERSION 3.20)
project(Uni_Algorithms_Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab1-bitfield lab1/test_bitfield.cpp lab1/TBitField.cpp lab1/TBitField.h)
add_executable(Lab1-set lab1/test_set.cpp lab1/TSet.cpp lab1/TSet.h lab1/TBitField.cpp lab1/TBitField.h)
