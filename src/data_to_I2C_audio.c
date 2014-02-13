/*
12.2.2014
Juha Kivekäs

This is a program that will make data into I2C signals encoded as .wav files.
The right channel is the serial data and and the left channel is the serial clock.
The baud of this transfer will be 2000 bits/s.
*/



#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t dataLen;
uint32_t NumSamples;
uint32_t SubChunck2Size;
uint32_t ChunckSize;


void write_audio(char* filename, uint8_t* header, uint8_t* audio_data){
    FILE* output = fopen(filename, "w");

    fwrite(header, 0x2c, 1, output);
    fwrite(audio_data, SubChunck2Size, 1, output);
    fclose(output);
}

uint8_t* read_data(char* filename){
    FILE* input = fopen(filename, "r");

    fseek(input, 0L, SEEK_END);
    dataLen = ftell(input);
    fseek(input, 0L, SEEK_SET);

    uint8_t* data = malloc(dataLen);
    fread(data, dataLen, 1, input);
    fclose(input);
    return data;
}
int main(int argc, char* argv[]){
    if ( argc != 3 )
        printf( "usage: %s input_filename output_filename\n", argv[0]);

    uint8_t* input = read_data(argv[1]);

    //an I2C block per bit (one I2C block has four samples)
    NumSamples = dataLen * 8 * 4;
    SubChunck2Size = NumSamples * 2;
    ChunckSize = SubChunck2Size + 36;
    //stero sound 
    uint8_t* audio = malloc(SubChunck2Size);

    uint8_t WAVE_header[0x2c] = {
        0x52, 0x49, 0x46, 0x46,     //"RIFF"
        ((uint8_t*)&ChunckSize)[0], ((uint8_t*)&ChunckSize)[1], ((uint8_t*)&ChunckSize)[2], ((uint8_t*)&ChunckSize)[3],     //36 + SubChunck2size
        0x57, 0x41, 0x56, 0x45,     //"WAVE"

        0x66, 0x6d, 0x74, 0x20,     //"fmt "
        0x10, 0x00, 0x00, 0x00,     //16 for PCM
        0x01, 0x00, 
        0x02, 0x00, 
        0x40, 0x1F, 0x00, 0x00,     //8000 samples per second
        0x80, 0x3e, 0x00, 0x00,     //8000 * 2 * 1
        0x02, 0x00,                 //2 byte blocks
        0x08, 0x00,                 //8 bits per sample

        0x64, 0x61, 0x74, 0x61,     //"data"
        ((uint8_t*)&SubChunck2Size)[0], ((uint8_t*)&SubChunck2Size)[1], ((uint8_t*)&SubChunck2Size)[2], ((uint8_t*)&SubChunck2Size)[3]      //SubChunck2size = NumSamples * 2 * 1
    };

    uint8_t* currByte = input;
    uint8_t* currAudio = audio;
    uint8_t dat;
    int i, j;
    for(i=0; i<dataLen; i++){
        for(j=0; j<8; j++){
            dat = ((*currByte) & 1) ? 0xff:0x00;
            currAudio[0] = dat;      //SDA
            currAudio[1] = 0x00;     //SCL
            currAudio[2] = dat;
            currAudio[3] = 0xff;
            currAudio[4] = dat;
            currAudio[5] = 0xff;
            currAudio[6] = dat;
            currAudio[7] = 0x00;
            currAudio += 8;
            *currByte >>= 1;
        }
        currByte++;
    }

    write_audio(argv[2], WAVE_header, audio);
    return 0;
}



