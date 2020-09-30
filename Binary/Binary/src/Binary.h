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

	virtual bool* GetBits();
	virtual bool GetBit(unsigned int i) const;
	virtual void SetBit(unsigned int i, bool val);

	virtual const int SizeOf() const;

	// Operators

	Binary operator!() const;

	friend std::ostream& operator<<(std::ostream& stream, const Binary& bin);
};

// Method for outputting Binary using iostream
std::ostream& operator<<(std::ostream& stream, const Binary& bin);