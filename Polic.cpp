//
// Created by yaroslav on 5/12/18.
//

#include "Element.h"

Polynomial Element::bar(const Comparator& cmp, const std::vector<Polynomial> &F) const {
    if (size() != F.size()) {
        throw std::exception();
    }
    auto ans = std::vector<Polynomial>();
    for (size_t i = 0; i < size(); ++i) {
        ans.push_back(Polynomial::mul(cmp, F[i], at(i)));
    }
    return Polynomial::add_many(cmp, ans);
}
