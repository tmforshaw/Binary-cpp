#pragma once
#include "../../Other/Constants.h"
#include "../Binary.h"
#include <ostream>
#include <vector>

class BinaryInt : public Binary
{
private:
	bool m_bits[intByteNum * 8] = {};

public:
	BinaryInt();
	BinaryInt(std::string strBits);
	BinaryInt(int decVal);

	bool* GetBits();
	bool GetBit(unsigned int i) const;
	void SetBit(unsigned int i, bool val);

	const int SizeOf() const;

	// Assignment operators
	void operator=(std::string strBits);
	void operator=(int decVal) const;

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
	void operator++();
	void operator++(int);
	void operator--();
	void operator--(int);

	BinaryInt Abs() const;

	// Shift operators
	BinaryInt operator>>(int amt) const;
	BinaryInt operator<<(int amt) const;

	// Conversion Functions
	std::string ToBase(const BinaryInt& base) const;
	std::string ToDec() const;
	std::string ToHex() const;
};