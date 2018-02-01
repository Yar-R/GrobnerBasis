#include <iostream>
#include <vector>
#include <algorithm>
#include "Monomial.h"
#include "Comparator.h"



int main() {
    std::vector<Monomial> monomials = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {1, 0, 1}, {1, 1, 0}, {0, 1, 1}};
    std::vector<Comparator*> comparators = {new LexComparator(), new GrlexComparator(), new GrevlexComparator()};
    for (const auto & m : monomials) {
        std::cout << m << std::endl;
    }
    for (const auto & cmp : comparators) {
        std::cout << "-------------------------" << std::endl;
        std::sort(monomials.begin(), monomials.end(), cmp->get_cmp_func());
        for (const auto & m : monomials) {
            std::cout << m << std::endl;
        }
    }

    for (const auto & cmp : comparators) {
        delete cmp;
    }
    return 0;
}
