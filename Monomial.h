//
// Created by yaroslav on 5/12/18.
//

#ifndef GROBNERBASIS_MONOMIAL_H
#define GROBNERBASIS_MONOMIAL_H


#include <cstdint>
#include <vector>

class Monomial : public std::vector<uint64_t> {
public:
    using std::vector<uint64_t>::vector;

    Monomial &operator*=(const Monomial &other);

    Monomial &operator/=(const Monomial &other);

    friend Monomial operator*(const Monomial &a, const Monomial &b);

    friend Monomial operator/(const Monomial &a, const Monomial &b);

    uint64_t pow() const;
};

Monomial gcd(const Monomial &a, const Monomial &b);

#endif //GROBNERBASIS_MONOMIAL_H
