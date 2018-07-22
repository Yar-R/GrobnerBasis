//
// Created by yaroslav on 5/12/18.
//

#include "Monomial.h"

Monomial &Monomial::operator*=(const Monomial &other) {
    for (size_t i = 0; i < other.size(); ++i) {
        if (i < size()) {
            this->at(i) += other[i];
        } else {
            this->push_back(other[i]);
        }
    }
}

Monomial &Monomial::operator/=(const Monomial &other) {
    for (size_t i = 0; i < other.size(); ++i) {
        if (i < size()) {
            if (this->at(i) >= other[i])
                this->at(i) -= other[i];
            else
                throw std::exception();
        } else
            throw std::exception();
    }
}

Monomial operator*(const Monomial &a, const Monomial &b) {
    auto ans = a;
    ans *= b;
    return ans;
}

Monomial operator/(const Monomial &a, const Monomial &b) {
    auto ans = a;
    ans /= b;
    return ans;
}

Monomial gcd(const Monomial &a, const Monomial &b) {
    auto ans = Monomial();
    size_t i = 0;
    for (; i < a.size() && i < b.size(); ++i) {
        ans.push_back(std::min(a[i], b[i]));
    }
    for (; i < a.size() || i < b.size(); ++i) {
        ans.push_back(0);
    }
    return ans;
}