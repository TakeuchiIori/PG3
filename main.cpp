#include <stdio.h>
#include "Test.h"
#include <iostream>


int main() {

	
    // int : float
    Test<int, float> minIntFloat(3, 2.1f);
    std::cout << "Min(int, float): " << minIntFloat.Min() << std::endl;

    // int : double 
    Test<int, double> minIntDouble(6, 7.2);
    std::cout << "Min(int, double): " << minIntDouble.Min() << std::endl;

    // float : int 
    Test<float, int> minFloatInt(8.7f, 10);
    std::cout << "Min(float, int): " << minFloatInt.Min() << std::endl;

    // float : double 
    Test<float, double> minFloatDouble(8.5f, 9.5);
    std::cout << "Min(float, double): " << minFloatDouble.Min() << std::endl;

    // double : int 
    Test<double, int> minDoubleInt(22.5, 8);
    std::cout << "Min(double, int): " << minDoubleInt.Min() << std::endl;

    // double : float 
    Test<double, float> minDoubleFloat(22.5, 73.5f);
    std::cout << "Min(double, float): " << minDoubleFloat.Min() << std::endl;

	return 0;
}