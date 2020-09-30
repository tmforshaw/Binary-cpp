#include "Binary.h"
#include <iostream>
#include <algorithm>

Binary::Binary()
{
	// Return a Binary of 0
	for (int i = 0; i < defaultByteNum * 8; i++)
		m_bits[i] = 0;
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
			m_bits[(int)strBits.length() - 1 - i] = 1;
		else // Zero
			m_bits[(int)strBits.length() - 1 - i] = 0;
	}
}

bool* Binary::GetBits() { return m_bits; }

bool Binary::GetBit(unsigned int i) { return m_bits[i]; }

void Binary::SetBit(unsigned int i, bool val) { m_bits[i] = val; }


// Method for outputting Binary using iostream

std::ostream& operator<<(std::ostream& stream, Binary& bin)
{
	for (int i = defaultByteNum * 8 - 1; i >= 0; i--) // Loop through backwards (Start with most significant bit)
	{
		stream << bin.GetBit(i);

		if (spaceNibbles && i % 4 == 0) stream << ' ';

		if (padBytes && i % 8 == 0)
		{
			stream << ' ';

			// if (spaceNibbles) stream << ' '; // Extra Padding between bytes
		}
	}

	return stream;
}