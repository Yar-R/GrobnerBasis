//
// Created by yaroslav on 09.01.18.
//

#ifndef GROBNERBASIS_COMPARATOR_H
#define GROBNERBASIS_COMPARATOR_H

#include <functional>
#include "Monomial.hpp"
#include "Term.hpp"

template <typename ValT>
class Comparator {
public:
    virtual bool operator()(const Monomial<ValT>& a, const Monomial<ValT>& b) = 0;
    bool operator()(const Term<ValT>& a, const Term<ValT>& b);
    std::function<bool(const Monomial<ValT>&, const Monomial<ValT>&)>  get_cmp_func();
};

template <typename ValT>
class LexComparator: public Comparator<ValT> {
public:
    bool operator()(const Monomial<ValT>& a, const Monomial<ValT>& b) override ;
};

template <typename ValT>
class GrlexComparator : public Comparator<ValT> {
public:
    bool operator()(const Monomial<ValT>& a, const Monomial<ValT>& b) override ;
};

template <typename ValT>
class GrevlexComparator : public Comparator<ValT> {
public:
    bool operator()(const Monomial<ValT>& a, const Monomial<ValT>& b) override ;
};

template <typename ValT>
std::function<bool(const Monomial<ValT> &, const Monomial<ValT> &)> Comparator<ValT>::get_cmp_func() {
    return [this](const Monomial<ValT> &a, const Monomial<ValT> &b)->bool{ return this->operator()(a, b);};
}

template<typename ValT>
bool Comparator<ValT>::operator()(const Term<ValT> &a, const Term<ValT> &b) {
    return this->operator()(a.mon(), b.mon());
}

template <typename ValT>
bool LexComparator<ValT>::operator()(const Monomial<ValT> &a, const Monomial<ValT> &b) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

template <typename ValT>
bool GrlexComparator<ValT>::operator()(const Monomial<ValT> &a, const Monomial<ValT> &b) {
    ValT sum_a = 0, sum_b = 0;
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


template <typename ValT>
bool GrevlexComparator<ValT>::operator()(const Monomial<ValT> &a, const Monomial<ValT> &b) {
    ValT sum_a = 0, sum_b = 0;
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

#endif //GROBNERBASIS_COMPARATOR_H
