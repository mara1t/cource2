#pragma once
#include <iostream>
#include <cmath>

namespace complex {

struct complex_num {

    double a_;
    double b_;

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

bool complex_num::is_zero() const
{
    return ((abs(a_) < 1e-8) && (abs(a_) < 1e-8));
}

void complex_num::print_num() const 
{
    std::cout << a_;
    if (abs(b_) > 1e-8) {
        std::cout << " + i*" << b_ << std::endl;
    }
}

complex_num::complex_num() : a_{0}, b_{0} {}

complex_num::complex_num(const double a, const double b) : a_{a}, b_{b} {}

complex_num::complex_num(const complex_num &another_comp_num) : a_{another_comp_num.a_}, b_{another_comp_num.b_} {}

complex_num complex_num::operator + (const complex_num &num1) const
{   
    return complex_num{a_ + num1.a_, b_ + num1.b_};
}

complex_num complex_num::operator + () const
{   
    return *this;
}

complex_num complex_num::operator - (const complex_num &num1) const
{   
    return complex_num{a_ - num1.a_, b_ - num1.b_};
}

complex_num complex_num::operator - () const
{   
    return complex_num{- a_, - b_};
}

complex_num complex_num::operator * (const complex_num &num1) const
{   
    return complex_num{a_ * num1.a_ - b_ * num1.b_, a_ * num1.b_ + b_ * num1.a_};
}

complex_num complex_num::operator * (const double num2) const
{   
    return complex_num{a_ * num2, b_ * num2};
}

complex_num complex_num::operator / (const complex_num &num1) const
{   
    if (num1.is_zero()) {
        return complex_num{NAN, NAN};
    }
    return complex_num{(a_ * num1.a_ + b_ * num1.b_) / (num1.a_ * num1.a_ + num1.b_ * num1.b_), (b_ * num1.a_ - a_ * num1.b_) / (num1.a_ * num1.a_ + num1.b_ * num1.b_)};
}

complex_num complex_num::operator / (const double num1) const
{   
    if (abs(num1) < 1e-8) {
        return complex_num{NAN, NAN};
    }

    return complex_num{a_ / num1, b_ / num1};
}

bool complex_num::operator > (const complex_num &num1) const 
{
    if (abs(num1.b_) > 1e-8 || abs(b_) > 1e-8) {
        return 0;
    }

    return a_ > num1.a_;
}

bool complex_num::operator < (const complex_num &num1) const 
{
    if (abs(num1.b_) > 1e-8 || abs(b_) > 1e-8) {
        return 0;
    }

    return a_ < num1.a_;
}

};