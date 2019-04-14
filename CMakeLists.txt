cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project (Glassify)

# Define Test Directories
# add_subdirectory (src)
# add_subdirectory (test)
# enable_testing()

#set(wiringPi_DIR "/home/pi/wiringPi/wiringPi")
#set(wiringPiDev_DIR "home/pi/wiringPi/devLib")
set(raspicam_DIR "/usr/local/lib/cmake")
include_directories(/home/pi/wiringPi/wiringPi)
include_directories(/home/pi/wiringPi/devLib)
link_directories(/home/pi/wiringPi/wiringPi)
link_directories(/home/pi/wiringPi/devLib)


find_package(Threads)
# find_package(WiringPi)
find_package(OpenCV REQUIRED)
find_package(raspicam REQUIRED)

include_directories(./include)

add_executable(Glassify ./include/ClassifierThread.cpp ./include/state.cpp ./include/Camera.cpp ./include/libServo.cpp ./include/Classifier.cpp ./include/MotorThread.cpp ./include/SwitchThread.cpp ./include/gpio-sysfs.cpp ./include/Display.cpp ./include/MenuThread.cpp ./include/Menu.cpp ./include/ActivePollThread.cpp Glassify.cpp)

target_link_libraries (Glassify ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (Glassify wiringPi wiringPiDev)
#target_link_libraries (Glassify ${WIRINGPI_LIBRARIES})
target_link_libraries (Glassify ${raspicam_LIBS})
target_link_libraries (Glassify ${OpenCV_LIBS})
