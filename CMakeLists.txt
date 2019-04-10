cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project (Glassify)

# Define Test Directories
# add_subdirectory (src)
# add_subdirectory (test)
# enable_testing()

set(WiringPi_DIR "/home/pi/wiringPi")
set(raspicam_DIR "/usr/local/lib/cmake")
include_directories(${WIRINGPI_INCLUDE_DIRS})

find_package(Threads)
find_package(WiringPi REQUIRED)
find_package(OpenCV REQUIRED)
find_package(raspicam REQUIRED)

include_directories(./include)

add_executable(Glassify Glassify.cpp ./include/MotorThread.cpp ./include/SwitchThread.cpp ./include/gpio-sysfs.cpp ./include/Camera.cpp)

target_link_libraries (Glassify ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (Glassify ${WIRINGPI_LIBRARIES})
target_link_libraries (Glassify ${raspicam_LIBS})
target_link_libraries (Glassify ${OpenCV_LIBS})
