//
// Created by yaroslav on 03.01.18.
//

#ifndef GROBNERBASIS_MONOMIAL_H
#define GROBNERBASIS_MONOMIAL_H


#include <vector>
#include <cstdint>
#include <ostream>

template <typename ValT>
class Monomial {
    std::vector<ValT> powers;
public:
    Monomial<ValT>() = default;
    Monomial<ValT>(Monomial<ValT>&& _mon) noexcept;
    Monomial<ValT>(const Monomial<ValT>& _mon);
    Monomial<ValT>(std::initializer_list<ValT>&& list);
    explicit Monomial<ValT>(std::vector<ValT>&& _data) noexcept;
    explicit Monomial<ValT>(const std::vector<ValT>& _data);
    Monomial<ValT>& operator=(const Monomial<ValT>& _mon);
    Monomial<ValT>& operator=(Monomial<ValT>&& _mon) noexcept ;
    Monomial<ValT>& operator*=(const Monomial<ValT>& other);

    template <typename T>
    friend bool operator==(const Monomial<T>& a, const Monomial<T>& b);
    template <typename T>
    friend Monomial<T> operator*(const Monomial<T>& a, const Monomial<T>& b);
    template <typename T>
    friend std::pair<Monomial<T>, bool> operator/(const Monomial<T>& a, const Monomial<T>& b);
    template <typename T>
    friend std::ostream & operator<<(std::ostream & os, const Monomial<T>& a);

    size_t size() const;
    size_t size();
    const ValT& operator[](size_t idx) const;
    ValT& operator[](size_t idx);

    typename std::vector<ValT>::const_iterator begin() const;
    typename std::vector<ValT>::const_iterator end() const;
    typename std::vector<ValT>::iterator begin();
    typename std::vector<ValT>::iterator end();
};


template <typename ValT>
Monomial<ValT>::Monomial(Monomial<ValT> &&_mon) noexcept {
    this->powers.resize(_mon.size());
    std::copy(_mon.powers.begin(), _mon.powers.end(), this->powers.begin());
}

template <typename ValT>
Monomial<ValT>::Monomial(const Monomial<ValT> &_mon) {
    this->powers.resize(_mon.size());
    std::copy(_mon.powers.begin(), _mon.powers.end(), this->powers.begin());
}

template <typename ValT>
Monomial<ValT>::Monomial(std::initializer_list<ValT> &&list) {
    this->powers.clear();
    this->powers = std::vector<ValT>(list);
}

template <typename ValT>
Monomial<ValT>::Monomial(std::vector<ValT> &&_data) noexcept {
    this->powers.resize(_data.size());
    std::copy(_data.begin(), _data.end(), this->powers.begin());
}

template <typename ValT>
Monomial<ValT>::Monomial(const std::vector<ValT> &_data) {
    this->powers.resize(_data.size());
    std::copy(_data.begin(), _data.end(), this->powers.begin());
}

template <typename ValT>
bool operator==(const Monomial<ValT> &a, const Monomial<ValT> &b) {
    return a.powers == b.powers;
}

template <typename ValT>
Monomial<ValT> &Monomial<ValT>::operator=(const Monomial<ValT> &_mon) {
    this->powers.resize(_mon.size());
    std::copy(_mon.powers.begin(), _mon.powers.end(), this->powers.begin());
    return *this;
}

template <typename ValT>
Monomial<ValT> &Monomial<ValT>::operator=(Monomial<ValT> &&_mon) noexcept {
    this->powers.resize(_mon.size());
    std::move(_mon.powers.begin(), _mon.powers.end(), this->powers.begin());
    return *this;
}

template <typename ValT>
Monomial<ValT> operator*(const Monomial<ValT> &a, const Monomial<ValT> &b) {
    Monomial<ValT> ans = a;
    ans *= b;
    return ans;
}

template <typename ValT>
Monomial<ValT> &Monomial<ValT>::operator*=(const Monomial<ValT> &other) {
    for (size_t idx = 0; idx < this->powers.size(); ++idx) {
        this->powers[idx] += other.powers[idx];
    }
    return *this;
}

template <typename ValT>
std::ostream &operator<<(std::ostream &os, const Monomial<ValT> &a) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] ==  1) {
            os << "x_{" << i << "}";
        } else if (a[i]) {
            os << "x_{" << i << "}^{" << a[i] << "}";
        }
    }
    return os;
}

template <typename ValT>
size_t Monomial<ValT>::size() const {
    return this->powers.size();
}

template <typename ValT>
size_t Monomial<ValT>::size() {
    return this->powers.size();
}

template <typename ValT>
const ValT &Monomial<ValT>::operator[](size_t idx) const {
    return this->powers[idx];
}

template <typename ValT>
ValT &Monomial<ValT>::operator[](size_t idx) {
    return this->powers[idx];
}

template <typename ValT>
typename std::vector<ValT>::const_iterator Monomial<ValT>::begin() const {
    return this->powers.begin();
}

template <typename ValT>
typename std::vector<ValT>::const_iterator Monomial<ValT>::end() const {
    return this->powers.end();
}

template <typename ValT>
typename std::vector<ValT>::iterator Monomial<ValT>::begin() {
    return this->powers.begin();
}

template <typename ValT>
typename std::vector<ValT>::iterator Monomial<ValT>::end() {
    return this->powers.end();
}

template <typename ValT>
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
