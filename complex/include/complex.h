#pragma once
#include <iostream>
#include <math.h>


namespace complex {

class complex_num {
    double a_;
    double b_;
public:
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

};