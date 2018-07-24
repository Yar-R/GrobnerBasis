//
// Created by Yaroslav Rebenko on 21.07.2018.
//

#ifndef GROBNERBASIS_MODULEELEMENT_H
#define GROBNERBASIS_MODULEELEMENT_H

#include "MonomialOrder.hpp"
#include "ModuleMonomialOrder.hpp"
#include "Input.hpp"
#include "Polynomial.hpp"
#include "ModuleBasis.hpp"
#include <experimental/optional>
#include "ModuleMonomial.hpp"


template <typename Pow>
using ModuleElement = std::vector<ModuleMonomial<Pow>>;

template <typename Pow>
ModuleElement<Pow> operator*(const ModuleElement<Pow>& me, const Term<double, Monomial<Pow>>& t) {
    ModuleElement<Pow> ans;
    for (auto& mt : me) {
        ans.push_back(mt * t);
    }
    return ans;
}


template <typename Coef, typename Pow>
ModuleElement<Pow> operator*(const Polynomial<Coef, Pow>& p, const ModuleBasis& e) {
    ModuleElement<Pow> ans;
    for (const auto& term : p) {
        ans.push_back({term, e});
    }
    return ans;
}

template<typename Pow>
ModuleElement<Pow> substract(const ModuleMonomialOrder<Pow>& cmp, const ModuleElement<Pow>& a, const ModuleElement<Pow>& b) {
    size_t i = 0;
    size_t j = 0;
    ModuleElement<Pow> ans;
    while (i < a.size() && j < b.size()) {
        if (cmp(a[i].monomx, b[j].monom)) {
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
Polynomial<Coef, Pow> bar(const MonomialOrder<Pow>& cmp, const Input<Coef, Pow>& input, ModuleElement<Pow> module_element) {
    Polynomial<Coef, Pow> ans;
    for (const auto& term : module_element) {
        add(cmp, ans, input[term.monom] * term.coef);
    }
    return ans;
}


template <typename Coef, typename Pow>
std::experimental::optional<ModuleElement<Pow>> sreduce(const MonomialOrder<Pow>& cmp,
                                                   const ModuleMonomialOrder<Pow>& Cmp,
                                                   const std::vector<Polynomial<Coef, Pow>>& input,
                                                   const ModuleElement<Pow>& a,
                                                   size_t idx,
                                                   const ModuleElement<Pow>& reducer) {
    auto t = bar(cmp, input, a)[idx];
    auto lt = bar(cmp, input, reducer)[0];
    auto b = t / lt;
    if (!b) {
        return {};
    }
    return substract(Cmp, a, reducer * get_value(b));
}

#endif //GROBNERBASIS_MODULEELEMENT_H
