//
// Created by yaroslav on 5/13/18.
//

#ifndef GROBNERBASIS_MONIC_H
#define GROBNERBASIS_MONIC_H


#include "Polynomial.h"

class Monic {
private:
    Term _poly;
    size_t _idx;
public:
    Term & coef();

    const Term & coef() const;

    size_t &axis();

    const size_t &axis() const;
};


#endif //GROBNERBASIS_MONIC_H
