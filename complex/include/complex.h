#pragma once
#include <iostream>
#include <cmath>
#include <cassert>

namespace complex {

const double EPS = 0.00001;

struct complex_num {

    double Re;
    double Im;

    complex_num();
    complex_num(const double a, const double b);
    complex_num(const complex_num &another_comp_num);

    complex_num operator + (const complex_num &num1) const;
    complex_num operator + () const;
    complex_num operator - (const complex_num &num1) const;
    complex_num operator - () const;
    complex_num operator * (const complex_num &num1) const;
    complex_num operator * (const double num) const;
    complex_num operator / (const complex_num &num1) const;
    complex_num operator / (const double num) const;
    bool operator > (const complex_num &num1) const;
    bool operator < (const complex_num &num1) const;

    bool is_zero() const;
    void print_num() const;
    
};

}; // namespace complex