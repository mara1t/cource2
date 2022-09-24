#include "..//include//complex.h"

using namespace complex;

int test_add()
{   
    complex_num num1{1, 2};
    complex_num num2{3, 5};
    complex_num res = num1 + num2;
    assert(res.Re == 4 && res.Im == 7);

    return 0;
}
int test_sub()
{   
    complex_num num1{1, 2};
    complex_num num2{3, 5};
    complex_num res = num1 - num2;
    assert(res.Re == -2 && res.Im == -3);
    return 0;
}
int test_mul()
{   
    complex_num num1{1, 2};
    complex_num num2{3, 5};
    complex_num res = num1 * num2;
    assert(res.Re == -7 && res.Im == 11);
    return 0;
}
int test_div()
{   
    complex_num num1{1, 2};
    complex_num num2{2, 4};
    complex_num res = num1 / num2;
    assert(res.Re == 0.5 && res.Im == 0);
    return 0;
}

int main()
{
    test_add();
    test_sub();
    test_mul();
    test_div();

    return 0;
}