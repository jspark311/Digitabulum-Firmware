/* \mainpage Firmware Documentation

    .__       ,    .     .
    |  \* _ *-+- _.|_ . .|. .._ _
    |__/|(_]| | (_][_)(_||(_|[ | )
         ._|                      

# This fork is no longer used. It is being retained for historical reasons. Please see the [main repo](https://github.com/Manuvr/Digitabulum-Firmware) for current firmware.

Digitabulum is an inertial motion-capture glove designed to be modular and open.

----------------------
####What is in this repository:
**./3DModels**: Blender models. This includes models of the physical pieces that comprise a finished unit as well as their molds.

**./compiler**:  The gcc compiler and the libraries for the STM32F7.

**./doc**:  Documentation related to this project, which can be built by running...

    doxygen Doxyfile

**./lib**:  Libraries that were not written by Manuvr.

**./src**:  Original (unless otherwise specified) source code for Digitabulum.


----------------------
####Building the device firmware under linux
Because the compiler and all the dependencies are included in this repo, this ought to be as easy as...

    # Clone...
    git clone https://github.com/Manuvr/Digitabulum-Firmware.git
    cd Digitabulum-Firmware

    # Unpack the toolchain and download dependencies...
    ./unpackTools.sh
    ./downloadDeps.sh

    # Build...
    make

If that succeeded and your system has DFU support, you can then plug your glove into a USB port, press the bootloader button, and...

    make program

----------------------
####Building the emulator
There is a separate makefile for the linux emulator.

    make -f Makefile.emu DEBUG=1

----------------------
####Building the CPLD
Altera's software is required to build the CPLD. It is presently outside the scope of this document.

----------------------
####License
Original code is Apache 2.0.

Code adapted from others' work inherits their license terms, which were preserved in the commentary where it applies.

----------------------
####Cred:
The ASCII art in this file was generated by [this most-excellent tool](http://patorjk.com/software/taag).

The USB virtual COM port code was written by Tilen Majerle:
http://stm32f4-discovery.com/2014/07/library-19-use-internal-rtc-on-stm32f4xx-devices
