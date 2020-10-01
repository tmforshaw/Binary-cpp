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

BinaryInt::BinaryInt(int decVal)
{
	// Find and remove sign
	bool negative = decVal < 0;
	int decimalValue = decVal;
	if (negative) decimalValue *= -1;

	for (int i = this->SizeOf() - 2; i >= 0; i--) // Loop backwards (Skip sign bit)
	{
		if (decimalValue >= (int)pow(2, i))
		{
			decimalValue -= (int)pow(2, i);
			SetBit(i, 1);
		} else SetBit(i, 0);
	}

	if (negative) // Two's complement
	{
		(*this)--;
		*this = !(*this);
	}
}

bool* BinaryInt::GetBits() { return BinaryInt::m_bits; }

bool BinaryInt::GetBit(unsigned int i) const { return BinaryInt::m_bits[i]; }

void BinaryInt::SetBit(unsigned int i, bool val) { BinaryInt::m_bits[i] = val; }

const int BinaryInt::SizeOf() const { return intByteNum * 8; }


// Assignment Operator


void BinaryInt::operator=(unsigned int decVal) const
{
	BinaryInt::BinaryInt(decVal);
}


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

bool BinaryInt::operator!=(const BinaryInt& other) const
{
	for (int i = 0; i < this->SizeOf(); i++)
		if (this->GetBit(i) != other.GetBit(i))
			return true;

	return false;
}

bool BinaryInt::operator>(const BinaryInt& other) const
{
	for (int i = this->SizeOf() - 1; i >= 0; i--)
		if (this->GetBit(i) != other.GetBit(i))
			return this->GetBit(i);

	return false;
}

bool BinaryInt::operator>=(const BinaryInt& other) const
{
	for (int i = this->SizeOf() - 1; i >= 0; i--)
		if (this->GetBit(i) != other.GetBit(i))
			return this->GetBit(i);

	return true;
}

bool BinaryInt::operator<(const BinaryInt& other) const
{
	for (int i = this->SizeOf() - 1; i >= 0; i--)
		if (this->GetBit(i) != other.GetBit(i))
			return !this->GetBit(i);

	return false;
}

bool BinaryInt::operator<=(const BinaryInt& other) const
{
	for (int i = this->SizeOf() - 1; i >= 0; i--)
		if (this->GetBit(i) != other.GetBit(i))
			return !this->GetBit(i);

	return true;
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

void BinaryInt::operator-=(const BinaryInt& other) { *this = *this - other; }

BinaryInt BinaryInt::operator*(const BinaryInt& other) const
{
	BinaryInt total("0"); // Initialise to zero

	BinaryInt unsignedThis = *this;
	BinaryInt unsignedOther = other;

	bool negativeThis = unsignedThis.GetBit(unsignedThis.SizeOf() - 1);
	if (negativeThis) // Remove Two's complement
	{
		unsignedThis--;
		unsignedThis = !unsignedThis;
	}

	bool negativeOther = unsignedOther.GetBit(unsignedOther.SizeOf() - 1);
	if (negativeOther) // Remove Two's complement
	{
		unsignedOther--;
		unsignedOther = !unsignedOther;
	}

	for (int i = 0; i < this->SizeOf() - 1; i++) // Loop through (Starting with least significant bit) (Skip sign bit)
	{
		if (unsignedThis.GetBit(i))
			total += (unsignedOther << i);
	}

	total.SetBit(this->SizeOf() - 1, (negativeThis && !negativeOther) || (negativeOther && !negativeThis)); // Set sign bit

	return total;
}

void BinaryInt::operator*=(const BinaryInt& other) { *this = *this * other; }

BinaryInt BinaryInt::operator/(const BinaryInt& other) const
{
	BinaryInt quotient("0"); // Initialise to zero

	BinaryInt divisor = other;
	BinaryInt dividend = *this;

	// Remove Signs
	bool negativeDividend = dividend.GetBit(dividend.SizeOf() - 1);
	if (negativeDividend) // Remove Two's complement
	{
		dividend--;
		dividend = !dividend;
	}

	bool negativeDivisor = divisor.GetBit(divisor.SizeOf() - 1);
	if (negativeDivisor) // Remove Two's complement
	{
		divisor--;
		divisor = !divisor;
	}

	if (divisor > dividend && !(divisor == quotient || dividend == quotient)) // Divisor is bigger, or one is equal to zero
		return quotient;

	// Find most significant bit
	int dividendMS = -1, divisorMS = -1;

	for (int i = this->SizeOf() - 1; i >= 0 && (dividendMS == -1 || divisorMS == -1); i--) // Loop backwards (Skip sign bit)
	{
		if (dividend.GetBit(i) && dividendMS == -1)
			dividendMS = i;
		if (divisor.GetBit(i) && divisorMS == -1)
			divisorMS = i;
	}

	divisor = divisor << (dividendMS - divisorMS);

	for (int i = 0; dividend >= other.Abs(); i++) // More than original divisor (Still gets checked to eliminate a final unnecessary loop)
	{
		if (dividend >= divisor) // If it's more than the divisor
		{
			dividend -= divisor; // Subtract shifted divisor from dividend
			quotient.SetBit(dividendMS - divisorMS - i, 1); // Set quotient bit to 1
		}

		if (dividend < other.Abs()) // If it's less than original divisor
			break;

		divisor = divisor >> 1; // Divide divisor by 2
	}

	// Give sign back to quotient
	if ((negativeDividend && !negativeDivisor) || (negativeDivisor && !negativeDividend))
	{
		quotient--;
		quotient = !quotient;
	}

	return quotient;
}

void BinaryInt::operator/=(const BinaryInt& other) { *this = *this / other; }

BinaryInt BinaryInt::operator%(const BinaryInt& other) const
{
	BinaryInt divisor = other;
	BinaryInt dividend = *this;

	// Remove Signs
	bool negativeDividend = dividend.GetBit(dividend.SizeOf() - 1);
	if (negativeDividend) // Remove Two's complement
	{
		dividend--;
		dividend = !dividend;
	}

	bool negativeDivisor = divisor.GetBit(divisor.SizeOf() - 1);
	if (negativeDivisor) // Remove Two's complement
	{
		divisor--;
		divisor = !divisor;
	}

	if (divisor > dividend && !(divisor == BinaryInt("0") || dividend == BinaryInt("0"))) // Divisor is bigger, or one is equal to zero
		return dividend;

	// Find most significant bit
	int dividendMS = -1, divisorMS = -1;

	for (int i = this->SizeOf() - 2; i >= 0 && (dividendMS == -1 || divisorMS == -1); i--) // Skip sign bit
	{
		if (dividend.GetBit(i) && dividendMS == -1)
			dividendMS = i;
		if (divisor.GetBit(i) && divisorMS == -1)
			divisorMS = i;
	}

	divisor = divisor << (dividendMS - divisorMS);

	for (int i = 0; dividend >= other.Abs(); i++) // More than original divisor (Still gets checked to eliminate a final unnecessary loop)
	{
		if (dividend >= divisor) // If it's more than the divisor
		{
			dividend -= divisor; // Subtract shifted divisor from dividend
		}

		if (dividend < other.Abs()) // If it's less than original divisor
			break;

		divisor = divisor >> 1; // Divide divisor by 2
	}

	// Modulo negative is only affected by dividend
	if (negativeDividend)
	{
		dividend++;
		dividend = !dividend;
	}

	return dividend;
}

void BinaryInt::operator%=(const BinaryInt& other) { *this = *this % other; }

void BinaryInt::operator++()
{
	*this += BinaryInt("1");
}

void BinaryInt::operator++(int)
{
	++(*this);
}

void BinaryInt::operator--()
{
	*this -= BinaryInt("1");
}

void BinaryInt::operator--(int)
{
	--(*this);
}

BinaryInt BinaryInt::Abs() const
{
	if (this->GetBit(this->SizeOf() - 1)) // Is negative
	{
		BinaryInt output = *this;
		output--;
		output = !output;

		return output;
	}
	return *this;
}


// Shift operators


BinaryInt BinaryInt::operator>>(int amt) const
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

BinaryInt BinaryInt::operator<<(int amt) const
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


// Conversion Functions


std::string BinaryInt::ToBase(const BinaryInt& divisor) const
{
	BinaryInt dividend = *this;
	std::vector<BinaryInt> digits;
	std::vector<char> charDigits;
	std::string finalDigits;

	// Get sign of the number
	bool negative = this->GetBit(this->SizeOf() - 1);
	if (negative) // Remove Two's complement
	{
		dividend--;
		dividend = !dividend;
		finalDigits += '-'; // Add a sign to the final answer
	}

	while (dividend >= divisor)
	{
		digits.push_back(dividend % divisor);
		dividend /= divisor;
	}

	digits.push_back(dividend);

	// THIS IS NOT HOW COMPUTERS WOULD DO THIS STEP

	for (int i = digits.size() - 1; i >= 0; i--)
	{
		int digitTotal = 0;
		for (int j = 0; j < this->SizeOf(); j++)
			digitTotal += digits[i].GetBit(j) * (int)pow(2, j);

		charDigits.push_back(
			((char)digitTotal > 9) ?
			(char)digitTotal + 'A' - 10 :
			(char)digitTotal + '0'
		);
	}

	for (int i = 0; i < (int)charDigits.size(); i++)
		finalDigits += charDigits[i];

	return finalDigits;
}

std::string BinaryInt::ToDec() const { return BinaryInt::ToBase(BinaryInt("1010")); }

std::string BinaryInt::ToHex() const { return BinaryInt::ToBase(BinaryInt("1 0000")); }