//
// Created by yaroslav on 7/24/18.
//

#ifndef GROBNERBASIS_MODULEMONOMIALORDER_HPP
#define GROBNERBASIS_MODULEMONOMIALORDER_HPP

#include "ModuleMonomial.hpp"
#include "MonomialOrder.hpp"

template<typename Pow>
class ModuleMonomialOrder {
    MonomialOrder<Pow> _cmp;
public:
    ModuleMonomialOrder(const MonomialOrder<Pow>& __cmp) : _cmp(_cmp) {};
    virtual bool operator()(const ModuleMonomial<Pow>& a, const ModuleMonomial<Pow>& b) const = 0;
    bool cmp(const Monomial<Pow>& a, const Monomial<Pow>& b) const {
        return this->_cmp(a, b);
    }
};

template<typename Pow>
class Pot : public ModuleMonomialOrder<Pow> {
    using ModuleMonomialOrder<Pow>::ModuleMonomialOrder;
    bool operator()(const ModuleMonomial<Pow>& a, const ModuleMonomial<Pow>& b) const final;
};

template<typename Pow>
bool Pot<Pow>::operator()(const ModuleMonomial<Pow>& a, const ModuleMonomial<Pow>& b) const {
    return a.monom < b.monom || (a.monom == b.monom && this->cmp(a.coef.monom, b.coef.monom));
}

#endif //GROBNERBASIS_MODULEMONOMIALORDER_HPP
