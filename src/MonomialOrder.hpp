//
// Created by yaroslav on 7/24/18.
//

#ifndef GROBNERBASIS_MONOMIALORDER_HPP
#define GROBNERBASIS_MONOMIALORDER_HPP

template<typename Pow>
class MonomialOrder {
public:
    virtual bool operator()(const Monomial<Pow>& a, const Monomial<Pow>& b) const = 0;
};

template<typename Pow>
class Lex : public MonomialOrder<Pow> {
    bool operator()(const Monomial<Pow>& a, const Monomial<Pow>& b) const final;
};

template<typename Pow>
bool Lex<Pow>::operator()(const Monomial<Pow>& a, const Monomial<Pow>& b) const {
    size_t i = 0;
    for (; i < a.size() && i < b.size(); ++i) {
        if (a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return i < a.size();
}


#endif //GROBNERBASIS_MONOMIALORDER_HPP
