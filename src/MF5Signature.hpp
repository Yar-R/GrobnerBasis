//
// Created by yaroslav on 8/24/18.
//

#ifndef GROBNERBASIS_MF5SIGNATURE_HPP
#define GROBNERBASIS_MF5SIGNATURE_HPP

#include "Term.hpp"

template <typename Coef, typename Pow>
using Signature = std::pair<size_t, Term<Coef, Pow>>;

#endif //GROBNERBASIS_MF5SIGNATURE_HPP
