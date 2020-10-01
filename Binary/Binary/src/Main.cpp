#include <iostream>
#include "Binary/Binary.h"
#include "Binary/Int/BinaryInt.h"
#include "Other/Equation.h"

BinaryInt bin1 = 10;
BinaryInt bin2 = -120;

int main()
{
	std::cout << "Binary Calculations:" << std::endl << std::endl;

	std::cout << bin1 << " : " << bin1.ToDec() << std::endl;
	std::cout << bin2 << " : " << bin2.ToDec() << std::endl;

	std::cin.get();
}