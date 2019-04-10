cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project (TestingAll)

set(WiringPi_DIR "/home/pi/wiringPi")
set(raspicam_DIR "/usr/local/lib/cmake")
include_directories(${WIRINGPI_INCLUDE_DIRS})

find_package(Threads)
find_package(WiringPi REQUIRED)
find_package(OpenCV REQUIRED)
find_package(raspicam REQUIRED)

include_directories(./include)

add_executable(TestingAll TestingAll.cpp ./include/MotorThread.cpp ./include/SwitchThread.cpp ./include/gpio-sysfs.cpp)

target_link_libraries (TestingAll ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (TestingAll ${WIRINGPI_LIBRARIES})
target_link_libraries (TestingAll ${raspicam_LIBS})
target_link_libraries (TestingAll ${OpenCV_LIBS})
