//
// Created by Yaroslav Rebenko on 21.07.2018.
//

#ifndef GROBNERBASIS_MODULETERM_H
#define GROBNERBASIS_MODULETERM_H

#include "Polynomial.hpp"

typedef Term<Polynomial, size_t > ModuleTerm;

ModuleTerm operator*(const ModuleTerm& mt, const Term<double, Monomial<int64_t>>& t) {
    return ModuleTerm(mt.coef * t, mt.monom);
}

#endif //GROBNERBASIS_MODULETERM_H
