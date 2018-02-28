#include <iostream>
#include <vector>
#include <algorithm>
#include "Monomial.hpp"
#include "Comparator.hpp"
#include "Term.hpp"



int main() {
    std::vector<Monomial<uint16_t>> monomials = {{1, 0, 2}, {0, 1, 0}, {0, 0, 1}, {1, 0, 1}, {1, 1, 0}, {0, 1, 1}};
    std::vector<Term<uint16_t>> terms = {{monomials[0], 1}, {monomials[1], 2}, {monomials[2], 3}, {monomials[3], 4}, {monomials[4], 5}, {monomials[5], 6}};
    std::vector<Comparator<uint16_t>*> comparators = {new LexComparator<uint16_t>(), new GrlexComparator<uint16_t>(), new GrevlexComparator<uint16_t>()};
    for (const auto & t : terms) {
        std::cout << t << std::endl;
    }
    /*
    for (const auto & cmp : comparators) {
        std::cout << "-------------------------" << std::endl;
        std::sort(terms.begin(), terms.end(), cmp->get_cmp_func());
        for (const auto & t : terms) {
            std::cout << t << std::endl;
        }
    }

    for (const auto & cmp : comparators) {
        delete cmp;
    }
     */
    return 0;
}
