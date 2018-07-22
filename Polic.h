//
// Created by yaroslav on 5/12/18.
//

#ifndef GROBNERBASIS_ELEMENT_H
#define GROBNERBASIS_ELEMENT_H


#include <cstdint>
#include <vector>
#include "Polynomial.h"
#include "Monic.h"

class Element : public std::vector<Monic> {
public:
    using std::vector<Polynomial>::vector;

    Polynomial bar(const Comparator& cmp, const std::vector<Polynomial> &F) const;


};


#endif //GROBNERBASIS_ELEMENT_H
