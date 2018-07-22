//
// Created by yaroslav on 5/13/18.
//

#ifndef GROBNERBASIS_MONICCOMPARATOR_H
#define GROBNERBASIS_MONICCOMPARATOR_H


#include <functional>
#include "Monomial.h"
#include "Monic.h"

class MonicComparator {
private:
    std::function<bool(const Monic &a, const Monic &b)> _monic_cmp;
    std::function<bool(const Monomial &a, const Monomial &b)> _monomial_cmp;
public:
    template<typename MC>
    MonicComparator(MC &cmp) {
        _monomial_cmp = std::function<bool(const Monomial &a, const Monomial &b)>(
                [&cmp](const Monomial &a, const Monomial &b) -> bool {
                    return cmp(a, b);
                });
        _monic_cmp = std::function<bool(const Monic &a, const Monic &b)>(
                [&cmp](const Monic &a, const Monic &b) -> bool {
                    return cmp(a, b);
                });
    }

    bool operator()(const Monic &a, const Monic &b) const {
        return _monic_cmp(a, b);
    }

    bool operator()(const Monomial &a, const Monomial &b) const {
        return _monomial_cmp(a, b);
    }
};

class Pot {
private:
    Comparator &cmp;
public:
    Pot(Comparator &_cmp) : cmp(_cmp) {};

    bool operator()(const Monic &a, const Monic &b) const {
        if (a.axis() == b.axis()) {
            return cmp(a.coef().mon(), b.coef().mon());
        }
        return a.axis() < b.axis();
    }

    bool operator()(const Monomial &a, const Monomial &b) const {
        return cmp(a, b);
    }
};

class Top {
private:
    Comparator &cmp;
public:
    Top(Comparator &_cmp) : cmp(_cmp) {};

    bool operator()(const Monic &a, const Monic &b) const {
        if (a.coef().mon() == b.coef().mon()) {
            return a.axis() < b.axis();
        }
        return a.coef().mon() < b.coef().mon();
    }

    bool operator()(const Monomial &a, const Monomial &b) const {
        return cmp(a, b);
    }
};

class GrMonic {
private:
    MonicComparator &cmp;
public:
    GrMonic(MonicComparator&_cmp) : cmp(_cmp) {};

    bool operator()(const Monic &a, const Monic &b) const {
        auto _a = a.coef().mon().pow();
        auto _b = b.coef().mon().pow();
        if (_a == _b) {
            return cmp(a, b);
        }
        return _a < _b;
    }

    bool operator()(const Monomial &a, const Monomial &b) const {
        return cmp(a, b);
    }
};


#endif //GROBNERBASIS_MONICCOMPARATOR_H
