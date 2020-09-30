#pragma once
#include "Constants.h"
#include "Binary.h"
#include <iostream>

class BinaryInt : public Binary
{
private:
	bool m_bits[intByteNum * 8] = {};

public:
	BinaryInt();
	BinaryInt(std::string strBits);

	bool* GetBits();
	bool GetBit(unsigned int i) const;
	void SetBit(unsigned int i, bool val);

	const int SizeOf() const;

	// Boolean operators

	BinaryInt operator!() const;

	// Maths operators

	BinaryInt operator+(const BinaryInt& other) const;
	BinaryInt operator-(const BinaryInt& other) const;
	BinaryInt operator*(const BinaryInt& other) const;
	BinaryInt operator/(const BinaryInt& other) const;
};