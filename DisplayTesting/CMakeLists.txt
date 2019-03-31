cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project (Display)

#Location libraries
set(WiringPi_DIR "/home/pi/wiringPi")
find_package(WiringPi REQUIRED)
#Include Headers
include_directories(${WIRINGPI_INCLUDE_DIRS})

add_executable(
	Display
	Display.cpp	
)

target_link_libraries(Display ${WIRINGPI_LIBRARIES})
target_link_libraries(Display wiringPiDev)
