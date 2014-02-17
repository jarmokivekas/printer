;The keyboard routines for the text editor in the i2c program



last_key:
.db	$00
#define no_key $00

wait_for_key:
	bcall(_scanKey)
	CP no_key
	JR Z, wait_for_key
	RET

get_char:
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

symbols:
	;start a
	RET 