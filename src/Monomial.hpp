//
// Created by Yaroslav Rebenko on 20.07.2018.
//

#ifndef GROBNERBASIS_MONOMIAL_H
#define GROBNERBASIS_MONOMIAL_H
//#define OSX

#include <vector>
#include <experimental/optional>

#ifdef OSX
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

double gcd(double a, double b) {
    return std::min(a, b);
}
#else

template<typename T>
T& get_value(std::experimental::optional<T>& opt) {
    if (!opt)
        throw std::logic_error("bad optional access");
    return opt.value();
}

template<typename T>
T const& get_value(std::experimental::optional<T> const& opt) {
    if (!opt)
        throw std::logic_error("bad optional access");
    return opt.value();
}

double gcd(double a, double b) {
    return std::min(a, b);
}

#endif
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
    Monomial<Pow> ans;
    for (; i < first.size() && i < second.size() && first[i] >= second[i]; ++i)
        ans.push_back(first[i] - second[i]);
    if (i < first.size() && i < second.size() && first[i] < second[i]) {
        return {};
    }
    for (; i < first.size(); ++i)
        ans.push_back(first[i]);
    return ans;
}

template<typename Pow>
Monomial<Pow> gcd(const Monomial<Pow>& a, const Monomial<Pow>& b) {
    Monomial<Pow> ans;
    for (size_t i = 0; i < a.size() && i < b.size(); ++i) {
        ans.push_back(std::min(a[i], b[i]));
    }
    return ans;
}

#endif //GROBNERBASIS_MONOMIAL_H
