//
// Created by Yaroslav Rebenko on 20.07.2018.
//

#ifndef GROBNERBASIS_MONOMIAL_H
#define GROBNERBASIS_MONOMIAL_H

#include <vector>

template<typename Pow>
using Monomial = std::vector<Pow>;

template<typename Pow>
Monomial<Pow>& operator*=(Monomial<Pow>& first, const Monomial<Pow>& second) {
    size_t i = 0;
    for (; i < first.size() && i < second.size(); ++i)
        first[i] += second[i];
    for (; i < second.size(); ++i)
        first.push_back(second[i]);
    return first;
}

template<typename Pow>
Monomial<Pow> operator*(const Monomial<Pow>& a, const Monomial<Pow>& b) {
    auto c = a;
    c *= b;
    return c;
}

#endif //GROBNERBASIS_MONOMIAL_H
