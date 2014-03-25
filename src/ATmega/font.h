#include <avr/pgmspace.h>
#include "main.h"


#ifndef FONT_H
#define FONT_H

// Font character bitmap height and width
#define CHAR_H 8
#define CHAR_W 5

// Macro for accessing bitmaps[] / deprecated use fontBitmapReadColumn()
#define BM_IDX(c) ((c-0x20) * CHAR_W)

// Returns bitmap data for a given column of a given symbol.
// Handles reading data from FLASH
char fontBitmapReadColumn(char symbol, char column);

// for sanitizing input before use
int fontBitmapExists(char c);

extern const char bitmaps[] PROGMEM;

#endif