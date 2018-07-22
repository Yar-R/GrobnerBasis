//
// Created by Yaroslav Rebenko on 22.07.2018.
//

#include "../src/Polynomial.hpp"
#include "../src/ModuleElement.hpp"
//#include "catch.hpp"

bool bar_test() {
    return 1;
    std::vector<Polynomial> i = {
            {{1, {}}},
            {{2, {1, 1}}},
            {{-1, {}}, {-4, {1, 1}}},
            {{-1, {1, 1}}}
    };
    ModuleElement e = {
            {{1, {}}, 0},
            {{1, {}}, 1},
            {{1, {}}, 2},
            {{-2, {}}, 3}
    };
    auto cmp = Lex<int64_t>();
    return bar(std::ref(cmp), i, e).empty();
}

