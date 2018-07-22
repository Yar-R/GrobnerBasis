//
// Created by Yaroslav Rebenko on 20.07.2018.
//

#ifndef GROBNERBASIS_MONOMIAL_H
#define GROBNERBASIS_MONOMIAL_H

#include <vector>
#include <experimental/optional>

template<typename T>
T& get_value(std::experimental::optional<T> &opt)
{
    if(!opt.has_value())
        throw std::logic_error("bad optional access");
    return *opt;
}

template<typename T>
T const& get_value(std::experimental::optional<T>const &opt)
{
    if(!opt.has_value())
        throw std::logic_error("bad optional access");
    return *opt;
}

template<typename Pow>
using Monomial = std::vector<Pow>;

template<typename Pow>
Monomial<Pow>& operator*=(Monomial<Pow>& first, const Monomial<Pow>& second) {
    size_t i = 0;
    for (; i < first.size() && i < second.size(); ++i)
        first[i] += second[i];
    for (; i < second.size(); ++i)
        first.push_back(second[i]);
    return first;
}

template<typename Pow>
Monomial<Pow> operator*(const Monomial<Pow>& a, const Monomial<Pow>& b) {
    auto c = a;
    c *= b;
    return c;
}

template<typename Pow>
std::experimental::optional<Monomial<Pow>> operator/(const Monomial<Pow>& first, const Monomial<Pow>& second) {
    size_t i = 0;
    for (; i < first.size() && i < second.size() && first[i] >= second[i]; ++i)
        first[i] -= second[i];
    if (i < first.size() && i < second.size() && first[i] < second[i]) {
        return {};
    }
    for (; i < second.size(); ++i)
        first.push_back(second[i]);
    return first;
}

#endif //GROBNERBASIS_MONOMIAL_H
