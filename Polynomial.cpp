//
// Created by yaroslav on 5/12/18.
//

#include <queue>
#include "Polynomial.h"

Polynomial Polynomial::operator-() const {
    auto ans = Polynomial();
    for (const auto &elem : *this) {
        ans.push_back(-elem);
    }
    return ans;
}

Polynomial &Polynomial::add_term_to_end(const Term &term) {
    if (!empty()) {
        if (back().mon() == term.mon()) {
            back().coef() += term.coef();
        } else {
            push_back(term);
        }
    } else {
        push_back(term);
    }
    if (back().coef() == 0) {
        pop_back();
    }
    return *this;
}

Polynomial &Polynomial::add(const Comparator &cmp, const Polynomial &other) {
    auto ans = add_many(cmp, {*this, other});
    clear();
    std::move(ans.begin(), ans.end(), std::back_inserter(*this));
    return *this;
}

Polynomial &Polynomial::dec(const Comparator &cmp, const Polynomial &other) {
    add(cmp, -other);
    return *this;
}

Polynomial &Polynomial::operator*=(const double &other) {
    for (auto& elem : *this) {
        elem *= other;
    }
    return *this;
}

Polynomial &Polynomial::operator*=(const Monomial &other) {
    for (auto& elem : *this) {
        elem *= other;
    }
    return *this;
}

Polynomial &Polynomial::operator*=(const Term &other) {
    for (auto& elem : *this) {
        elem *= other;
    }
    return *this;
}

Polynomial &Polynomial::mul(const Comparator &cmp, const Polynomial &other) {
    auto ans = multiply(cmp, *this, other);
    clear();
    std::move(ans.begin(), ans.end(), std::back_inserter(*this));
    return *this;
}

Polynomial add(const Comparator &cmp, const Polynomial &a, const Polynomial &b) {
    auto ans = a;
    ans.add(cmp, b);
    return ans;
}

Polynomial add_many(const Comparator &cmp, const std::vector<Polynomial> &polys) {
    auto ans = Polynomial();
    auto _cmp = [cmp](const std::pair<Term, size_t>& a, const std::pair<Term, size_t>& b){
        return cmp(a.first.mon(), b.first.mon());
    };
    std::priority_queue<std::pair<Term, size_t>, std::vector<std::pair<Term, size_t>>, decltype(_cmp)> heap(_cmp);
    std::vector<size_t> a(polys.size(), 1);
    for (size_t i = 0; i < polys.size(); ++i) {
        heap.push(std::make_pair(polys[i][0], i));
    }
    size_t idx;
    while (!heap.empty()) {
        ans.add_term_to_end(heap.top().first);
        idx = heap.top().second;
        heap.pop();
        if (a[idx] < polys[idx].size()) {
            heap.push(std::make_pair(polys[idx][a[idx]], idx));
            ++a[idx];
        }
    }
    return ans;
}

Polynomial dec(const Comparator &cmp, const Polynomial &a, const Polynomial &b) {
    return add_many(cmp, {a, -b});
}

Polynomial operator*(const Polynomial &a, const double &other) {
    auto ans = a;
    ans *= other;
    return ans;
}

Polynomial operator*(const Polynomial &a, const Monomial &other) {
    auto ans = a;
    ans *= other;
    return ans;
}

Polynomial operator*(const Polynomial &a, const Term &other) {
    auto ans = a;
    ans *= other;
    return ans;
}

Polynomial multiply(const Comparator &cmp, const Polynomial &a, const Polynomial &b) {
    auto polys = std::vector<Polynomial>();
    if (a.size() < b.size()) {
        for (const auto& term : a) {
            polys.push_back(b * term);
        }
    } else {
        for (const auto& term : b) {
            polys.push_back(a * term);
        }
    }
    return add_many(cmp, polys);
}

Polynomial reduce(const Comparator &cmp, const Polynomial &f, const Polynomial &g, size_t idx = 0) {
    auto t = f[idx] / g[0];
    return add(cmp, f, -g * t);
}

Polynomial spol(const Comparator& cmp, const Polynomial &a, const Polynomial &b) {
    Monomial l = gcd(a[0].mon(), b[0].mon());
    return (a * (b[0] / l)).dec(cmp, b * (a[0] / l));
}


