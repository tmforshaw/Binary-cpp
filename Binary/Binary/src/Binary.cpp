#include "Binary.h"
#include <iostream>
#include <algorithm>

Binary::Binary()
{
	// Return a Binary of 0
	for (int i = 0; i < this->SizeOf(); i++)
		Binary::m_bits[i] = 0;
}

Binary::Binary(std::string strBits)
{
	// Remove spaces from strBits
	strBits.erase(remove_if(strBits.begin(), strBits.end(), [](const char& c) { return c == ' '; }), strBits.end());

	// Loop will not count most significant bits that appear after the size in bits

	for (int i = (int)strBits.length() - 1; i >= 0; i--) // Loop through backwards (Start with least significant bit)
	{
		// Set the n-th element of m_bits to the value of 1 or 0

		if (strBits[i] - '0') // Everything above zero
			Binary::m_bits[(int)strBits.length() - 1 - i] = 1;
		else // Zero
			Binary::m_bits[(int)strBits.length() - 1 - i] = 0;
	}
}

bool* Binary::GetBits() { return Binary::m_bits; }

bool Binary::GetBit(unsigned int i) const { return Binary::m_bits[i]; }

void Binary::SetBit(unsigned int i, bool val) { Binary::m_bits[i] = val; }

const int Binary::SizeOf() const { return defaultByteNum * 8; }

Binary Binary::operator!() const
{
	Binary output("0");

	for (int i = 0; i < this->SizeOf(); i++)
	{
		output.SetBit(i, !this->GetBit(i));
	}

	return output;
}


// Method for outputting Binary using iostream
std::ostream& operator<<(std::ostream& stream, const Binary& bin)
{
	for (int i = bin.SizeOf() - 1; i >= 0; i--) // Loop through backwards (Start with most significant bit)
	{
		stream << bin.GetBit(i);

		if (padNibbles && i % 4 == 0) stream << ' ';

		if (padBytes && i % 8 == 0)
		{
			stream << ' ';

			// if (padNibbles) stream << ' '; // Extra Padding between bytes
		}
	}

	return stream;
}