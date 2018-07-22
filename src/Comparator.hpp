//
// Created by Yaroslav Rebenko on 21.07.2018.
//

#ifndef GROBNERBASIS_COMPARATOR_H
#define GROBNERBASIS_COMPARATOR_H

#include "Monomial.hpp"

template <typename Pow>
class Comparator {
public:
    virtual bool operator()(const Monomial<Pow>& a, const Monomial<Pow>& b) const = 0;
};

template <typename Pow>
class Lex : public Comparator<Pow> {
    bool operator()(const Monomial<Pow>& a, const Monomial<Pow>& b) const final;
};

template<typename Pow>
bool Lex<Pow>::operator()(const Monomial<Pow> &a, const Monomial<Pow> &b) const{
    size_t i = 0;
    for (; i < a.size() && i < b.size(); ++i) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return i < a.size();
}

#endif //GROBNERBASIS_COMPARATOR_H
