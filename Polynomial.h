//
// Created by yaroslav on 5/12/18.
//

#ifndef GROBNERBASIS_POLYNOMIAL_H
#define GROBNERBASIS_POLYNOMIAL_H


#include <vector>
#include "Term.h"
#include "Comparator.h"

class Polynomial : public std::vector<Term> {
private:
    Polynomial &add_term_to_end(const Term &term);

public:
    using std::vector<Term>::vector;

    Polynomial operator-() const;

    Polynomial &add(const Comparator &cmp, const Polynomial &other);

    Polynomial &dec(const Comparator &cmp, const Polynomial &other);

    Polynomial &operator*=(const double &other);

    Polynomial &operator*=(const Monomial &other);

    Polynomial &operator*=(const Term &other);

    Polynomial &mul(const Comparator &cmp, const Polynomial &other);

    friend Polynomial add(const Comparator &cmp, const Polynomial &a, const Polynomial &b);

    friend Polynomial add_many(const Comparator &cmp, const std::vector<Polynomial> &polys);

    friend Polynomial dec(const Comparator &cmp, const Polynomial &a, const Polynomial &b);

    friend Polynomial operator*(const Polynomial &a, const double &other);

    friend Polynomial operator*(const Polynomial &a, const Monomial &other);

    friend Polynomial operator*(const Polynomial &a, const Term &other);

    friend Polynomial multiply(const Comparator &cmp, const Polynomial &a, const Polynomial &b);
};

Polynomial spol(const Comparator& cmp, const Polynomial& a, const Polynomial& b);

Polynomial reduce(const Comparator& cmp, const Polynomial& f, const Polynomial& g, size_t idx);

#endif //GROBNERBASIS_POLYNOMIAL_H
