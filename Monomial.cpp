//
// Created by yaroslav on 03.01.18.
//

#include <cstdint>
#include <cstddef>
#include "Monomial.h"

Monomial::Monomial() = default;

Monomial::Monomial(Monomial &&_mon) noexcept {
    this->powers.resize(_mon.size());
    std::copy(_mon.powers.begin(), _mon.powers.end(), this->powers.begin());
}

Monomial::Monomial(const Monomial &_mon) {
    this->powers.resize(_mon.size());
    std::copy(_mon.powers.begin(), _mon.powers.end(), this->powers.begin());
}

Monomial::Monomial(std::initializer_list<base_type> &&list) {
    this->powers.clear();
    this->powers = std::vector<base_type>(list);
}

Monomial::Monomial(std::vector<base_type> &&_data) noexcept {
    this->powers.resize(_data.size());
    std::copy(_data.begin(), _data.end(), this->powers.begin());
}

Monomial::Monomial(const std::vector<base_type> &_data) {
    this->powers.resize(_data.size());
    std::copy(_data.begin(), _data.end(), this->powers.begin());
}

bool operator==(const Monomial &a, const Monomial &b) {
    return a.powers == b.powers;
}

Monomial &Monomial::operator=(const Monomial &_mon) {
    this->powers.resize(_mon.size());
    std::copy(_mon.powers.begin(), _mon.powers.end(), this->powers.begin());
    return *this;
}

Monomial &Monomial::operator=(Monomial &&_mon) noexcept {
    this->powers.resize(_mon.size());
    std::copy(_mon.powers.begin(), _mon.powers.end(), this->powers.begin());
    return *this;
}

Monomial operator*(const Monomial &a, const Monomial &b) {
    Monomial ans = a;
    ans *= b;
    return ans;
}

Monomial &Monomial::operator*=(const Monomial &other) {
    for (size_t idx = 0; idx < this->powers.size(); ++idx) {
        this->powers[idx] += other.powers[idx];
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Monomial &a) {
    for (size_t i = 0; i < a.powers.size(); ++i) {
        if (a.powers[i]) {
            os << "x_{" << i << "}^{" << a.powers[i] << "}";
        }
    }
    return os;
}

size_t Monomial::size() const {
    return this->powers.size();
}

size_t Monomial::size() {
    return this->powers.size();
}

const base_type &Monomial::operator[](size_t idx) const {
    return this->powers[idx];
}

base_type &Monomial::operator[](size_t idx) {
    return this->powers[idx];
}
