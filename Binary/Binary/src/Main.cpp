#include <iostream>
#include "Binary.h"
#include "BinaryInt.h"

BinaryInt bin1(127);
BinaryInt bin2(-10);

int main()
{
	std::cout << "Binary Calculations:" << std::endl << std::endl;

	std::cout << bin1 << "   " << bin1.ToDec() << std::endl;
	std::cout << bin2 << "   " << bin2.ToDec() << std::endl;

	BinaryInt bin3 = bin1 / bin2;
	std::cout << bin3 << "   " << bin3.ToDec() << std::endl;

	std::cin.get();
}