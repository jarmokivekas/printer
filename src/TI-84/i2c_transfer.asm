;destroys all registers
;D = bytes to transfer
;HL = transferable data adress

send_data:
	PUSH HL
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
	SRL C		;shift next bit to position 0

	OUT (0), A	;set the data
	CALL wait_transmit

	XOR $02		;set clock to high
	OUT (0), A	;send data
	CALL wait_transmit
	CALL wait_transmit

	XOR $02		;set clock to low
	OUT (0), A
	CALL wait_transmit

	DJNZ next_bit	;decrement the bits left in the current byte

	DEC D		;decrement bytes left to transfer
	JP NZ, next_byte

	LD A, $00
	OUT (0), A	;set the IO port data to 0
	POP HL		;empty the stack
	RET

wait_transmit:
	LD E, 00
wait_loop:
	DEC E
	JR NZ, wait_loop
	RET