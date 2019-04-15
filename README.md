
# Introduction

We are bringing you a colour-based glass recycling sorter which can separate, in real-time, green, amber and clear bottles!
This is a university project for the subject real-time embedded programming. Watch our short introduction to why and how we are building this project:

<p align="center">
  <a href="https://www.youtube.com/watch?v=iapjhaJnOS8" target="_blank">
  <img src="https://img.youtube.com/vi/iapjhaJnOS8/0.jpg" alt="A video summary of Glassify"> 
  </a>
</p>


## Motive

Glass is 100% recyclable and by doing so we can substantially reduce raw materials needed, the waste produced as well as water and air pollution.<sup>[1](https://www.glassrecycle.co.uk/Why-Recycle/Facts--Figures/)</sup> However, contamination is a major factor in the effectiveness of recycling.<sup>[2](https://wasterecycling.org/news/426888/NWRA-Celebrates-America-Recycles-Day.htm)</sup> This can be due to non-glass materials disposed alongside with the bottles, such as bottle caps, but also by mixing differently coloured glasses. Colours are achieved by adding impurities, such as sulfur, copper or iron to the glasses. Their purpose is to protect the contents from environmental effects. Even one colour misplaced in the wrong bin can deteriorate the quality of the recycled glass. <sup>[3](https://recyclenation.com/2014/09/recycling-glass-does-color-matter/)</sup> This project aims to achieve a more effective glass recycling to preserve our natural resources and protect our environment. 

## Our Solution

We are presenting here a device which can be installed to recycling points to assisst with the user-side recycling process. Once installed, a single input can be used for the glass recycling bin and the internal sorting would ensure that colour contamination doesn't occur. The device uses a Raspberry Pi microcontroller and is built using 3D printing which means that the overall production cost can be kept under £100. 

<p align="center">
  <a href="https://www.youtube.com/watch?v=UAzmWVJm4zI" target="_blank">
  <img src="https://img.youtube.com/vi/UAzmWVJm4zI/0.jpg" alt="A video summary of Glassify"> 
  </a>
</p>



# Have we got your fascination?

To see updates follow us on Facebook, YouTube and Instagram.

If you would like to recreate this project, head over to our [Wiki](https://github.com/poganyg/Glassify/wiki) page where you will find a detailed building guide including a list of all the components you will need for building it. In terms of software requirements, you will need to install:

* [openCV](https://opencv.org/releases.html)
* [Raspicam](http://www.uco.es/investiga/grupos/ava/node/40?fbclid=IwAR3oNeb0COuL_Odd_C1q-Dq5YQPJ6SrulXHsiW9hHNv8-BaiqOYJpjWOB74)
* [WiringPi](http://wiringpi.com/download-and-install/)
* [CMake](https://cmake.org/install/)
* [Git](https://git-scm.com/downloads) (Optional, makes cloning this repository easier.)

Do make sure to only have these installed once on your Raspberry Pi.

To build our software run the following code in your terminal:
```
git clone https://github.com/poganyg/Glassify.git
cd Glassify
mkdir build
cd build
cmake ..
make
```

The project is under the GNU General Public License v3.0.
