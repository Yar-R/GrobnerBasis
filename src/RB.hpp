#include "MonomialOrder.hpp"
#include "PairsetOrder.hpp"
#include "RewriteOrder.hpp"
#include "Pairset.hpp"
#include "Input.hpp"


std::pair<RewriteBasis, Basis> RB(const Input& input,
                                  const MonomialOrder& monomial_order,
                                  const ModuleMonomialOrder& module_monomial_order,
                                  const PairsetOrder& pairset_order,
                                  const RewriteOrder& rewrite_order) {
    RewriteBasis G;
    Basis H;
    Pairset P(pairset_order);
    for (size_t i = 0; i < size(input); ++i) {
        insert(P, ModuleBasis(i));
    }
    for (size_t i = 0; i < size(input); ++i) {
        for (size_t j = i + 1; j < size(input); ++i) {
            insert(H, substract(module_monomial_order, input[i] * ModuleBasis(j), input[j] * ModuleBasis(i)));
        }
    }
    while (!empty(P)) {
        auto B = first(P);
        del_first(P);
        if (!rewritable(B, G, H, rewrite_order)) {
            auto y = sreduce(B);
            if (bar(y) == 0) {
                insert(H, y);
            } else {
                for (const auto& e : G) {
                    if (regular(spair(e, y))) {
                        insert(P, spair(e, y));
                    }
                }
                insert(G, y);
            }
        }
    }
};