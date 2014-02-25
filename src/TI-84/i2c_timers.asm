next_byte_adress:
.dw	$0000
bytes_left:
.db	$00
bits_left:
.db	$00
phase:
.db	$00

init_transmission:
	LD (next_byte_adress), HL
	LD (bytes_left), D
	LD A, 0
	LD (bits_left), A
	RET

terminate_transmission:
next_byte:
	LD HL, (next_byte_address)
	LD A, (HL)
	LD C, A
	INC HL

	LD A, (bytes_left)
	DEC A
	LD (bytes_left), A

	JR Z, terminate_transmission

	LD A, 8
next_bit:
	DEC A
	LD (bits_left), A
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
	PUSH BC
	PUSH AF
	LD BC, $1000
wait_loop:
	DEC BC
	LD A, B
	XOR C
	JR NZ, wait_loop

	POP AF
	POP BC
	RET