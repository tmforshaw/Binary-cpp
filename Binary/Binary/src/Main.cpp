#include <iostream>
#include "Binary.h"
#include "BinaryInt.h"

BinaryInt bin1("0000 1101");
BinaryInt bin2("0000 0011");

int main()
{
	std::cout << bin1 << std::endl;
	std::cout << bin2 << std::endl;
	std::cout << bin1 + bin2 << std::endl;

	std::cin.get();
}