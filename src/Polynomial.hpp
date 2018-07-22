//
// Created by Yaroslav Rebenko on 20.07.2018.
//

#ifndef GROBNERBASIS_POLYNOMIAL_H
#define GROBNERBASIS_POLYNOMIAL_H

#include <vector>
#include <queue>
#include "Term.hpp"
#include "Monomial.hpp"
#include "Comparator.hpp"

typedef std::vector<Term<double, Monomial<int64_t>>> Polynomial;

Polynomial& operator +=(Polynomial& a, const Term<double, Monomial<int64_t>>& b) {
    if (!a.empty() && a.back().monom == b.monom) {
        a.back().coef += b.coef;
    } else {
        a.push_back(b);
    }
    return a;
}

Polynomial& operator *=(Polynomial& a, const Term<double, Monomial<int64_t>>& b) {
    for (auto& element : a) {
        element *= b;
    }
    return a;
}

Polynomial operator+(const Polynomial& a, const Term<double, Monomial<int64_t>>& b) {
    auto ans = a;
    ans += b;
    return ans;
}

Polynomial operator*(const Polynomial& a, const Term<double, Monomial<int64_t>>& b) {
    auto ans = a;
    ans *= b;
    return ans;
}

Polynomial add(const Comparator<int64_t>& cmp, const Polynomial& a, const Polynomial& b) {
    size_t i = 0;
    size_t j = 0;
    Polynomial ans;
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

Polynomial mul(const Comparator<int64_t>& cmp, const Polynomial& a, const Polynomial& b) {
    Polynomial ans;
    std::vector<size_t> indexes(b.size());
    auto cmp2 = [&cmp](const std::pair<size_t, Term<double, Monomial<int64_t>>>& a, const std::pair<size_t, Term<double, Monomial<int64_t>>>& b) mutable {
        return cmp(b.second.monom, a.second.monom);
    };
    std::priority_queue<std::pair<size_t, Term<double, Monomial<int64_t>>>, std::vector<std::pair<size_t, Term<double, Monomial<int64_t>>>>, decltype(cmp2)> queue(cmp2);
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