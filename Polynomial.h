//
// Created by yaroslav on 09.01.18.
//

#ifndef GROBNERBASIS_POLYNOMIAL_H
#define GROBNERBASIS_POLYNOMIAL_H

#include "Comparator.hpp"
#include "Term.hpp"

class Polynomial {
    std::vector<Term> terms;
public:
    Term greatest_term();
    Monomial greatest_monomial();
    double greatest_coeficient();
};


#endif //GROBNERBASIS_POLYNOMIAL_H
