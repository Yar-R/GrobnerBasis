//
// Created by Yaroslav Rebenko on 21.07.2018.
//

#ifndef GROBNERBASIS_MODULEELEMENT_H
#define GROBNERBASIS_MODULEELEMENT_H

#include "ModuleTerm.hpp"
#include "Comparator.hpp"
#include <experimental/optional>

typedef std::vector<ModuleTerm> ModuleElement;

ModuleElement operator*(const ModuleElement& me, const Term<double, Monomial<int64_t>>& t) {
    ModuleElement ans;
    for (auto& mt : me) {
        ans.push_back(mt * t);
    }
    return ans;
}



Polynomial bar(const Comparator<int64_t>& cmp, const std::vector<Polynomial>& input, ModuleElement module_element) {
    Polynomial ans;
    for (const auto& term : module_element) {
        add(cmp, ans, input[term.monom] * term.coef);
    }
    return ans;
}

std::experimental::optional<ModuleElement> sreduce(const Comparator<int64_t>& cmp,
                                                   const std::vector<Polynomial>& input,
                                                   const ModuleElement& a,
                                                   size_t idx,
                                                   const ModuleElement& reducer) {
    auto t = bar(cmp, input, a)[idx];
    auto lt = bar(cmp, input, reducer)[0];
    auto b = t / lt;
    if (!b) {
        return {};
    }
    return a - reducer * get_value(b);
}

#endif //GROBNERBASIS_MODULEELEMENT_H
