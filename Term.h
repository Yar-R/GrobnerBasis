//
// Created by yaroslav on 5/12/18.
//

#ifndef GROBNERBASIS_TERM_H
#define GROBNERBASIS_TERM_H


#include "Monomial.h"

class Term {
private:
    double _coef;
    Monomial _mon;
public:
    Term(double c, const Monomial& m);
    Term(double c, Monomial&& m);
    Term(const Term& t);
    Term(Term&& t) noexcept;

    double &coef();

    const double &coef() const;

    Monomial &mon();

    const Monomial &mon() const;

    Term operator-() const;

    Term &operator+=(const Term &other);

    Term &operator-=(const Term &other);

    Term &operator*=(const Term &other);

    Term &operator/=(const Term &other);

    friend Term operator+(const Term &a, const Term &b);

    friend Term operator-(const Term &a, const Term &b);

    friend Term operator*(const Term &a, const Term &b);

    friend Term operator/(const Term &a, const Term &b);

    Term &operator*=(const double &other);

    Term &operator/=(const double &other);

    Term &operator*=(const Monomial &other);

    Term &operator/=(const Monomial &other);

    friend Term operator*(const Term &a, const double &b);

    friend Term operator/(const Term &a, const double &b);

    friend Term operator*(const Term &a, const Monomial &b);

    friend Term operator/(const Term &a, const Monomial &b);

};


#endif //GROBNERBASIS_TERM_H
