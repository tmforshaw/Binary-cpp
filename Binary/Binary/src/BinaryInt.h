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
	bool operator==(const BinaryInt& other) const;
	bool operator!=(const BinaryInt& other) const;
	bool operator>(const BinaryInt& other) const;
	bool operator>=(const BinaryInt& other) const;
	bool operator<(const BinaryInt& other) const;
	bool operator<=(const BinaryInt& other) const;

	// Maths operators

	BinaryInt operator+(const BinaryInt& other) const;
	void operator+=(const BinaryInt& other);
	BinaryInt operator-(const BinaryInt& other) const;
	void operator-=(const BinaryInt& other);
	BinaryInt operator*(const BinaryInt& other) const;
	void operator*=(const BinaryInt& other);
	BinaryInt operator/(const BinaryInt& other) const;
	void operator/=(const BinaryInt& other);
	BinaryInt operator%(const BinaryInt& other) const;
	void operator%=(const BinaryInt& other);

	// Shift operators
	BinaryInt operator>>(int amt) const;
	BinaryInt operator<<(int amt) const;
};