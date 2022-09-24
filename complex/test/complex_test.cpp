#include "complex.h"

static int test_add()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num num2{3, 5};
    complex::complex_num res = num1 + num2;

    return res.Re == 4 && res.Im == 7;
}
static int test_sub()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num num2{3, 5};
    complex::complex_num res = num1 - num2;

    return res.Re == -2 && res.Im == -3;
}
static int test_mul()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num num2{3, 5};
    complex::complex_num res = num1 * num2;
    
    return res.Re == -7 && res.Im == 11;
}
static int test_div()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num num2{2, 4};
    complex::complex_num res = num1 / num2;
    
    return res.Re == 0.5 && res.Im == 0;
}

int main()
{
    if (!test_add() || !test_sub() || !test_mul() || !test_div()) {
        return -1;
    }
    
    return 0;
}