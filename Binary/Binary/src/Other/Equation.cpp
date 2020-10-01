#include "Equation.h"
#include <iostream>

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
	};

	std::cout << b1 << ' ' << operation << ' ' << b2 << " = " << result << " = ";
	std::cout << b1.ToDec() << ' ' << operation << ' ' << b2.ToDec() << " = " << result.ToDec() << std::endl;
}
