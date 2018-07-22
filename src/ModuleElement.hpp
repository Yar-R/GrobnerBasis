//
// Created by Yaroslav Rebenko on 21.07.2018.
//

#ifndef GROBNERBASIS_MODULEELEMENT_H
#define GROBNERBASIS_MODULEELEMENT_H

#include "ModuleTerm.hpp"

typedef std::vector<ModuleTerm> ModuleElement;

Polynomial bar(const Comparator<int64_t>& cmp, const std::vector<Polynomial>& input, ModuleElement module_element) {
    Polynomial ans;
    for (const auto& term : module_element) {
        add(cmp, ans, input[term.monom] * term.coef);
    }
    return ans;
}

#endif //GROBNERBASIS_MODULEELEMENT_H
