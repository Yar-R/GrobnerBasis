//
// Created by yaroslav on 09.01.18.
//

#ifndef GROBNERBASIS_POLYNOMIAL_H
#define GROBNERBASIS_POLYNOMIAL_H

#include <cassert>
#include <queue>
#include "Comparator.hpp"
#include "Term.hpp"

template<typename CoefType, typename PowType>
class Polynomial : public std::vector<Term<CoefType, PowType>> {
private:
    bool sorted = false;
public:
    using std::vector<Term<CoefType, PowType>>::vector;
    using std::vector<Term<CoefType, PowType>>::at;
    using std::vector<Term<CoefType, PowType>>::operator[];

    void sort_by(std::shared_ptr<Comparator<CoefType, PowType>> ptr);

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

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>>&& list);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>>& list);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add_and_substract_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>>&& list_p, std::vector<Polynomial<Coef, Pow>>&& list_n);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add_and_substract_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>>&& list_p, const std::vector<Polynomial<Coef, Pow>>& list_n);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add_and_substract_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>>& list_p, std::vector<Polynomial<Coef, Pow>>&& list_n);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add_and_substract_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>>& list_p, const std::vector<Polynomial<Coef, Pow>>& list_n);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>>&& list);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>>& list);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add_and_substract(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>>&& list_p, std::vector<Polynomial<Coef, Pow>>&& list_n);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add_and_substract(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>>&& list_p, const std::vector<Polynomial<Coef, Pow>>& list_n);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add_and_substract(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>>& list_p, std::vector<Polynomial<Coef, Pow>>&& list_n);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> add_and_substract(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>>& list_p, const std::vector<Polynomial<Coef, Pow>>& list_n);

    template <typename Coef, typename Pow>
    friend Polynomial<Coef, Pow> mul_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, const Polynomial<Coef, Pow>& a, const Polynomial<Coef, Pow>& b);
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

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>
add_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>>&& list) {
    auto ans =  Polynomial<Coef, Pow>();
    auto cmp = [ptr](const std::pair<Term<Coef, Pow>, size_t>& a, const std::pair<Term<Coef, Pow>, size_t>& b) {
        Proxy<Coef, Pow> p(ptr);
        return !p(a.first, b.first);
    };
    Proxy<Coef, Pow> p(ptr);
    std::priority_queue<std::pair<Term<Coef, Pow>, size_t>, std::vector<std::pair<Term<Coef, Pow>, size_t>>, decltype(cmp)> heap(cmp);
    std::vector<size_t> a(list.size(), 1);
    for (size_t i = 0; i < list.size(); ++i) {
        heap.push(std::make_pair(list[i][0], i));
    }
    size_t idx;
    while (!heap.empty()) {
        auto term = heap.top().first;
        if (!ans.empty()) {
            if (ans.back().mon() == term.mon()) {
                ans.back().coef() += term.coef();
            } else {
                ans.push_back(term);
            }
        } else {
            ans.push_back(term);
        }
        idx = heap.top().second;
        heap.pop();
        if (a[idx] < list[idx].size()) {
            heap.push(std::make_pair(list[idx][a[idx]], idx));
            ++a[idx];
        }
    }
    return ans;
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>
add_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>>& list) {
    auto ans =  Polynomial<Coef, Pow>();
    auto cmp = [ptr](const std::pair<Term<Coef, Pow>, size_t>& a, const std::pair<Term<Coef, Pow>, size_t>& b) {
        Proxy<Coef, Pow> p(ptr);
        return !p(a.first, b.first);
    };
    Proxy<Coef, Pow> p(ptr);
    std::priority_queue<std::pair<Term<Coef, Pow>, size_t>, std::vector<std::pair<Term<Coef, Pow>, size_t>>, decltype(cmp)> heap(cmp);
    std::vector<size_t> a(list.size(), 1);
    for (size_t i = 0; i < list.size(); ++i) {
        heap.push(std::make_pair(list[i][0], i));
    }
    size_t idx;
    while (!heap.empty()) {
        auto term = heap.top().first;
        if (!ans.empty()) {
            if (ans.back().mon() == term.mon()) {
                ans.back().coef() += term.coef();
            } else {
                ans.push_back(term);
            }
        } else {
            ans.push_back(term);
        }
        idx = heap.top().second;
        heap.pop();
        if (a[idx] < list[idx].size()) {
            heap.push(std::make_pair(list[idx][a[idx]], idx));
            ++a[idx];
        }
    }
    return ans;
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>
add_and_substract_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>> &&list_p,
                         std::vector<Polynomial<Coef, Pow>> &&list_n) {
    auto ans =  Polynomial<Coef, Pow>();
    auto cmp = [ptr](const std::pair<Term<Coef, Pow>, size_t>& a, const std::pair<Term<Coef, Pow>, size_t>& b) {
        Proxy<Coef, Pow> p(ptr);
        return !p(a.first, b.first);
    };
    std::priority_queue<std::pair<Term<Coef, Pow>, size_t>, std::vector<std::pair<Term<Coef, Pow>, std::pair<char, size_t>>>, decltype(cmp)> heap(cmp);
    std::vector<size_t> p(list_p.size(), 1), n(list_n.size(), 1);
    for (size_t i = 0; i < list_p.size(); ++i) {
        heap.push(std::make_pair(list_p[i][0], std::make_pair('p', i)));
    }
    size_t idx;
    char l;
    while (!heap.empty()) {
        auto term = heap.top().first;
        if (heap.top().second.first == 'n') {
            term = -term;
        }
        if (!ans.empty()) {
            if (ans.back().mon() == term.mon()) {
                ans.back().coef() += term.coef();
            } else {
                ans.push_back(term);
            }
        } else {
            ans.push_back(term);
        }
        idx = heap.top().second.second;
        l = heap.top().second.first;
        heap.pop();
        if (l == 'p') {
            if (p[idx] < list_p[idx].size()) {
                heap.push(std::make_pair(list_p[idx][p[idx]], idx));
                ++p[idx];
            }
        } else {
            if (n[idx] < list_n[idx].size()) {
                heap.push(std::make_pair(list_n[idx][n[idx]], idx));
                ++n[idx];
            }
        }
    }
    return ans;
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>
add_and_substract_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>> &&list_p,
                         const std::vector<Polynomial<Coef, Pow>> &list_n) {
    auto ans =  Polynomial<Coef, Pow>();
    auto cmp = [ptr](const std::pair<Term<Coef, Pow>, size_t>& a, const std::pair<Term<Coef, Pow>, size_t>& b) {
        Proxy<Coef, Pow> p(ptr);
        return !p(a.first, b.first);
    };
    std::priority_queue<std::pair<Term<Coef, Pow>, size_t>, std::vector<std::pair<Term<Coef, Pow>, std::pair<char, size_t>>>, decltype(cmp)> heap(cmp);
    std::vector<size_t> p(list_p.size(), 1), n(list_n.size(), 1);
    for (size_t i = 0; i < list_p.size(); ++i) {
        heap.push(std::make_pair(list_p[i][0], std::make_pair('p', i)));
    }
    size_t idx;
    char l;
    while (!heap.empty()) {
        auto term = heap.top().first;
        if (heap.top().second.first == 'n') {
            term = -term;
        }
        if (!ans.empty()) {
            if (ans.back().mon() == term.mon()) {
                ans.back().coef() += term.coef();
            } else {
                ans.push_back(term);
            }
        } else {
            ans.push_back(term);
        }
        idx = heap.top().second.second;
        l = heap.top().second.first;
        heap.pop();
        if (l == 'p') {
            if (p[idx] < list_p[idx].size()) {
                heap.push(std::make_pair(list_p[idx][p[idx]], idx));
                ++p[idx];
            }
        } else {
            if (n[idx] < list_n[idx].size()) {
                heap.push(std::make_pair(list_n[idx][n[idx]], idx));
                ++n[idx];
            }
        }
    }
    return ans;
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>
add_and_substract_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>> &list_p,
                         std::vector<Polynomial<Coef, Pow>> &&list_n) {
    auto ans =  Polynomial<Coef, Pow>();
    auto cmp = [ptr](const std::pair<Term<Coef, Pow>, size_t>& a, const std::pair<Term<Coef, Pow>, size_t>& b) {
        Proxy<Coef, Pow> p(ptr);
        return !p(a.first, b.first);
    };
    std::priority_queue<std::pair<Term<Coef, Pow>, size_t>, std::vector<std::pair<Term<Coef, Pow>, std::pair<char, size_t>>>, decltype(cmp)> heap(cmp);
    std::vector<size_t> p(list_p.size(), 1), n(list_n.size(), 1);
    for (size_t i = 0; i < list_p.size(); ++i) {
        heap.push(std::make_pair(list_p[i][0], std::make_pair('p', i)));
    }
    size_t idx;
    char l;
    while (!heap.empty()) {
        auto term = heap.top().first;
        if (heap.top().second.first == 'n') {
            term = -term;
        }
        if (!ans.empty()) {
            if (ans.back().mon() == term.mon()) {
                ans.back().coef() += term.coef();
            } else {
                ans.push_back(term);
            }
        } else {
            ans.push_back(term);
        }
        idx = heap.top().second.second;
        l = heap.top().second.first;
        heap.pop();
        if (l == 'p') {
            if (p[idx] < list_p[idx].size()) {
                heap.push(std::make_pair(list_p[idx][p[idx]], idx));
                ++p[idx];
            }
        } else {
            if (n[idx] < list_n[idx].size()) {
                heap.push(std::make_pair(list_n[idx][n[idx]], idx));
                ++n[idx];
            }
        }
    }
    return ans;
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>
add_and_substract_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>> &list_p,
                         const std::vector<Polynomial<Coef, Pow>> &list_n) {
    auto ans =  Polynomial<Coef, Pow>();
    auto cmp = [ptr](const std::pair<Term<Coef, Pow>, size_t>& a, const std::pair<Term<Coef, Pow>, size_t>& b) {
        Proxy<Coef, Pow> p(ptr);
        return !p(a.first, b.first);
    };
    std::priority_queue<std::pair<Term<Coef, Pow>, size_t>, std::vector<std::pair<Term<Coef, Pow>, std::pair<char, size_t>>>, decltype(cmp)> heap(cmp);
    std::vector<size_t> p(list_p.size(), 1), n(list_n.size(), 1);
    for (size_t i = 0; i < list_p.size(); ++i) {
        heap.push(std::make_pair(list_p[i][0], std::make_pair('p', i)));
    }
    size_t idx;
    char l;
    while (!heap.empty()) {
        auto term = heap.top().first;
        if (heap.top().second.first == 'n') {
            term = -term;
        }
        if (!ans.empty()) {
            if (ans.back().mon() == term.mon()) {
                ans.back().coef() += term.coef();
            } else {
                ans.push_back(term);
            }
        } else {
            ans.push_back(term);
        }
        idx = heap.top().second.second;
        l = heap.top().second.first;
        heap.pop();
        if (l == 'p') {
            if (p[idx] < list_p[idx].size()) {
                heap.push(std::make_pair(list_p[idx][p[idx]], std::make_pair(l, idx)));
                ++p[idx];
            }
        } else {
            if (n[idx] < list_n[idx].size()) {
                heap.push(std::make_pair(list_n[idx][n[idx]], std::make_pair(l, idx)));
                ++n[idx];
            }
        }
    }
    return ans;
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow> add(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>> &&list) {
    for (Polynomial<Coef, Pow>& element : list) {
        element.sort_by(ptr);
    }
    return add_sorted(ptr, list);
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow> add(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>> &list) {
    std::vector<Polynomial<Coef, Pow>> sorted = list;
    for (Polynomial<Coef, Pow>& element : sorted) {
        element.sort_by(ptr);
    }
    return add_sorted(ptr, sorted);
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>
add_and_substract(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>> &&list_p,
                  std::vector<Polynomial<Coef, Pow>> &&list_n) {
    for (Polynomial<Coef, Pow>& element : list_p) {
        element.sort_by(ptr);
    }
    for (Polynomial<Coef, Pow>& element : list_n) {
        element.sort_by(ptr);
    }
    return add_and_substract_sorted(ptr, list_p, list_n);
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>
add_and_substract(std::shared_ptr<Comparator<Coef, Pow>> ptr, std::vector<Polynomial<Coef, Pow>> &&list_p,
                  const std::vector<Polynomial<Coef, Pow>> &list_n) {
    for (Polynomial<Coef, Pow>& element : list_p) {
        element.sort_by(ptr);
    }
    std::vector<Polynomial<Coef, Pow>> sorted = list_n;
    for (Polynomial<Coef, Pow>& element : sorted) {
        element.sort_by(ptr);
    }
    return add_and_substract_sorted(ptr, list_p, sorted);
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>
add_and_substract(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>> &list_p,
                  std::vector<Polynomial<Coef, Pow>> &&list_n) {
    for (Polynomial<Coef, Pow>& element : list_n) {
        element.sort_by(ptr);
    }
    std::vector<Polynomial<Coef, Pow>> sorted = list_p;
    for (Polynomial<Coef, Pow>& element : sorted) {
        element.sort_by(ptr);
    }
    return add_and_substract_sorted(ptr, sorted, list_n);
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>
add_and_substract(std::shared_ptr<Comparator<Coef, Pow>> ptr, const std::vector<Polynomial<Coef, Pow>> &list_p,
                  const std::vector<Polynomial<Coef, Pow>> &list_n) {
    std::vector<Polynomial<Coef, Pow>> sorted_p = list_p;
    for (Polynomial<Coef, Pow>& element : sorted_p) {
        element.sort_by(ptr);
    }
    std::vector<Polynomial<Coef, Pow>> sorted_n = list_n;
    for (Polynomial<Coef, Pow>& element : sorted_n) {
        element.sort_by(ptr);
    }
    return add_and_substract_sorted(ptr, sorted_p, sorted_n);
}

template<typename Coef, typename Pow>
Polynomial<Coef, Pow>
mul_sorted(std::shared_ptr<Comparator<Coef, Pow>> ptr, const Polynomial<Coef, Pow> &a, const Polynomial<Coef, Pow> &b) {
    std::vector<Polynomial<Coef, Pow>> list;
    if (a.size() < b.size()) {
        list.emplace_back(Polynomial<Coef, Pow>());
        for (const Term<Coef, Pow>& mul : a) {
            for (const Term<Coef, Pow>& elem : b) {
                list.back().push_back(elem * mul);
            }
        }
    } else {
        list.emplace_back(Polynomial<Coef, Pow>());
        for (const Term<Coef, Pow>& mul : b) {
            for (const Term<Coef, Pow>& elem : a) {
                list.back().push_back(elem * mul);
            }
        }
    }
    return add_sorted(ptr, list);
}


#endif //GROBNERBASIS_POLYNOMIAL_H
