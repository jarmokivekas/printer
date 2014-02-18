#include "ti83plus.inc"

.org$9D93
.db t2ByteTok, tAsmCmp

Start:
	B_CALL(_runIndicOff)
	B_CALL(_ClrLCDFull)

	LD HL, $0000
	LD (CurRow), HL
Loop:
	CALL get_char
	CP $1f
	JR Z, Loop
	B_CALL(_putC)
	JR Loop

	RET

#include "./keyboard.asm"