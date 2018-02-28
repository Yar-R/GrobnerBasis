cmake_minimum_required(VERSION 3.8)
project(GrobnerBasis)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Monomial.hpp Term.hpp Comparator.hpp main.cpp)
add_executable(GrobnerBasis ${SOURCE_FILES})