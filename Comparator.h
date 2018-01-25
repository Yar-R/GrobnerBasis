//
// Created by yaroslav on 09.01.18.
//

#ifndef GROBNERBASIS_COMPARATOR_H
#define GROBNERBASIS_COMPARATOR_H

#include <functional>
#include "Monomial.h"

class Comparator {
public:
    virtual bool operator()(const Monomial& a, const Monomial& b) = 0;
    std::function<bool(const Monomial&, const Monomial&)>  get_cmp_func();
};

class LexComparator: public Comparator {
public:
    bool operator()(const Monomial& a, const Monomial& b) override ;
};

class GrlexComparator : public Comparator {
public:
    bool operator()(const Monomial& a, const Monomial& b) override ;
};

class GrevlexComparator : public Comparator {
public:
    bool operator()(const Monomial& a, const Monomial& b) override ;
};

#endif //GROBNERBASIS_COMPARATOR_H
