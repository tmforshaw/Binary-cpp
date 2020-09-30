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

	bool* GetBits();
	bool GetBit(unsigned int i);
	void SetBit(unsigned int i, bool val);
};


// Method for outputting Binary using iostream

std::ostream& operator<<(std::ostream& stream, Binary& bin);