//
// Created by Yaroslav Rebenko on 20.07.2018.
//

#include "../src/Term.hpp"
#include "catch.hpp"
#include "../src/Monomial.hpp"

bool term_mul_1() {
    Term<double, Monomial<int> > a(1, {1});
    Term<double, Monomial<int> > b(1, {0, 1});
    Term<double, Monomial<int> > c(1, {1, 1});
    return a * b == c;
}

bool term_mul_2() {
    Term<double, Monomial<int> > a(1, {0, 1});
    Term<double, Monomial<int> > b(1, {1});
    Term<double, Monomial<int> > c(1, {1, 1});
    return a * b == c;
}

bool term_mul_3() {
    Term<double, Monomial<int> > a(0, {1});
    Term<double, Monomial<int> > b(1, {0, 1});
    Term<double, Monomial<int> > c(0, {});
    return a * b == c;
}

bool term_sum_1() {
    Term<double, Monomial<int> > a(2, {1});
    Term<double, Monomial<int> > b(1, {1});
    Term<double, Monomial<int> > c(3, {1});
    return a + b == c;
}


TEST_CASE( "Term Mul second dim bigger" ) {
    REQUIRE( term_mul_1() );
}

TEST_CASE( "Term Mul first dim bigger" ) {
    REQUIRE( term_mul_2() );
}

TEST_CASE( "Term Mul zero" ) {
    REQUIRE( term_mul_3() );
}

TEST_CASE( "Term Sum" ) {
    REQUIRE( term_sum_1() );
}
