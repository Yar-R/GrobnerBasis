//
// Created by yaroslav on 7/24/18.
//

#ifndef GROBNERBASIS_PAIRSET_HPP
#define GROBNERBASIS_PAIRSET_HPP

#include "ModuleElement.hpp"
#include "PairsetOrder.hpp"

using Pairset = std::priority_queue<std::pair<ModuleElement, ModuleElement>, std::vector<std::pair<ModuleElement, ModuleElement>>, PairsetOrder>;

template <typename Less>
auto insert(Pairset& P, const std::pair<ModuleElement, ModuleElement>& e) {
    return P.push(e);
}

auto first(const Pairset& P) {
    return P.top();
}

void del_first(Pairset& P) {
    P.pop();
}

#endif //GROBNERBASIS_PAIRSET_HPP
