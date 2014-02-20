send_data:
	LD D, $80
	LD HL, data_address
next_byte:
	POP HL
	LD A,(HL)
	INC HL
	PUSH HL
	LD C, A
	LD B, 8
next_bit:
	LD A, C
	AND $01		;read one bit
	OUT (0), A	;set the data
	CALL wait_transmit
	XOR $02		;set clock to high
	OUT (0), A	;send data
	CALL wait_transmit
	CALL wait_transmit
	XOR $02		;set clock to low
	OUT (0), A
	CALL wait_transmit
	SRL C		;next bit
	DJNZ next_bit

	DEC D
	JP NZ, next_byte

wait_transmit:
	LD D, 00
	DEC D
	JR NZ, wait_transmit