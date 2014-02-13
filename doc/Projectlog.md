Printer
=======

####11.2.2014
This project is currently lacking a name. We thought about "Monaco9 is seven pixels tall", but it turns out we want to use a font thats eight pixels tall, so we could go with "We need a font" as the current project name.

####12.2.2014
There are many thing that i see as intresting and having potential in this project. First of all i like the idea of developing some functional hardware, i know how to program and i know how to solder, but the things in between are a bit fuzzy for me at the moment and i'd like learn some more about that.

I see the result of this project being something autonomous. I hope that it will be a device that can be used without the assistance of a general-purpose computer. This is going to be a printer (kind of) and a printer should be running a program that can take (formatted) input and give output regardless of the source. The input will be given through I2C, the device will save it in RAM, and then it can be printed whenever you want. There should be no need to reprogram the Flash or EEPROM in order to print a new message. The only time reprogramming should be done is if there's an update to the software.

I2C in .WAV
-----------
####13.2.2014

I2C is a communicatoin protocol, not a filetype. But it can still be thought of as signals that can be recorded. I2C has two busses, so it can be recorded as stereo audio, one channel for the serial clock and one for the data. WAV is an audiofile format that enables us to save audio in a lossless manner. WAV is also a really simple filetype to write and it's supported by most platforms. These are the reasons why i chose to use WAV as the medium for saving and transporting data to the microcontroller in the electronic brush.

I need four stereo samples (8 bytes of 8-bit samples) to save and transfer a bit of data. This will make sure that the signals are well in sync and that all data is safetly transfered. I'll be using 8kHz 8-bit audio and it'll give me a transfer speed of 2000 bits per second which is good enough for the application. Since the signal has it's own clock the samplerate can be increased to get a faster transfer. A baud of 2000 bits/s should not be hard to recieve with any microcontroller.