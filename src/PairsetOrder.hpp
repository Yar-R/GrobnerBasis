//
// Created by yaroslav on 7/24/18.
//

#ifndef GROBNERBASIS_PAIRSETORDER_HPP
#define GROBNERBASIS_PAIRSETORDER_HPP

template<typename Pow>
class PairsetOrder {
public:
    virtual bool operator()(const ModuleElement& a, const ModuleElement& b) const = 0;
};

template<typename Pow>
class DecSig : public PairsetOrder<Pow> {
    bool operator()(const ModuleElement& a, const ModuleElement& b) const final;
};

template<typename Pow>
bool DecSig<Pow>::operator()(const ModuleElement& a, const ModuleElement& b) const {
    return signature(a) < signature(b);
}

#endif //GROBNERBASIS_PAIRSETORDER_HPP
