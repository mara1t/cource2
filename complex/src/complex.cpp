#include "complex.h"

bool complex::complex_num::is_valid() const 
{
    return Re == Re && Im == Im;
}

bool complex::complex_num::is_zero() const
{
    return ((abs(Re) < EPS) && (abs(Im) < EPS));
}

void complex::complex_num::print_num() const 
{
    std::cout << Re;
    if (fabs(Im) >= EPS) {
        std::cout << " + i*" << Im;
    }
    std::cout << std::endl;
}

complex::complex_num::complex_num() : Re{0}, Im{0} {}

complex::complex_num::complex_num(const double a, const double b) : Re{a}, Im{b} {}

complex::complex_num::complex_num(const complex_num &another_comp_num) : Re{another_comp_num.Re}, Im{another_comp_num.Im} {}

complex::complex_num complex::complex_num::operator + (const complex_num &num1) const
{   
    return complex_num{Re + num1.Re, Im + num1.Im};
}

complex::complex_num complex::complex_num::operator + () const
{   
    return *this;
}

complex::complex_num complex::complex_num::operator - (const complex_num &num1) const
{   
    return complex_num{Re - num1.Re, Im - num1.Im};
}

complex::complex_num complex::complex_num::operator - () const
{   
    return complex_num{- Re, - Im};
}

complex::complex_num complex::complex_num::operator * (const complex_num &num1) const
{   
    return complex_num{Re * num1.Re - Im * num1.Im, Re * num1.Im + Im * num1.Re};
}

complex::complex_num complex::complex_num::operator * (const double num2) const
{   
    return complex_num{Re * num2, Im * num2};
}

complex::complex_num complex::complex_num::operator / (const complex_num &num1) const
{   
    if (num1.is_zero()) {
        return complex_num{NAN, NAN};
    }
    return complex_num{(Re * num1.Re + Im * num1.Im) / (num1.Re * num1.Re + num1.Im * num1.Im), 
        (Im * num1.Re - Re * num1.Im) / (num1.Re * num1.Re + num1.Im * num1.Im)};
}

complex::complex_num complex::complex_num::operator / (const double num1) const
{   
    if (abs(num1) < EPS) {
        return complex_num{NAN, NAN};
    }

    return complex_num{Re / num1, Im / num1};
}

bool complex::complex_num::operator > (const complex_num &num1) const 
{
    if (abs(num1.Im) > EPS || abs(Im) > EPS) {
        return 0;
    }

    return Re > num1.Re;
}

bool complex::complex_num::operator < (const complex_num &num1) const 
{
    if (abs(num1.Im) > EPS || abs(Im) > EPS) {
        return 0;
    }

    return Re < num1.Re;
}