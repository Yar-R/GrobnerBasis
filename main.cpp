#include <iostream>
#include <vector>
#include <algorithm>
#include "Monomial.hpp"
#include "Comparator.hpp"
#include "Term.hpp"
#include "Polynomial.hpp"


int main() {
    Monomial<uint16_t> a(1);
    /*
    std::vector<Monomial<uint16_t>> monomials({{1, 0, 2},
                                               {0, 1, 0},
                                               {0, 0, 1},
                                               {1, 0, 1},
                                               {1, 1, 0},
                                               {0, 1, 1}});
    Polynomial<double, uint16_t> poly({{monomials[0], 1},
                                        {monomials[1], 2},
                                        {monomials[2], 3},
                                        {monomials[3], 4},
                                        {monomials[4], 5},
                                        {monomials[5], 6}});
    std::vector<std::shared_ptr<Comparator<double, uint16_t>>> comparators;
    comparators.push_back((std::shared_ptr<Comparator<double, uint16_t>>)new LexComparator<double, uint16_t>());
    comparators.push_back((std::shared_ptr<Comparator<double, uint16_t>>)new GrlexComparator<double, uint16_t>());
    comparators.push_back((std::shared_ptr<Comparator<double, uint16_t>>)new GrevlexComparator<double, uint16_t>());

    std::cout << poly << std::endl;
    /*/
    /*/
    for (const auto &cmp : comparators) {
        std::cout << "-------------------------" << std::endl;
        poly.sort_by(cmp);
        std::cout << poly << std::endl;
    }
    Polynomial<double, uint16_t> p2();
    //*/
    return 0;
}
