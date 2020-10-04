#pragma once

// Sizes of binary numbers

const unsigned int defaultByteNum = 1;
const unsigned int intByteNum = 1;
const unsigned int floatByteNum = 1;

// Float information

const unsigned int expBitNum = 3;
const unsigned int mantissaBitNum = floatByteNum * 8 - 1 - expBitNum;

// Format of outputted binary

const bool padNibbles = true; // Add spacing between nibbles
const bool padBytes = false; // Add spacing between bytes

/*	If Both padNibbles and padBytes are enabled there will be
	more padding around bytes to differentiate them. */