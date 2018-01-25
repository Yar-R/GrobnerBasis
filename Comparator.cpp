//
// Created by yaroslav on 09.01.18.
//

#include <iostream>
#include "Comparator.h"


std::function<bool(const Monomial &, const Monomial &)> Comparator::get_cmp_func() {
    return [this](const Monomial &a, const Monomial &b)->bool{ return this->operator()(a, b);};
}


bool LexComparator::operator()(const Monomial &a, const Monomial &b) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}


bool GrlexComparator::operator()(const Monomial &a, const Monomial &b) {
    base_type sum_a = 0, sum_b = 0;
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


bool GrevlexComparator::operator()(const Monomial &a, const Monomial &b) {
    base_type sum_a = 0, sum_b = 0;
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

