//
// Created by yaroslav on 5/12/18.
//

#include "Term.h"

double &Term::coef() {
    return _coef;
}

const double &Term::coef() const {
    return _coef;
}

Monomial &Term::mon() {
    return _mon;
}

const Monomial &Term::mon() const {
    return _mon;
}

Term Term::operator-() const {
    auto ans = Term(*this);
    ans.coef() *= -1;
    return ans;
}

Term &Term::operator+=(const Term &other) {
    if (mon() != other.mon())
        throw std::exception();
    else
        coef() += other.coef();
    return *this;
}

Term &Term::operator-=(const Term &other) {
    if (mon() != other.mon())
        throw std::exception();
    else
        coef() -= other.coef();
    return *this;
}

Term &Term::operator*=(const Term &other) {
    mon() *= other.mon();
    return *this;
}

Term &Term::operator/=(const Term &other) {
    mon() /= other.mon();
    return *this;
}

Term operator+(const Term &a, const Term &b) {
    auto ans = a;
    ans += b;
    return ans;
}

Term operator-(const Term &a, const Term &b) {
    auto ans = a;
    ans -= b;
    return ans;
}

Term operator*(const Term &a, const Term &b) {
    auto ans = a;
    ans *= b;
    return ans;
}

Term operator/(const Term &a, const Term &b) {
    auto ans = a;
    ans /= b;
    return ans;
}

Term &Term::operator*=(const double &other) {
    coef() *= other;
    return *this;
}

Term &Term::operator/=(const double &other) {
    coef() /= other;
    return *this;
}

Term &Term::operator*=(const Monomial &other) {
    mon() *= other;
    return *this;
}

Term &Term::operator/=(const Monomial &other) {
    mon() /= other;
    return *this;
}

Term operator*(const Term &a, const double &b) {
    auto ans = a;
    ans *= b;
    return ans;
}

Term operator/(const Term &a, const double &b) {
    auto ans = a;
    ans /= b;
    return ans;
}

Term operator*(const Term &a, const Monomial &b) {
    auto ans = a;
    ans *= b;
    return ans;
}

Term operator/(const Term &a, const Monomial &b) {
    auto ans = a;
    ans /= b;
    return ans;
}

Term::Term(double c, const Monomial &m) :_coef(c), _mon(m) {

}

Term::Term(double c, Monomial &&m) : _coef(c), _mon(std::move(m)) {

}

Term::Term(const Term &t) : _coef(t.coef()), _mon(t.mon()) {

}

Term::Term(Term &&t) noexcept  : _coef(t.coef()), _mon(std::move(t.mon())) {
}
