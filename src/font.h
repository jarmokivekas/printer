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
// These arrays will be CHAR_H * CHAR_W in size.
const uc_a[] PROGMEM = {}
const uc_b[] PROGMEM = {}
const uc_c[] PROGMEM = {}
const uc_d[] PROGMEM = {}

// Array of symbol bitmap arrays, bitmap data can be easily accessed
// through uc_chars[UC_IDX(char)][pixel]
const uc_chars[] PROGMEM = {
	uc_a,
	uc_b,
	uc_c,
	uc_d,
}

#endif FONT_H