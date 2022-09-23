#include "..//include//complex.h"

int main()
{
    complex::complex_num<double> tmp_num1{10, 20};
    std::cout << "first num = ";
    tmp_num1.print_num();

    complex::complex_num<double> tmp_num2{10, 20};
    std::cout << "second num = ";
    tmp_num2.print_num();
    
    complex::complex_num<double> tmp_num3;

    tmp_num3 = tmp_num2 + tmp_num1;
    std::cout << "sum = ";
    tmp_num3.print_num();

    tmp_num3 = tmp_num2 * tmp_num1;
    std::cout << "sub = ";
    tmp_num3.print_num();

    tmp_num3 = tmp_num1 / tmp_num2;
    std::cout << "div = ";
    tmp_num3.print_num();
    return 0;
}