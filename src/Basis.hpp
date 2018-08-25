//
// Created by yaroslav on 7/25/18.
//

#ifndef GROBNERBASIS_BASIS_HPP
#define GROBNERBASIS_BASIS_HPP

#include <vector>
#include "Polynomial.hpp"

template<typename Coef, typename Pow>
using Basis = std::vector<Polynomial<Coef, Pow>>;

template<typename Coef, typename Pow>
void insert(Basis<Coef, Pow>& basis, const Polynomial<Coef, Pow>& polynomial) {
    basis.push_back(polynomial);
};

#endif //GROBNERBASIS_BASIS_HPP
