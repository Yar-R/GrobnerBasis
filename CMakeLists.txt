cmake_minimum_required(VERSION 3.8)
project(GrobnerBasis)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/Polynomial.hpp src/Term.hpp src/Monomial.hpp tests/main.cpp src/Comparator.hpp src/ModuleTerm.hpp src/ModuleElement.hpp src/MF5.hpp src/ModuleComparator.hpp)
add_executable(GrobnerBasis ${SOURCE_FILES})
