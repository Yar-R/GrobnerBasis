//
// Created by Yaroslav Rebenko on 22.07.2018.
//

#ifndef GROBNERBASIS_F5_H
#define GROBNERBASIS_F5_H

#include <optional>
#include "Basis.hpp"
#include "Input.hpp"
#include "MF5Signature.hpp"
#include "Matrix.hpp"

template <typename Coef, typename Pow>
bool nin(std::vector<Monomial<Pow>>& Crit, Monomial<Pow> m) {
    return std::find(Crit.begin(), Crit.end(), m) == Crit.end();
};

template <typename Coef, typename Pow>
Basis MatrixF5(const Input<Coef, Pow>& input,
               const MonomialOrder<Pow>& monomial_order,
               const Pow D) {
    std::vector<Pow> deg(input.size());
    for (size_t i = 0; i < input.size(); ++i) {
        deg[i] = pow(input[i]);
    }
    std::vector<std::vector<Matrix<Coef, Pow>>> M(D), _M(D);
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
                std::vector<Monomial<Pow>> Crit;
                for (size_t j = M[d - 1][i - 1].size(); j < M[d - 1][i].size(); ++j) {
                    Signature<Pow> s = M[d - 1][i][j].first;
                    Polynomial<Coef, Pow> r = M[d - 1][i][j].second;
                    size_t k = s.first;
                    Monomial<Pow> m = s.second;
                    for (Monomial<Pow> variable) {
                        if (nin(Crit, variable * m)) {
                            M[d][i].push_back(std::make_pair(std::make_pair(k, variable * m), m * r));
                        }
                    }
                }
            }
            _M[d][i] = gauss(M[d][i], monomial_order);
        }
    }
};

#endif //GROBNERBASIS_F5_H
