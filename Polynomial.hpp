//
// Created by yaroslav on 09.01.18.
//

#ifndef GROBNERBASIS_POLYNOMIAL_H
#define GROBNERBASIS_POLYNOMIAL_H

#include "Comparator.hpp"
#include "Term.hpp"

template<typename CoefType, typename PowType>
class Polynomial : public std::vector<Term<CoefType, PowType>> {
private:
    std::shared_ptr<Comparator<CoefType, PowType>> sort_order = nullptr;
public:
    using std::vector<Term<CoefType, PowType>>::vector;

    void sort_by(std::shared_ptr<Comparator<CoefType, PowType>> cmp);

    std::shared_ptr<Comparator<CoefType, PowType>> cmp();

    std::shared_ptr<Comparator<CoefType, PowType>> cmp() const;

    template<typename T1, typename T2>
    friend std::ostream &operator<<(std::ostream &os, const Polynomial<T1, T2> &a);

    template<typename T1, typename T2>
    friend Polynomial<T1, T2> operator/(const Polynomial<T1, T2> &a, const Polynomial<T1, T2> &b);

    template<typename T1, typename T2>
    friend Polynomial<T1, T2> operator*(const Polynomial<T1, T2> &a, const Polynomial<T1, T2> &b);

    template<typename T1, typename T2>
    friend Polynomial<T1, T2> operator+(const Polynomial<T1, T2> &a, const Polynomial<T1, T2> &b);

    template<typename T1, typename T2>
    friend Polynomial<T1, T2> operator-(const Polynomial<T1, T2> &a, const Polynomial<T1, T2> &b);

};

template<typename CoefType, typename PowType>
void Polynomial<CoefType, PowType>::sort_by(std::shared_ptr<Comparator<CoefType, PowType>> cmp) {
    if (this->sort_order != cmp) { // weak optimisation condition to prevent double sort
        std::sort(this->begin(), this->end(), Proxy<CoefType, PowType>(cmp));
        this->sort_order = cmp;
    }
}

template<typename CoefType, typename PowType>
std::shared_ptr<Comparator<CoefType, PowType>> Polynomial<CoefType, PowType>::cmp() {
    return this->sort_order;
}

template<typename CoefType, typename PowType>
std::shared_ptr<Comparator<CoefType, PowType>> Polynomial<CoefType, PowType>::cmp() const {
    return this->sort_order;
}

template<typename CoefType, typename powType>
std::ostream &operator<<(std::ostream &os, const Polynomial<CoefType, powType> &a) {
    for (size_t i = 0; i < a.size() - 1; ++i) {
        os << a[i] << "+";
    }
    if (a.size()) {
        os << a[a.size() - 1];
    } else {
        os << 0;
    }
}

#endif //GROBNERBASIS_POLYNOMIAL_H
