cmake_minimum_required(VERSION 3.8)
project(GrobnerBasis)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Monomial.cpp Monomial.h Polynomial.cpp Polynomial.h Comparator.cpp Comparator.h Term.cpp Term.h)
add_executable(GrobnerBasis ${SOURCE_FILES})