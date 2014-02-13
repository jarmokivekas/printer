#C compiler name, i use gcc
CC=gcc

#flags for C compiler
#-c, C sourcefile
#-Wall, show all warnings

OBJFLAGS = -c -Wall
CFLAGS = -Wall
LNKLAGS = -o -Wall

#------- paths to make the makefile a bit prettier, readable and more compact

data_to_I2C_audio.c = src/data_to_I2C_audio.c

#------- dependencies

i2c_to_wav: src/data_to_I2C_audio.c
	$(CC) $(CFLAGS) src/data_to_I2C_audio.c -o ./bin/i2c_to_audio

data_to_I2C_audio.c:

clean:
	rm -rf ./*.o */a.out