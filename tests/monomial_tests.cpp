//
// Created by Yaroslav Rebenko on 20.07.2018.
//

#include "../src/Monomial.hpp"
#include "catch.hpp"

bool test_monomial_mul_1() {
    Monomial<int> a = {1, 1, 1};
    Monomial<int> b = {1, 1};
    Monomial<int> c = {2, 2, 1};
    return a * b == c;
}

bool test_monomial_mul_2() {
    Monomial<int> a = {1, 1};
    Monomial<int> b = {1, 1, 1};
    Monomial<int> c = {2, 2, 1};
    return a * b == c;
}

bool test_monomial_mul_3() {
    Monomial<int> a = {1, 1};
    a *= {1, 1, 1};
    Monomial<int> c = {2, 2, 1};
    return a == c;
}

TEST_CASE( "Monomial Mul first dim bigger" ) {
    REQUIRE( test_monomial_mul_1() );
}

TEST_CASE( "Monomial Mul second dim bigger" ) {
    REQUIRE( test_monomial_mul_2() );
}

TEST_CASE( "Monomial Mul assign" ) {
    REQUIRE( test_monomial_mul_3() );
}
