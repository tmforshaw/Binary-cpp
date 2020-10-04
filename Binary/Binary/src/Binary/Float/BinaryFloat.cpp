#include "BinaryFloat.h"
#include "../Int/BinaryInt.h"

BinaryFloat::BinaryFloat()
{
	// Return a Binary of 0
	for (int i = 0; i < this->SizeOf(); i++)
		this->SetBit(i, 0);
}

BinaryFloat::BinaryFloat(std::string strBits)
{
	// Remove spaces from strBits
	strBits.erase(remove_if(strBits.begin(), strBits.end(), [](const char& c) { return c == ' '; }), strBits.end());

	// Loop will not count most significant bits that appear after the size in bits

	for (int i = (int)strBits.length() - 1; i >= 0; i--) // Loop through backwards (Start with least significant bit)
	{
		// Set the n-th element of m_bits to the value of 1 or 0

		if (strBits[i] - '0') // Everything above zero
			this->SetBit((int)strBits.length() - 1 - i, 1);
		else // Zero
			this->SetBit((int)strBits.length() - 1 - i, 0);
	}
}

BinaryFloat::BinaryFloat(float decVal)
{
	// Find Integer part
	BinaryInt intPartFull;
	std::string intPart;
	std::string fracPart;

	// Find and remove sign
	bool negative = decVal < 0;
	int decIntValue = decVal;
	float decFloatValue = decVal - (float)decIntValue;
	if (negative) decIntValue *= -1;

	for (int i = this->SizeOf() - 2; i >= 0; i--) // Loop backwards (Skip sign bit)
	{
		if (decIntValue >= (int)pow(2, i))
		{
			decIntValue -= (int)pow(2, i);
			intPartFull.SetBit(i, 1);
		} else intPartFull.SetBit(i, 0);
	}

	if (negative) // Two's complement
	{
		intPartFull--;
		intPartFull = !intPartFull;
	}

	for (int i = 0; i < intPartFull.SizeOf(); i++) // Turn into string
		intPart += intPartFull.GetBit(i);

	delete& intPartFull; // Cleans up memory

	// Float part

}

bool* BinaryFloat::GetBits() { return m_bits; }

bool BinaryFloat::GetBit(unsigned int i) const { return m_bits[i]; }

void BinaryFloat::SetBit(unsigned int i, bool val) { m_bits[i] = val; }

const int BinaryFloat::SizeOf() const { return floatByteNum * 8; }

std::string BinaryFloat::Denormalise()
{
	// Denormalise the float

	return std::string();
}
