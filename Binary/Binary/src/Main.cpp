#include <iostream>
#include "Binary.h"
#include "BinaryInt.h"

BinaryInt bin1 = 10;
BinaryInt bin2 = -120;
BinaryInt bin3 = bin2;

void DisplayEquation(BinaryInt b1, char operation, BinaryInt b2)
{
	BinaryInt result = 0;

	switch (operation)
	{
	case('+'):
		result = b1 + b2;
		break;
	case('-'):
		result = b1 - b2;
		break;
	case('*'):
		result = b1 * b2;
		break;
	case('/'):
		result = b1 / b2;
		break;
	case('%'):
		result = b1 % b2;

	default:
		result = "0";
		break;
	}

	std::cout << b1 << ' ' << operation << ' ' << b2 << " = " << result << std::endl;
	std::cout << b1.ToDec() << ' ' << operation << ' ' << b2.ToDec() << " = " << result.ToDec() << std::endl;
}

int main()
{
	std::cout << "Binary Calculations:" << std::endl << std::endl;

	std::cout << bin1 << " : " << bin1.ToDec() << std::endl;
	std::cout << bin2 << " : " << bin2.ToDec() << std::endl;
	std::cout << bin3 << " : " << bin3.ToDec() << std::endl;

	DisplayEquation(bin1, '+', bin2);

	std::cin.get();
}