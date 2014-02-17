#include "ti83plus.inc"

.org$9D93
.db t2ByteTok, tAsmCmp

Start:
	B_CALL(_runIndicOff)
	B_CALL(_ClrLCDFull)

	LD HL, $0000
	LD (CurRow), HL
	LD A, $80
Loop:
	PUSH AF
	B_CALL(_putC)
	;B_CALL(_getKey)
	POP AF
	INC A
	cp $f2
	JR NZ, Loop
	B_CALL(_getKey)

	RET