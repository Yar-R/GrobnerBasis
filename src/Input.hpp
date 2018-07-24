//
// Created by yaroslav on 7/24/18.
//

#ifndef GROBNERBASIS_INPUT_HPP
#define GROBNERBASIS_INPUT_HPP

#include "Polynomial.hpp"

template <typename Coef, typename Pow>
using Input = std::vector<Polynomial<Coef, Pow>>;

template <typename Coef, typename Pow>
size_t size(const Input<Coef, Pow>& input) {
    return input.size();
}
#endif //GROBNERBASIS_INPUT_HPP
