#include "BinaryInt.h"

BinaryInt::BinaryInt()
{
	// Return a Binary of 0
	for (int i = 0; i < this->SizeOf(); i++)
		BinaryInt::m_bits[i] = 0;
}

BinaryInt::BinaryInt(std::string strBits)
{
	// Remove spaces from strBits
	strBits.erase(remove_if(strBits.begin(), strBits.end(), [](const char& c) { return c == ' '; }), strBits.end());

	// Loop will not count most significant bits that appear after the size in bits

	for (int i = (int)strBits.length() - 1; i >= 0; i--) // Loop through backwards (Start with least significant bit)
	{
		// Set the n-th element of m_bits to the value of 1 or 0

		if (strBits[i] - '0') // Everything above zero
			BinaryInt::m_bits[(int)strBits.length() - 1 - i] = 1;
		else // Zero
			BinaryInt::m_bits[(int)strBits.length() - 1 - i] = 0;
	}
}

bool* BinaryInt::GetBits() { return BinaryInt::m_bits; }

bool BinaryInt::GetBit(unsigned int i) const { return BinaryInt::m_bits[i]; }

void BinaryInt::SetBit(unsigned int i, bool val) { BinaryInt::m_bits[i] = val; }

const int BinaryInt::SizeOf() const { return intByteNum * 8; }


// Boolean Operators


BinaryInt BinaryInt::operator!() const
{
	BinaryInt output("0");

	for (int i = 0; i < this->SizeOf(); i++)
	{
		output.SetBit(i, !this->GetBit(i));
	}

	return output;
}

bool BinaryInt::operator==(const BinaryInt& other) const
{
	for (int i = 0; i < this->SizeOf(); i++)
		if (this->GetBit(i) != other.GetBit(i))
			return false;

	return true;
}

bool BinaryInt::operator>(const BinaryInt& other) const
{
	return (*this - other).GetBit(0) == 0;
}

bool BinaryInt::operator>=(const BinaryInt& other) const
{
	return (*this - other).GetBit(0) == 0 || *this == other;
}

bool BinaryInt::operator<(const BinaryInt& other) const
{
	return (*this - other).GetBit(0) == 1;
}

bool BinaryInt::operator<=(const BinaryInt& other) const
{
	return (*this - other).GetBit(0) == 1 || *this == other;
}


// Maths operators


BinaryInt BinaryInt::operator+(const BinaryInt& other) const
{
	BinaryInt output = BinaryInt("0"); // Initialise to zero
	bool carryBit = 0; // Initialise to zero

	for (int i = 0; i < this->SizeOf(); i++) // Loop through bits (Least significant first)
	{
		// Boolean Expressions Creating a half-adder
		if (this->GetBit(i)) // Bit i of this is 1
		{
			output.SetBit(i, (other.GetBit(i) && carryBit) || !(other.GetBit(i) || carryBit)); // Both or Neither of other bits
			carryBit = (other.GetBit(i) || carryBit);
		} else if (other.GetBit(i)) // Bit i of other is 1
		{
			output.SetBit(i, !carryBit);
			// Carry is unchanged
		} else
		{
			output.SetBit(i, carryBit);
			carryBit = 0;
		}
	}

	return output;
}

void BinaryInt::operator+=(const BinaryInt& other) { *this = *this + other; }

BinaryInt BinaryInt::operator-(const BinaryInt& other) const
{
	BinaryInt output = !other + BinaryInt("1");

	return output + *this;
}

void BinaryInt::operator-=(const BinaryInt& other) { *this = *this + other; }

BinaryInt BinaryInt::operator*(const BinaryInt& other) const
{
	BinaryInt output("0"); // Initialise to zero

	for (int i = 0; i < this->SizeOf(); i++) // Loop through (Starting with least significant bit)
	{
		if (this->GetBit(i))
			output += ((BinaryInt)other >> i);
	}

	return output;
}

void BinaryInt::operator*=(const BinaryInt& other) { *this = *this * other; }

BinaryInt BinaryInt::operator/(const BinaryInt& other) const
{
	BinaryInt output("0"); // Initialise to zero

	return output;
}

void BinaryInt::operator/=(const BinaryInt& other) { *this = *this / other; }


// Shift operators


BinaryInt BinaryInt::operator>>(int amt) const
{
	BinaryInt output = *this;

	for (int i = 0; i < amt; i++)
	{
		for (int j = output.SizeOf() - 1; j > 0; j--)
		{
			output.SetBit(j, output.GetBit(j - 1));
		}
		output.SetBit(0, 0);
	}

	return output;
}

BinaryInt BinaryInt::operator<<(int amt) const
{
	BinaryInt output = *this;

	for (int i = 0; i < amt; i++)
	{
		for (int j = 0; j < output.SizeOf() - 1; j++)
		{
			output.SetBit(j, output.GetBit(j + 1));
		}
		output.SetBit(output.SizeOf() - 1, 0);
	}

	return output;
}
