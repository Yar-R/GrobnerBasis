//
// Created by Yaroslav Rebenko on 20.07.2018.
//

#ifndef GROBNERBASIS_TERM_H
#define GROBNERBASIS_TERM_H

#include <iostream>
#include "Monomial.hpp"

template <typename Coef, typename Monom>
class Term {
public:
    Coef coef;
    Monom monom;
    Term(const Coef& c, const Monom& m) : coef(c), monom(m) {}
    Term(const Coef& c) : coef(c), monom(0) {}
};

template <typename Coef, typename Monom>
Term<Coef, Monom>& operator*=(Term<Coef, Monom>& first, const Term<Coef, Monom>& second) {
    first.coef *= second.coef;
    if (first.coef) {
        first.monom *= second.monom;
    } else {
        first.monom = {};
    }
    return first;
}

template <typename Coef, typename Monom>
Term<Coef, Monom> operator*(const Term<Coef, Monom>& a, const Term<Coef, Monom>& b) {
    auto c = a;
    c *= b;
    return c;
}

template <typename Coef, typename Monom>
Term<Coef, Monom>& operator+=(Term<Coef, Monom>& first, const Term<Coef, Monom>& second) {
    first.coef += second.coef;
    return first;
}

template <typename Coef, typename Monom>
Term<Coef, Monom> operator+(const Term<Coef, Monom>& a, const Term<Coef, Monom>& b) {
    auto c = a;
    c += b;
    return c;
}

template <typename Coef, typename Monom>
bool operator==(const Term<Coef, Monom>& a, int b) {
    return a.coef == b;
};

template <typename Coef, typename Monom>
bool operator==(const Term<Coef, Monom>& a, const Term<Coef, Monom>& b) {
    return a.coef == b.coef && (a.coef == 0 || a.monom == b.monom);
}

template <typename Coef, typename Monom>
std::experimental::optional<Term<Coef, Monom>> operator/(const Term<Coef, Monom>& a, const Term<Coef, Monom>& b) {
    auto m = a.monom / b.monom;
    if (!m) {
        return {};
    }
    return Term<Coef, Monom>(a.coef / b.coef, get_value(m));

}

template <typename Coef, typename Pow>
Term<Coef, Pow> gcd(const Term<Coef, Pow>& a, const Term<Coef, Pow>& b) {
    auto c = gcd(a.coef, b.coef);
    auto m = gcd(a.monom, b.monom);
    return Term<Coef, Pow>(c, m);
};

#endif //GROBNERBASIS_TERM_H
