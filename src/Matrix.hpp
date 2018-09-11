//
// Created by yaroslav on 8/24/18.
//

#ifndef GROBNERBASIS_GAUSS_HPP
#define GROBNERBASIS_GAUSS_HPP

#include "MF5Signature.hpp"
#include "Polynomial.hpp"
#include "MonomialOrder.hpp"

template <typename Coef, typename Pow>
using Matrix = std::vector<std::pair<Signature<Coef, Pow>, Polynomial<Coef, Pow>>>;

template<typename Coef, typename Pow>
Matrix<Coef, Pow> gauss(
        Matrix<Coef, Pow> matrix,
        MonomialOrder<Pow>) {
    for (size_t i = 0; i < matrix.size(); ++i) {

    }
};
#endif //GROBNERBASIS_GAUSS_HPP
