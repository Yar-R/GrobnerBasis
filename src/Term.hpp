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
bool operator==(const Term<Coef, Monom>& a, const Term<Coef, Monom>& b) {
    return a.coef == b.coef && (a.coef == 0 || a.monom == b.monom);
}


#endif //GROBNERBASIS_TERM_H
