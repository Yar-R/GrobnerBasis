//
// Created by Yaroslav Rebenko on 22.07.2018.
//

#ifndef GROBNERBASIS_F5_H
#define GROBNERBASIS_F5_H

#include <optional>
#include "Basis.hpp"
#include "Input.hpp"
#include "ModuleMonomialOrder.hpp"

template <typename Coef, typename Pow>
using Signature = std::pair<size_t, Term<Coef, Pow>>;

template <typename Coef, typename Pow>
using Matrix = std::vector<std::pair<Signature<Coef, Pow>, Polynomial<Coef, Pow>>>;

template <typename Coef, typename Pow>
Basis MatrixF5(const Input<Coef, Pow>& input,
               const MonomialOrder<Pow>& monomial_order,
               const Pow D) {
    std::vector<std::pair<Signature, Polynomial<Coef, Pow>>> d_basis, next_basis;
    std::vector<Pow> deg(input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        deg[i] = pow(input[i]);
    }

    for (Pow d = deg[0]; d < D; ++d) {
        M[d][0] = {};
        _M[d][0] = {};
        for (size_t i = 0; i < input.size(); ++i) {
            if (d < deg[i]) {
                M[d][i + 1] = M[d][i];
            } else if (d == deg[i]) {
                M[d][i + 1] = _M[d][i];
                M[d][i + 1].push_back(std::make_pair(std::make_pair(i, Term(1)), input[i]));
            } else {
                M[d][i + 1] = _M[d][i];

            }
        }
    }
};

#endif //GROBNERBASIS_F5_H
