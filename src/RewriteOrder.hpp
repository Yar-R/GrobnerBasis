//
// Created by yaroslav on 7/24/18.
//

#ifndef GROBNERBASIS_REWRITEORDER_HPP
#define GROBNERBASIS_REWRITEORDER_HPP

template<typename Pow>
class RewriteOrder {
public:
    virtual bool operator()(const ModuleElement& a, const ModuleElement& b) const = 0;
};

template<typename Pow>
class Lex : public RewriteOrder<Pow> {
    bool operator()(const ModuleElement& a, const ModuleElement& b) const final;
};

#endif //GROBNERBASIS_REWRITEORDER_HPP
