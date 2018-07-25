#include "MonomialOrder.hpp"
#include "PairsetOrder.hpp"
#include "RewriteOrder.hpp"
#include "Pairset.hpp"
#include "Input.hpp"
#include "Basis.hpp"


template <typename Coef, typename Pow>
std::pair<RewriteBasis, Basis> RB(const Input<Coef, Pow>& input,
                                  const MonomialOrder<Pow>& monomial_order,
                                  const ModuleMonomialOrder<Pow>& module_monomial_order,
                                  const PairsetOrder<Pow>& pairset_order,
                                  const RewriteOrder<Pow>& rewrite_order) {
    RewriteBasis G;
    Basis<Coef, Pow> H;
    Pairset P(pairset_order);
    for (size_t i = 0; i < size(input); ++i) {
        insert(P, ModuleBasis(i));
    }
    for (size_t i = 0; i < size(input); ++i) {
        for (size_t j = i + 1; j < size(input); ++i) {
            insert(H, substract(input[i] * ModuleBasis(j), input[j] * ModuleBasis(i)));
        }
    }
    while (!empty(P)) {
        auto B = first(P);
        del_first(P);
        if (!rewritable(B, G, H, rewrite_order)) {
            auto y = sreduce(monomial_order, module_monomial_order, input, // TODO);
            if (y) {
                if (bar(monomial_order, input, get_value(y)).empty()) {
                    insert(H, get_value(y));
                } else {
                    for (const auto& e : G) {
                        auto pair = spair(input, monomial_order, e, get_value(y));
                        if (regular(pair)) {
                            insert(P, pair);
                        }
                    }
                    insert(G, get_value(y));
                }
            }
        }
    }
};

