//
// Created by yaroslav on 09.01.18.
//

#ifndef GROBNERBASIS_POLYNOMIAL_H
#define GROBNERBASIS_POLYNOMIAL_H

#include "Comparator.h"
#include "Term.h"

class Polynomial {
    std::vector<Term> terms;
public:
    Term greatest_term();
    Monomial greatest_monomial();
    double greatest_coeficient();
};


#endif //GROBNERBASIS_POLYNOMIAL_H
