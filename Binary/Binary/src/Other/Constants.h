#pragma once

// Sizes of binary numbers

const unsigned int defaultByteNum = 1;
const unsigned int intByteNum = 1;

// Format of outputted binary

const bool padNibbles = true; // Add spacing between nibbles
const bool padBytes = false; // Add spacing between bytes

/*	If Both padNibbles and padBytes are enabled there will be
	more padding around bytes to differentiate them. */