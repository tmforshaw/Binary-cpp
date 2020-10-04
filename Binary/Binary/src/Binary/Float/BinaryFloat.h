#pragma once
#include "../Binary.h"
#include "../../Other/Constants.h"

class BinaryFloat : public Binary
{
private:
	bool m_bits[floatByteNum * 8] = {};

public:
	BinaryFloat();
	BinaryFloat(std::string strBits);
	BinaryFloat(float decVal);

	bool* GetBits();
	bool GetBit(unsigned int i) const;
	void SetBit(unsigned int i, bool val);

	const int SizeOf() const;

	// Display as Float
	std::string Denormalise();
};

