;The keyboard routines for the text editor in the i2c program

last_key:
.db	$00
#define no_key $00

get_char:
	CALL get_key
	LD HL, ASCII_lookup
	LD C, A
	LD B, $00
	ADD HL, BC
	LD A, (HL)
	RET

get_key:
	CALL wait_for_key
	CP sk2nd
	JR Z, shifted
	CP skAlpha
	JR Z, alphaed
	CP skAdd
	JR Z, symbols
	RET

shifted:
	LD B, $38
	CALL wait_for_key
	ADD A, B
	RET

alphaed:
	LD B, $70
	CALL wait_for_key
	ADD A, B
	RET

wait_for_key:
	bcall(_GetCSC)
	CP no_key
	JR Z, wait_for_key
	RET

symbols:
	;start the symbol menu routine
	RET

ASCII_lookup:
.db	$1f
.db	$11	;Down
.db	$12	;Left
.db	$13	;Right
.db	$14	;Up
.db	$1f
.db	$1f
.db	$1f
.db	$1f
.db	$1d	;call send routine?
.db	$1f	;symbol (it'll call a function, not return a value)
.db	'w'
.db	'r'
.db	'm'
.db	'h'
.db	$08	;Backspace

.db	$1f
.db	$1f
.db	$1f
.db	'v'
.db	'q'
.db	'l'
.db	'g'
.db	$1f
.db	$1f
.db	$1f
.db	'z'
.db	'u'
.db	'p'
.db	'k'
.db	'f'
.db	'c'

.db	$1f
.db	$20	;space
.db	'y'
.db	't'
.db	'o'
.db	'j'
.db	'e'
.db	'b'
.db	$1f
.db	$1f
.db	'x'
.db	's'
.db	'n'
.db	'i'
.db	'd'
.db	'a'

.db	$1f	;calls the alpha routine
.db	$1f
.db	$1f
.db	$1f
.db	$1f
.db	$1f	;calls the shift routine
.db	$1f
.db	$1e

;shifted values (added 0x38)
.db	$1f
.db	$1f	
.db	$1f	
.db	$1f	
.db	$1f	
.db	$1f
.db	$1f
.db	$1f
.db	$1f
.db	$1f	
.db	$1f	
.db	'W'
.db	'R'
.db	'M'
.db	'H'
.db	$1f

.db	$1f
.db	$1f
.db	$1f
.db	'V'
.db	'Q'
.db	'L'
.db	'G'
.db	$1f
.db	$1f
.db	$1f
.db	'Z'
.db	'U'
.db	'P'
.db	'K'
.db	'F'
.db	'C'

.db	$1f
.db	$00	;Terminate string
.db	'Y'
.db	'T'
.db	'O'
.db	'J'
.db	'E'
.db	'B'
.db	$1f
.db	$1f
.db	'X'
.db	'S'
.db	'N'
.db	'I'
.db	'D'
.db	'A'

.db	$1f	;calls the alpha routine
.db	$1f
.db	$1f
.db	$1f
.db	$1f
.db	$1f	;calls the shift routine
.db	$1f
.db	$1f

;alpha values (added 0x70)
.db	$1f
.db	$1f	
.db	$1f	
.db	$1f	
.db	$1f	
.db	$1f
.db	$1f
.db	$1f
.db	$1f
.db	$1f	
.db	$1f
.db	$1f
.db	$1f
.db	$1f	
.db	$1f
.db	$1f

.db	$1f	
.db	$1f
.db	'3'	
.db	'6'	
.db	'9'	
.db	$1f
.db	$1f
.db	$1f
.db	$1f
.db	$1f
.db	'2'	
.db	'5'
.db	'8'
.db	$1f
.db	$1f	
.db	$1f
	
.db	$1f
.db	'0'
.db	'1'	
.db	'4'	
.db	'7'	
.db	$1f
.db	$1f
.db	$1f
.db	$1f
.db	$1f	
.db	$1f
.db	$1f
.db	$1f
.db	$1f	
.db	$1f
.db	$1f

.db	$1f
.db	$1f	
.db	$1f	
.db	$1f	
.db	$1f	
.db	$1f
.db	$1f
.db	$1f
