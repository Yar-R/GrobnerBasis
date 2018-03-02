//
// Created by yaroslav on 12.01.18.
//

#ifndef GROBNERBASIS_TERM_H
#define GROBNERBASIS_TERM_H


#include "Monomial.hpp"

template<typename CoefType, typename PowType>
class Term {
    CoefType coefficient;
    Monomial<PowType> monomial;
public:
    Term<CoefType, PowType>() = default;

    Term<CoefType, PowType>(Term<CoefType, PowType> &&_t) noexcept;

    Term<CoefType, PowType>(const Term<CoefType, PowType> &_t);

    Term<CoefType, PowType>(Monomial<PowType> &&mon, CoefType coef);

    Term<CoefType, PowType>(const Monomial<PowType> &mon, CoefType coef);

    Term<CoefType, PowType> &operator=(Term<CoefType, PowType> &&t) noexcept;

    Term<CoefType, PowType> &operator=(const Term<CoefType, PowType> &t);

    Term<CoefType, PowType> &operator*=(const Term<CoefType, PowType> &other);

    const Monomial<PowType> &mon();

    const CoefType& coef();

    const Monomial<PowType> &mon() const;

    const CoefType& coef() const;

    template<typename T1, typename T2>
    friend bool operator==(const Term<T1, T2> &a, const Term<T1, T2> &b);

    template<typename T1, typename T2>
    friend Term<T1, T2> operator*(const Term<T1, T2> &a, const Term<T1, T2> &b);

    template<typename T1, typename T2>
    friend std::pair<Term<T1, T2>, bool> operator/(const Term<T1, T2> &a, const Term<T1, T2> &b);

    template<typename T1, typename T2>
    friend std::ostream &operator<<(std::ostream &os, const Term<T1, T2> &t);
};

template<typename CoefType, typename PowType>
Term<CoefType, PowType>::Term(Term<CoefType, PowType> &&_t) noexcept : coefficient(_t.coefficient),
                                                                       monomial(_t.monomial) {}

template<typename CoefType, typename PowType>
Term<CoefType, PowType>::Term(const Term<CoefType, PowType> &_t)  : coefficient(_t.coefficient),
                                                                    monomial(_t.monomial) {}

template<typename CoefType, typename PowType>
Term<CoefType, PowType>::Term(Monomial<PowType> &&mon, CoefType coef) : coefficient(coef), monomial(mon) {}

template<typename CoefType, typename PowType>
Term<CoefType, PowType>::Term(const Monomial<PowType> &mon, CoefType coef) : coefficient(coef), monomial(mon) {}

template<typename CoefType, typename PowType>
Term<CoefType, PowType> &Term<CoefType, PowType>::operator=(Term<CoefType, PowType> &&t) noexcept {
    this->coefficient = t.coefficient;
    this->monomial = t.monomial;
    return *this;
}

template<typename CoefType, typename PowType>
Term<CoefType, PowType> &Term<CoefType, PowType>::operator=(const Term<CoefType, PowType> &t) {
    this->coefficient = t.coefficient;
    this->monomial = t.monomial;
    return *this;
}

template<typename CoefType, typename PowType>
Term<CoefType, PowType> &Term<CoefType, PowType>::operator*=(const Term<CoefType, PowType> &other) {
    this->coefficient *= other.coefficient;
    this->monomial *= other.monomial;
    return *this;;
}

template<typename CoefType, typename PowType>
bool operator==(const Term<CoefType, PowType> &a, const Term<CoefType, PowType> &b) {
    return a.coefficient == b.coefficient && a.monomial == b.monomial;
}

template<typename CoefType, typename PowType>
Term<CoefType, PowType> operator*(const Term<CoefType, PowType> &a, const Term<CoefType, PowType> &b) {
    Term<CoefType, PowType> ans(a);
    ans *= b;
    return ans;
}

template<typename CoefType, typename PowType>
std::ostream &operator<<(std::ostream &os, const Term<CoefType, PowType> &t) {
    os << t.coefficient << t.monomial;
    return os;
}

template<typename CoefType, typename PowType>
std::pair<Term<CoefType, PowType>, bool> operator/(const Term<CoefType, PowType> &a, const Term<CoefType, PowType> &b) {
    auto tmp = a.monomial / b.monomial;
    if (!tmp.second) {
        return std::make_pair(a, false);
    } else {
        return std::make_pair(Term<CoefType, PowType>(tmp.first, a.coefficient / b.coefficient), true);
    }
}

template<typename CoefType, typename PowType>
const Monomial<PowType> &Term<CoefType, PowType>::mon() {
    return this->monomial;
}

template<typename CoefType, typename PowType>
const CoefType &Term<CoefType, PowType>::coef() {
    return this->coefficient;
}

template<typename CoefType, typename PowType>
const Monomial<PowType> &Term<CoefType, PowType>::mon() const {
    return this->monomial;
}

template<typename CoefType, typename PowType>
const CoefType &Term<CoefType, PowType>::coef() const {
    return this->coefficient;
}

#endif //GROBNERBASIS_TERM_H
