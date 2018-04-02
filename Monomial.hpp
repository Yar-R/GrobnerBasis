//
// Created by yaroslav on 03.01.18.
//

#ifndef GROBNERBASIS_MONOMIAL_H
#define GROBNERBASIS_MONOMIAL_H

#include <vector>
#include <cstdint>
#include <ostream>

template<typename ValT>
class Monomial : public std::vector<ValT> {
public:
    using std::vector<ValT>::vector;

    Monomial<ValT> &operator*=(const Monomial<ValT> &other);

    template<typename T>
    friend Monomial<T> operator*(const Monomial<T> &a, const Monomial<T> &b);

    template<typename T>
    friend std::pair<Monomial<T>, bool> operator/(const Monomial<T> &a, const Monomial<T> &b);

    template<typename T>
    friend std::ostream &operator<<(std::ostream &os, const Monomial<T> &a);
};

template<typename ValT>
Monomial<ValT> operator*(const Monomial<ValT> &a, const Monomial<ValT> &b) {
    Monomial<ValT> ans = a;
    ans *= b;
    return ans;
}

template<typename ValT>
Monomial<ValT> &Monomial<ValT>::operator*=(const Monomial<ValT> &other) {
    for (size_t idx = 0; idx < this->powers.size(); ++idx) {
        this->powers[idx] += other.powers[idx];
    }
    return *this;
}

template<typename ValT>
std::ostream &operator<<(std::ostream &os, const Monomial<ValT> &a) {
    if (a.empty()) {
        os << 0;
        return os;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] == 1) {
            os << "x_{" << i << "}";
        } else if (a[i]) {
            os << "x_{" << i << "}^{" << a[i] << "}";
        }
    }
    return os;
}

template<typename ValT>
std::pair<Monomial<ValT>, bool> operator/(const Monomial<ValT> &a, const Monomial<ValT> &b) {
    Monomial<ValT> ans(a);
    for (size_t i = 0; i < a.size(); ++i) {
        if (ans[i] >= b[i]) {
            ans[i] -= b[i];
        } else {
            return std::make_pair(a, false);
        }
    }
    return std::make_pair(ans, true);
}


#endif //GROBNERBASIS_MONOMIAL_H
