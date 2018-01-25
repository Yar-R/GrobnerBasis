//
// Created by yaroslav on 03.01.18.
//

#ifndef GROBNERBASIS_MONOMIAL_H
#define GROBNERBASIS_MONOMIAL_H


#include <vector>
#include <cstdint>
#include <ostream>

typedef uint16_t base_type;

class Monomial {
    std::vector<base_type> powers;
public:
    Monomial();
    Monomial(Monomial&& _mon) noexcept;
    Monomial(const Monomial& _mon);
    explicit Monomial(std::vector<base_type>&& _data) noexcept;
    Monomial(std::initializer_list<base_type>&& list);
    explicit Monomial(const std::vector<base_type>& _data);
    Monomial& operator=(const Monomial& _mon);
    Monomial& operator=(Monomial&& _mon) noexcept ;
    Monomial& operator*=(const Monomial& other);
    friend bool operator==(const Monomial& a, const Monomial& b);
    friend Monomial operator*(const Monomial& a, const Monomial& b);
    friend std::ostream & operator<<(std::ostream & os, const Monomial& a);
    size_t size() const;
    size_t size();
    const base_type& operator[](size_t idx) const;
    base_type& operator[](size_t idx);
};

#endif //GROBNERBASIS_MONOMIAL_H
