cmake_minimum_required(VERSION 3.8)
project(GrobnerBasis)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/Polynomial.hpp
        src/Term.hpp
        src/Monomial.hpp
        tests/main.cpp
        src/Input.hpp
        src/MonomialOrder.hpp
        src/Matrix.hpp
        src/MF5Signature.hpp
        src/Basis.hpp
        src/MF5.hpp
        )
add_executable(GrobnerBasis ${SOURCE_FILES})
