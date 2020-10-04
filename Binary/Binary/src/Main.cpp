#include <iostream>
#include "Binary/Binary.h"
#include "Binary/Int/BinaryInt.h"
#include "Binary/Float/BinaryFloat.h"
#include "Other/Equation.h"

BinaryFloat bin1("1001 1001");
BinaryFloat bin2("1001 1001");

int main()
{
	std::cout << "Binary Calculations:" << std::endl << std::endl;

	std::cout << bin1 << std::endl;
	std::cout << bin2 << std::endl;

	std::cin.get();
}