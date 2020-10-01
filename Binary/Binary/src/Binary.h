#pragma once
#include "Constants.h"
#include <string>

class Binary
{
private:
	bool m_bits[defaultByteNum * 8] = {};

public:
	Binary();
	Binary(std::string strBits);
	Binary(unsigned int decVal);

	virtual bool* GetBits();
	virtual bool GetBit(unsigned int i) const;
	virtual void SetBit(unsigned int i, bool val);

	virtual const int SizeOf() const;

	// Boolean operators

	Binary operator!() const;

	// Stream Function
	friend std::ostream& operator<<(std::ostream& stream, const Binary& bin);
};

// Method for outputting Binary using iostream
std::ostream& operator<<(std::ostream& stream, const Binary& bin);