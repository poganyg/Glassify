![Glassify Logo](https://github.com/poganyg/Glassify/blob/master/CoverPhoto.png "Glassify Logo")

# Introduction

We are bringing you a colour-based glass recycling sorter which can separate, in real-time, green, amber and clear bottles.
This is a university project for the subject real-time embedded programming.

[![A video summary of Glassify](https://img.youtube.com/vi/iapjhaJnOS8/0.jpg)](https://www.youtube.com/watch?v=iapjhaJnOS8)

## Motive

Glass is 100% recyclable and by doing so we can substantially reduce raw materials needed, the waste produced as well as water and air pollution.<sup>[1](https://www.glassrecycle.co.uk/Why-Recycle/Facts--Figures/)</sup> However, contamination is a major factor in the effectiveness of recycling.<sup>[2](https://wasterecycling.org/news/426888/NWRA-Celebrates-America-Recycles-Day.htm)</sup> This can be due to non-glass materials disposed alongside with the bottles, such as bottle caps, but also by mixing differently coloured glasses. Colours are achieved by adding impurities, such as sulfur, copper or iron to the glasses. Their purpose is to protect the contents from environmental effects. Even one colour misplaced in the wrong bin can deteriorate the quality of the recycled glass. <sup>[3](https://recyclenation.com/2014/09/recycling-glass-does-color-matter/)</sup> This project aims to achieve a more effective glass recycling to preserve our natural resources and protect our environment. 

## Our Solution

We are presenting here a device which can be installed to recycling points to assisst with the user-side recycling process. Once installed, a single input can be used for the glass recycling bin and the internal sorting would ensure that colour contamination doesn't occur. The device uses a Raspberry Pi microcontroller and is built using 3D printing which means that the overall production cost can be kept under £100. 

embed 3d model rendering

# Building the Project

# Software Pakages Required
This project makes use of several widely used programs. The links to these can be found below.

[openCV](https://opencv.org/releases.html)

[Raspicam](http://www.uco.es/investiga/grupos/ava/node/40?fbclid=IwAR3oNeb0COuL_Odd_C1q-Dq5YQPJ6SrulXHsiW9hHNv8-BaiqOYJpjWOB74)

[WiringPi](http://wiringpi.com/download-and-install/) (Check if this is already installed before attempting instalation)

All other files are included in this github, these include modified versions of Bernd Porr's gpio-sysfs and CppTimer libraries and Omar Aflak's libServo library.
