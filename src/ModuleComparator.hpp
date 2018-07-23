//
// Created by Yaroslav Rebenko on 22.07.2018.
//

#ifndef GROBNERBASIS_MODULECOMPARATOR_H
#define GROBNERBASIS_MODULECOMPARATOR_H

#include "Comparator.hpp"
#include "ModuleTerm.hpp"

template <typename Pow>
class ModuleComparator {
private:
    Comparator cmp;
public:
    explicit ModuleComparator(const Comparator<Pow>& _cmp): cmp(_cmp) {}
    virtual bool operator()(const ModuleTerm& a, const ModuleTerm& b) const = 0;
};

class Top: public ModuleComparator {
    using ModuleComparator;
    bool operator()(const ModuleTerm& a, const ModuleTerm& b) {
        if (a.coef
    }
};


#endif //GROBNERBASIS_MODULECOMPARATOR_H
