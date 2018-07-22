cmake_minimum_required(VERSION 3.8)
project(GrobnerBasis)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/Polynomial.hpp src/Term.hpp src/Monomial.hpp tests/main.cpp tests/monomial_tests.cpp tests/polynomial_test.cpp tests/term_tests.cpp src/Comparator.hpp src/ModuleTerm.hpp src/ModuleElement.hpp tests/moduleElement_tests.cpp)
add_executable(GrobnerBasis ${SOURCE_FILES})
