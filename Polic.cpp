//
// Created by yaroslav on 5/12/18.
//

#include <queue>
#include "Polic.h"
#include "Polynomial.h"

void Polic::add_term_to_end(const Monic &m) {
    if (empty()) {
        push_back(m);
    } else {
        if (back().axis() == m.axis() && back().coef().mon() == m.coef().mon()) {
            back().coef() += m.coef();
        } else {
            push_back(m);
        }
    }
}

Polynomial Polic::bar(const Comparator &cmp, const std::vector<Polynomial> &F) const {
    if (size() != F.size()) {
        throw std::exception();
    }
    auto ans = std::vector<Polynomial>();
    for (size_t i = 0; i < size(); ++i) {
        ans.push_back(F[i] * at(i).coef());
    }
    return add_many(cmp, ans);
}

Polic Polic::sig() const {
    return Polic(1, at(0));
}

Polic Polic::operator-() const {
    auto ans = *this;
    for (auto &elem : ans) {
        elem.coef() *= -1;
    }
    return ans;
}

Polic &Polic::add(const MonicComparator &cmp, const Polic &other) {
    auto _cmp = std::function<bool(const Monomial &a, const Monomial &b)>([cmp](const Monomial &a, const Monomial &b) -> bool { return cmp(a, b);});
    auto ans = add_many(Comparator(_cmp), {*this, other});
    clear();
    std::move(ans.begin(), ans.end(), std::back_inserter(*this));
    return ans;
}


Polic add(const MonicComparator &cmp, const Polic &a, const Polic &b) {
    auto ans = a;
    ans.add(cmp, b);
    return ans;
}

Polic add_many(const MonicComparator &cmp, const std::vector<Polic> &polys) {
    auto ans = Polic();
    std::priority_queue<std::pair<Monic, size_t>, std::vector<std::pair<Monic, size_t>>, decltype(cmp)> heap(cmp);
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


