//
// Created by yaroslav on 09.01.18.
//

#ifndef GROBNERBASIS_COMPARATOR_H
#define GROBNERBASIS_COMPARATOR_H

#include <functional>
#include <memory>
#include <cassert>
#include "Monomial.hpp"
#include "Term.hpp"

template<typename CoefType, typename PowType>
class Comparator {
public:
    virtual bool operator()(const Monomial<PowType> &a, const Monomial<PowType> &b) = 0;

    std::function<bool(const Monomial<PowType> &, const Monomial<PowType> &)> get_cmp_func();;
};

template<typename CoefType, typename PowType>
class LexComparator : public Comparator<CoefType, PowType> {
public:
    bool operator()(const Monomial<PowType> &a, const Monomial<PowType> &b) override;
};

template<typename CoefType, typename PowType>
class GrlexComparator : public Comparator<CoefType, PowType> {
public:;
    bool operator()(const Monomial<PowType> &a, const Monomial<PowType> &b) override;
};

template<typename CoefType, typename PowType>
class GrevlexComparator : public Comparator<CoefType, PowType> {
public:
    bool operator()(const Monomial<PowType> &a, const Monomial<PowType> &b) override;
};

template<typename CoefType, typename PowType>
std::function<bool(const Monomial<PowType> &, const Monomial<PowType> &)>
Comparator<CoefType, PowType>::get_cmp_func() {
    return [this](const Monomial<PowType> &a, const Monomial<PowType> &b) -> bool { return this->operator()(a, b); };
}

template<typename CoefType, typename PowType>
bool LexComparator<CoefType, PowType>::operator()(const Monomial<PowType> &a, const Monomial<PowType> &b) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

template<typename CoefType, typename PowType>
bool GrlexComparator<CoefType, PowType>::operator()(const Monomial<PowType> &a, const Monomial<PowType> &b) {
    PowType sum_a = 0, sum_b = 0;
    bool ret = false, flag = false;
    for (size_t i = 0; i < a.size(); ++i) {
        sum_a += a[i];
        sum_b += b[i];
        if (a[i] != b[i] && !flag) {
            flag = true;
            ret = a[i] < b[i];
        }
    }
    if (sum_a == sum_b) {
        return ret;
    } else {
        return sum_a < sum_b;
    }
}


template<typename CoefType, typename PowType>
bool GrevlexComparator<CoefType, PowType>::operator()(const Monomial<PowType> &a, const Monomial<PowType> &b) {
    PowType sum_a = 0, sum_b = 0;
    bool ret = false;
    for (size_t i = a.size(); i > 0; --i) {
        sum_a += a[i - 1];
        sum_b += b[i - 1];
        if (a[i - 1] != b[i - 1]) {
            ret = a[i - 1] > b[i - 1];
        }
    }
    if (sum_a == sum_b) {
        return ret;
    } else {
        return sum_a < sum_b;
    }
}

template<typename CoefType, typename PowType>
class Proxy {
private:
    std::shared_ptr<Comparator<CoefType, PowType>> cmp;
    void check();
public:
    explicit Proxy(std::shared_ptr<Comparator<CoefType, PowType>> cmp);
    Proxy();


    bool operator()(const Monomial<PowType> &r1, const Monomial<PowType> &r2);

    bool operator()(const Term<CoefType, PowType> &r1, const Term<CoefType, PowType> &r2);
};

template<typename CoefType, typename PowType>
Proxy<CoefType, PowType>::Proxy(std::shared_ptr<Comparator<CoefType, PowType>> cmp) :cmp(cmp) {}

template<typename CoefType, typename PowType>
bool Proxy<CoefType, PowType>::operator()(const Monomial<PowType> &r1, const Monomial<PowType> &r2) {
    assert(this->cmp == nullptr);
    return this->cmp->operator()(r1, r2);
}

template<typename CoefType, typename PowType>
bool Proxy<CoefType, PowType>::operator()(const Term<CoefType, PowType> &r1, const Term<CoefType, PowType> &r2) {
    this->check();
    return this->cmp->operator()(r1.mon(), r2.mon());
}

template<typename CoefType, typename PowType>
Proxy<CoefType, PowType>::Proxy() {
    this->check();
    this->cmp = nullptr;
}

template<typename CoefType, typename PowType>
void Proxy<CoefType, PowType>::check() {
    assert(this->cmp != nullptr);
};

#endif //GROBNERBASIS_COMPARATOR_H
