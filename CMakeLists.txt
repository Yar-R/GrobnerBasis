cmake_minimum_required(VERSION 3.8)
project(GrobnerBasis)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/Polynomial.hpp
        src/Term.hpp
        src/Monomial.hpp
        tests/main.cpp
        src/ModuleMonomial.hpp
        src/ModuleElement.hpp
        src/Input.hpp
        src/MonomialOrder.hpp
        src/PairsetOrder.hpp
        src/RewriteOrder.hpp
        src/ModuleMonomialOrder.hpp
        src/Pairset.hpp
        src/ModuleBasis.hpp
        src/Basis.hpp
        src/MF5.hpp
        src/RB.hpp
        src/F4-5.hpp)
add_executable(GrobnerBasis ${SOURCE_FILES})
