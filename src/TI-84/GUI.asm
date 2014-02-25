#include "ti83plus.inc"

.org$9D93
.db t2ByteTok, tAsmCmp

Start:
	B_CALL(_runIndicOff)
	B_CALL(_ClrLCDFull)

	LD HL, $0000
	LD (CurRow), HL
	LD HL, text_data
	PUSH HL
Loop:
	CALL get_char
	CP $1e
	RET Z
	CP $1f
	JR Z, Loop
	CP $1d
	JR NZ, putcees

	LD D, $80		;set the arguments and call the send routine
	LD HL, text_data
	CALL send_data
	JR Loop
putcees:
	B_CALL(_putC)

	POP HL
	LD (HL), A
	INC HL
	PUSH HL

	JR Loop

	RET

text_data:
.db	$44, $41, $54, $41, $3A ;"DATA:"
.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00

.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00

.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00

.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00
.db	$00, $00, $00, $00, $00, $00, $00, $00



#include "./keyboard.asm"

#include "./i2c_transfer.asm"