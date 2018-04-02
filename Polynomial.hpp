//
// Created by yaroslav on 09.01.18.
//

#ifndef GROBNERBASIS_POLYNOMIAL_H
#define GROBNERBASIS_POLYNOMIAL_H

#include <cassert>
#include "Comparator.hpp"
#include "Term.hpp"

template<typename CoefType, typename PowType>
class Polynomial : public std::vector<Term<CoefType, PowType>> {
private:
    bool sorted = false;
public:
    using std::vector<Term<CoefType, PowType>>::vector;

    void sort_by(std::shared_ptr<Comparator<CoefType, PowType>> cmp);

    std::shared_ptr<Comparator<CoefType, PowType>> cmp();

    std::shared_ptr<Comparator<CoefType, PowType>> cmp() const;

    void __0_fix__();
    void __0_fix__() const;

    CoefType& LC();

    const CoefType& LC() const;

    Monomial<PowType>& LM();

    const Monomial<PowType>& LM() const;

    Term<CoefType, PowType>& LT();

    const Term<CoefType, PowType>& LT() const;

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
void Polynomial<CoefType, PowType>::sort_by(std::shared_ptr<Comparator<CoefType, PowType>> ptr) {
    Proxy<CoefType, PowType> p(ptr);
    std::sort(this->begin(), this->end(), p);
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

template<typename CoefType, typename PowType>
CoefType& Polynomial<CoefType, PowType>::LC() {
    if (this->empty())
        this->__0_fix__();
    return this->front().coef();
}

template<typename CoefType, typename PowType>
const CoefType& Polynomial<CoefType, PowType>::LC() const {
    if (this->empty())
        this->__0_fix__();
    return this->front().coef();
}

template<typename CoefType, typename PowType>
Monomial<PowType>& Polynomial<CoefType, PowType>::LM() {
    if (this->empty())
        this->__0_fix__();
    return this->front().mon();
}

template<typename CoefType, typename PowType>
const Monomial<PowType>& Polynomial<CoefType, PowType>::LM() const {
    if (this->empty())
        this->__0_fix__();
    return this->front().mon();
}

template<typename CoefType, typename PowType>
Term<CoefType, PowType>& Polynomial<CoefType, PowType>::LT() {
    if (this->empty())
        this->__0_fix__();
    return this->front();
}

template<typename CoefType, typename PowType>
const Term<CoefType, PowType>& Polynomial<CoefType, PowType>::LT() const {
    if (this->empty())
        this->__0_fix__();
    return this->front();
}

template<typename CoefType, typename PowType>
void Polynomial<CoefType, PowType>::__0_fix__() {
    this->push_back(Term<CoefType, PowType>());
}

template<typename CoefType, typename PowType>
void Polynomial<CoefType, PowType>::__0_fix__() const {
    this->push_back(Term<CoefType, PowType>());
}

#endif //GROBNERBASIS_POLYNOMIAL_H
