//
// Created by yaroslav on 5/12/18.
//

#ifndef GROBNERBASIS_POLIC_H
#define GROBNERBASIS_POLIC_H


#include <cstdint>
#include <vector>
#include "Polynomial.h"
#include "Monic.h"
#include "MonicComparator.h"

class Polic : public std::vector<Monic> {
    void add_term_to_end(const Monic &m);

public:
    using std::vector<Monic>::vector;

    Polynomial bar(const Comparator &cmp, const std::vector<Polynomial> &F) const;

    Polic sig() const;

    Polic operator-() const;

    friend Polic add_many(const MonicComparator &cmp, const std::vector<Polic> &polys);

    Polic &add(const MonicComparator &cmp, const Polic &other);

    friend Polic add(const MonicComparator &cmp, const Polic &a, const Polic &b);

    Polic &dec(const MonicComparator &cmp, const Polic &other);

    Polic &operator*=(const double other);

    Polic &operator*=(const Monomial &other);

    Polic &operator*=(const Term &other);

    friend Polic operator*(const Polic &a, const double other);

    friend Polic operator*(const Polic &a, const Monomial &other);

    friend Polic operator*(const Polic &a, const Term &other);
};

Polic
reduce(const MonicComparator &cmp, const std::vector<Polynomial> &F, const Polic &a, const Polic &b, const Term &t) {
    auto c = t / (b.bar(cmp, F)[0]);
    return add(cmp, a, -(b * c));
}


#endif //GROBNERBASIS_POLIC_H
