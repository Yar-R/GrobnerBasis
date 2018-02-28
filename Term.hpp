//
// Created by yaroslav on 12.01.18.
//

#ifndef GROBNERBASIS_TERM_H
#define GROBNERBASIS_TERM_H


#include "Monomial.hpp"

template <typename ValT>
class Term {
    double coefficient;
    Monomial<ValT> monomial;
public:
    Term<ValT>() = default;
    Term<ValT>(Term<ValT> &&_t) noexcept;
    Term<ValT>(const Term<ValT>& _t);
    Term<ValT>(Monomial<ValT>&& mon, double coef);
    Term<ValT>(const Monomial<ValT>& mon, double coef);
    Term<ValT>& operator=(Term<ValT>&& t) noexcept ;
    Term<ValT>& operator=(const Term<ValT>& t);
    Term<ValT>& operator*=(const Term<ValT>& other);
    const Monomial<ValT>& mon();
    const double coef();
    const Monomial<ValT>& mon() const;
    const double coef() const;
    template <typename T>
    friend bool operator==(const Term<T>& a, const Term<T>& b);
    template <typename T>
    friend Term<T> operator*(const Term<T>& a, const Term<T>& b);
    template <typename T>
    friend std::pair<Term<T>, bool> operator/(const Term<T>& a, const Term<T>& b);
    template <typename T>
    friend std::ostream& operator<<(std::ostream& os, const Term<T>& t);
};

template <typename ValT>
Term<ValT>::Term(Term<ValT> &&_t) noexcept : coefficient(_t.coefficient), monomial(_t.monomial) {}

template <typename ValT>
Term<ValT>::Term(const Term<ValT> &_t)  : coefficient(_t.coefficient), monomial(_t.monomial) {}

template <typename ValT>
Term<ValT>::Term(Monomial<ValT> &&mon, double coef) : coefficient(coef), monomial(mon) {}

template <typename ValT>
Term<ValT>::Term(const Monomial<ValT> &mon, double coef) : coefficient(coef), monomial(mon) {}

template <typename ValT>
Term<ValT> &Term<ValT>::operator=(Term<ValT> &&t) noexcept {
    this->coefficient = t.coefficient;
    this->monomial = t.monomial;
    return *this;
}

template <typename ValT>
Term<ValT> &Term<ValT>::operator=(const Term<ValT> &t) {
    this->coefficient = t.coefficient;
    this->monomial = t.monomial;
    return *this;
}

template <typename ValT>
Term<ValT> &Term<ValT>::operator*=(const Term<ValT> &other) {
    this->coefficient *= other.coefficient;
    this->monomial *= other.monomial;
    return *this;;
}

template <typename T>
bool operator==(const Term<T> &a, const Term<T> &b) {
    return a.coefficient == b.coefficient && a.monomial == b.monomial;
}

template <typename T>
Term<T> operator*(const Term<T> &a, const Term<T> &b) {
    Term<T> ans(a);
    ans *= b;
    return ans;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Term<T> &t) {
    os << t.coefficient << t.monomial;
    return os;
}

template <typename T>
std::pair<Term<T>, bool> operator/(const Term<T> &a, const Term<T> &b) {
    auto tmp = a.monomial / b.monomial;
    if (!tmp.second) {
        return std::make_pair(a, false);
    } else {
        return std::make_pair(Term<T>(tmp.first, a.coefficient / b.coefficient), true);
    }
}

template<typename ValT>
const Monomial<ValT> &Term<ValT>::mon() {
    return this->monomial;
}

template<typename ValT>
const double Term<ValT>::coef() {
    return this->coefficient;
}

template<typename ValT>
const Monomial<ValT> &Term<ValT>::mon() const {
    return this->monomial;
}

template<typename ValT>
const double Term<ValT>::coef() const {
    return this->coefficient;
}

#endif //GROBNERBASIS_TERM_H
