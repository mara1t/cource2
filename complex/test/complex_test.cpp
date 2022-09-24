#include "complex.h"

static int test_add_bin()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num num2{3, 5};
    complex::complex_num res = num1 + num2;

    return res.Re == 4 && res.Im == 7;
}

static int test_add_un()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num res = + num1;

    return res.Re == 1 && res.Im == 2;
}

static int test_sub_bin()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num num2{3, 5};
    complex::complex_num res = num1 - num2;

    return res.Re == -2 && res.Im == -3;
}

static int test_sub_un()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num res = - num1;

    return res.Re == -1 && res.Im == -2;
}

static int test_mul()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num num2{3, 5};
    complex::complex_num res = num1 * num2;
    
    return res.Re == -7 && res.Im == 11;
}

static int test_double_mul()
{   
    complex::complex_num num1{1, 2};
    double num2 = 5;
    complex::complex_num res = num1 * num2;
    
    return res.Re == 5 && res.Im == 10;
}

static int test_div()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num num2{2, 4};
    complex::complex_num res = num1 / num2;
    
    return res.Re == 0.5 && res.Im == 0;
}

static int test_double_div()
{   
    complex::complex_num num1{1, 2};
    double num2 = 10;
    complex::complex_num res = num1 / num2;
    
    return res.Re == 0.1 && res.Im == 0.2;
}

static int test_less()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num num2{2, 4};
    bool res = num1 < num2;
    
    return res != res;
}

static int test_more()
{   
    complex::complex_num num1{1, 2};
    complex::complex_num num2{2, 4};
    bool res = num1 > num2;
    
    return res != res;
}

int main()
{
    if (!test_add_bin() || !test_add_un() || !test_sub_bin() || !test_sub_un() || !test_mul() || 
    !test_double_mul() || !test_div() || !test_double_div()) {
        return -1;
    }
    
    return 0;
}