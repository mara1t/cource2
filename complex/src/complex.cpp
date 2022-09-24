#include "..//include//complex.h"
using namespace complex;

const double EPS = 0.00001;

int test_num()
{
    double Im1, Re1, Im2, Re2;

    std::cin >> Re1 >> Im1 >> Re2 >> Im2;

    complex::complex_num tmp_num1{Re1, Im1};
    complex::complex_num tmp_num2{Re2, Im2}; 
    complex::complex_num res{};

    std::cout << "first num = ";
    tmp_num1.print_num();
    std::cout << "second num = ";

    tmp_num2.print_num();
    res = tmp_num1 + tmp_num2;
    std::cout << "add = ";
    res.print_num();

    res = tmp_num1 - tmp_num2;
    std::cout << "sub = ";
    res.print_num();

    res = tmp_num1 * tmp_num2;
    std::cout << "mul = ";
    res.print_num();

    res = tmp_num1 / tmp_num2;
    std::cout << "div = ";
    res.print_num();

    return 0;
}

bool complex_num::is_zero() const
{
    return ((abs(Re) < EPS) && (abs(Im) < EPS));
}

void complex_num::print_num() const 
{
    std::cout << Re;
    if (fabs(Im) >= EPS) {
        std::cout << " + i*" << Im;
    }
    std::cout << std::endl;
}

complex_num::complex_num() : Re{0}, Im{0} {}

complex_num::complex_num(const double a, const double b) : Re{a}, Im{b} {}

complex_num::complex_num(const complex_num &another_comp_num) : Re{another_comp_num.Re}, Im{another_comp_num.Im} {}

complex_num complex_num::operator + (const complex_num &num1) const
{   
    return complex_num{Re + num1.Re, Im + num1.Im};
}

complex_num complex_num::operator + () const
{   
    return *this;
}

complex_num complex_num::operator - (const complex_num &num1) const
{   
    return complex_num{Re - num1.Re, Im - num1.Im};
}

complex_num complex_num::operator - () const
{   
    return complex_num{- Re, - Im};
}

complex_num complex_num::operator * (const complex_num &num1) const
{   
    return complex_num{Re * num1.Re - Im * num1.Im, Re * num1.Im + Im * num1.Re};
}

complex_num complex_num::operator * (const double num2) const
{   
    return complex_num{Re * num2, Im * num2};
}

complex_num complex_num::operator / (const complex_num &num1) const
{   
    if (num1.is_zero()) {
        return complex_num{NAN, NAN};
    }
    return complex_num{(Re * num1.Re + Im * num1.Im) / (num1.Re * num1.Re + num1.Im * num1.Im), 
        (Im * num1.Re - Re * num1.Im) / (num1.Re * num1.Re + num1.Im * num1.Im)};
}

complex_num complex_num::operator / (const double num1) const
{   
    if (abs(num1) < EPS) {
        return complex_num{NAN, NAN};
    }

    return complex_num{Re / num1, Im / num1};
}

bool complex_num::operator > (const complex_num &num1) const 
{
    if (abs(num1.Im) > EPS || abs(Im) > EPS) {
        return 0;
    }

    return Re > num1.Re;
}

bool complex_num::operator < (const complex_num &num1) const 
{
    if (abs(num1.Im) > EPS || abs(Im) > EPS) {
        return 0;
    }

    return Re < num1.Re;
}