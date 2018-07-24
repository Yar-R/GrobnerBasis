//
// Created by Yaroslav Rebenko on 20.07.2018.
//

#ifndef GROBNERBASIS_POLYNOMIAL_H
#define GROBNERBASIS_POLYNOMIAL_H

#include <vector>
#include <queue>
#include "Term.hpp"
#include "Monomial.hpp"
#include "MonomialOrder.hpp"

template<typename Coef, typename Pow>
using Polynomial = std::vector<Term<Coef, Monomial<Pow>>>;

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>& operator+=(Polynomial<Coef, Pow>& a, const Term<Coef, Monomial<Pow>>& b) {
    if (!a.empty() && a.back().monom == b.monom) {
        a.back().coef += b.coef;
    } else {
        a.push_back(b);
    }
    return a;
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>& operator*=(Polynomial<Coef, Pow>& a, const Term<Coef, Monomial<Pow>>& b) {
    for (auto& element : a) {
        element *= b;
    }
    return a;
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow> operator+(const Polynomial<Coef, Pow>& a, const Term<Coef, Monomial<Pow>>& b) {
    auto ans = a;
    ans += b;
    return ans;
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow> operator*(const Polynomial<Coef, Pow>& a, const Term<Coef, Monomial<Pow>>& b) {
    auto ans = a;
    ans *= b;
    return ans;
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow> add(const MonomialOrder<Pow>& cmp, const Polynomial<Coef, Pow>& a, const Polynomial<Coef, Pow>& b) {
    size_t i = 0;
    size_t j = 0;
    Polynomial<Coef, Pow> ans;
    while (i < a.size() && j < b.size()) {
        if (cmp(a[i].monom, b[j].monom)) {
            ans += a[i++];
        } else {
            ans += b[j++];
        }
    }
    while (i < a.size()) {
        ans += a[i++];
    }
    while (j < b.size()) {
        ans += b[j++];
    }
    return ans;
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow> mul(const MonomialOrder<Pow>& cmp, const Polynomial<Coef, Pow>& a, const Polynomial<Coef, Pow>& b) {
    Polynomial<Coef, Pow> ans;
    std::vector<size_t> indexes(b.size());
    auto cmp2 = [&cmp](const std::pair<size_t, Term<Coef, Monomial<Pow>>>& a,
                       const std::pair<size_t, Term<Coef, Monomial<Pow>>>& b) mutable {
        return cmp(b.second.monom, a.second.monom);
    };
    std::priority_queue<std::pair<size_t, Term<Coef, Monomial<Pow>>>, std::vector<std::pair<size_t, Term<Coef, Monomial<Pow>>>>, decltype(cmp2)> queue(
            cmp2);
    for (size_t i = 0; i < b.size(); ++i) {
        queue.push(std::make_pair(i, a[0] * b[i]));
    }
    while (!queue.empty()) {
        ans += queue.top().second;
        indexes[queue.top().first]++;
        if (indexes[queue.top().first] < a.size())
            queue.push(std::make_pair(queue.top().first, a[indexes[queue.top().first]] * b[queue.top().first]));
        queue.pop();
    }
    return ans;
}

#endif