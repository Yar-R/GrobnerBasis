cmake_minimum_required(VERSION 3.8)
project(GrobnerBasis)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Monomial.cpp Monomial.h Term.cpp Term.h Polynomial.cpp Polynomial.h Polic.cpp Polic.h Comparator.cpp Comparator.h Monic.cpp Monic.h MonicComparator.cpp MonicComparator.h)
add_executable(GrobnerBasis ${SOURCE_FILES})