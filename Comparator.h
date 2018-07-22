//
// Created by yaroslav on 5/12/18.
//

#ifndef GROBNERBASIS_COMPARATOR_H
#define GROBNERBASIS_COMPARATOR_H

#include <functional>
#include "Monomial.h"

class Comparator {
public:

    template<typename C>
    Comparator(C &cmp) {
        call_m = std::function<bool(const Monomial &a, const Monomial &b)>(
                [&cmp](const Monomial &a, const Monomial &b) -> bool {
                    return cmp(a, b);
                });
    }

    bool operator()(const Monomial &a, const Monomial &b) const {
        return call_m(a, b);
    }

private:
    std::function<bool(const Monomial &a, const Monomial &b)> call_m;
};

class Lex {
public:
    bool operator()(const Monomial &a, const Monomial &b);
};

class Grlex {
public:;

    bool operator()(const Monomial &a, const Monomial &b);
};

class Grevlex {
public:
    bool operator()(const Monomial &a, const Monomial &b);
};

#endif //GROBNERBASIS_COMPARATOR_H
