//
// Created by Yaroslav Rebenko on 20.07.2018.
//

#include "../src/Polynomial.hpp"
#include "../src/Comparator.hpp"
#include "catch.hpp"

bool polynomial_add_term() {
    Polynomial a = {{1, {2, 1}}, {1, {1, 1}}};
    Polynomial b = {{1, {1, 1}}};
    a += b[0];
    Polynomial c = {{1, {2, 1}}, {2, {1, 1}}};
    return a == c;
}

bool polynomial_mul_term() {
    Polynomial a = {{1, {2, 1}}, {1, {1, 1}}};
    Polynomial b = {{1, {1, 1}}};
    a *= b[0];
    Polynomial c = {{1, {3, 2}}, {1, {2, 2}}};
    return a == c;
}

bool polynomial_add() {
    auto cmp = Lex<int64_t>();
    Polynomial a = {{2, {2, 2}}, {1, {1, 1}}};
    Polynomial b = {{3, {1, 1}}, {3, {}}};
    a = std::move(add(std::ref(cmp), a, b));
    Polynomial c = {{2, {2, 2}}, {4, {1, 1}}, {3, {}}};
    return a == c;
}

bool polynomial_mul() {
    auto cmp = Lex<int64_t>();
    Polynomial a = {{3, {3, 10}}, {1, {2, 1}}, {10, {0, 1}}};
    Polynomial b = {{1, {1, 9}}, {1, {}}};
    a = std::move(mul(std::ref(cmp), a, b));
    Polynomial c = {{3, {4, 19}}, {4, {3, 10}}, {1, {2, 1}}, {10, {1, 10}}, {10, {0, 1}}};
    return a == c;
}

TEST_CASE( "Polynomial add assign term" ) {
    REQUIRE( polynomial_add_term() );
}

TEST_CASE( "Polynomial mul assign term") {
    REQUIRE( polynomial_mul_term() );
}

TEST_CASE( "Polynomial add" ) {
    REQUIRE( polynomial_add() );
}

TEST_CASE( "Polynomial mul" ) {
    REQUIRE( polynomial_mul() );
}