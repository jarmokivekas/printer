#!/bin/bash
# Usage: 
# 1. Create an 8-pixel high (arbitrary width) bitmap and rotate it
# 90 degrees clockwise.
# 2. In gimp open Image > Mode > Indexed, and choose on 1 bit palette.
# 3. File > Export bitmap from gimp as "C source code header"
# 4. Supply the exported file as the first argument to this script.
# The output is compatible with the bitmaps[] format in src/ATmega/font.c

# NOTE: For fonts, pipe the output through:
# parseGimpBitmap.bash file.h |sed -n '0~6!p'
# to remove every sixth line (6,12,18, counting the first one as #1).
# This way the spaces between characters are not stored.


cat  $1 \
# prepend 0b.
|sed 's/\t\([01]\)/0b\1/' \
# delete empty lines.
|sed '/^$/d' \
# remove commas between ones and zeros.
|sed 's/,\([10]\)/\1/g' \
# remove lines not starting with a 0 (0b...)
|sed '/^[^0]/d'