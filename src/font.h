#include <avr/pgmspace.h>

#ifndef FONT_H
#define FONT_H

// Font character bitmap height and width
#define CHAR_H 8
#define CHAR_W 5

// remove offset from ascii upper- and lowercase character values to align with 
// array index for easy access. "A" has value 0x41, "a" 0x61
#define UC_IDX(c) (c-0x41)
#define LC_IDX(c) (c-0x61)	

// symbol bitmap arrays for uppercase characters. Runlength encoded going
// from top to bottom, left to right. 
// Data is encoded using a bit depth of 1, every bit in the array maps
// a pixel.
const uc_a[] PROGMEM = {0x3f, 0x48, 0x48, 0x48, 0x3f};
const uc_b[] PROGMEM = {0x7f, 0x49, 0x49, 0x49, 0x36};
const uc_c[] PROGMEM = {0x32, 0x41, 0x41, 0x41, 0x22};
const uc_d[] PROGMEM = {0x7f, 0x41, 0x41, 0x41, 0x3e};

// Array of symbol bitmap arrays, bitmap data can be easily accessed
// through uc_chars[UC_IDX(char)][pixel]
const uc_chars[] PROGMEM = {
	uc_a,
	uc_b,
	uc_c,
	uc_d,
};

#endif FONT_H