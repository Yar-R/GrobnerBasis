//
// Created by yaroslav on 5/13/18.
//

#include "Monic.h"

Term & Monic::coef() {
    return _poly;
}

const Term & Monic::coef() const {
    return _poly;
}

size_t &Monic::axis() {
    return _idx;
}

const size_t &Monic::axis() const {
    return _idx;
}
