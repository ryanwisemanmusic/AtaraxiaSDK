# SDL3_ARM_Mac_Build
This is a build that allows SDL3 to be used on ARM Macs if it was installed via homebrew.

Due to the change of usr/local on x86 Mac chips to opt/homebrew, header files cannot be natively included 
into VSCode, they must be located via .json and Makefile. Since you cannot sideload external libraries 
natively on ARM Macs, this project has the fundamentals for any Mac to run SDL2 in VSCode.

If you wish to fork this project for whatever reason, make sure if you are using SDL3, you update your 
Makefile to the correct version you need to reference
 
