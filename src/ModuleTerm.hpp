//
// Created by Yaroslav Rebenko on 21.07.2018.
//

#ifndef GROBNERBASIS_MODULETERM_H
#define GROBNERBASIS_MODULETERM_H

#include "Term.hpp"

typedef Term<Term<double, Monomial<int64_t>>, size_t > ModuleTerm;

#endif //GROBNERBASIS_MODULETERM_H
