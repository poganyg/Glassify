cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

project(Glassify)

# Define Test Directories
# add_subdirectory (include)
add_subdirectory (test)
enable_testing()

set(raspicam_DIR "/usr/local/lib/cmake")
include_directories(/home/pi/wiringPi/wiringPi)
include_directories(/home/pi/wiringPi/devLib)
link_directories(/home/pi/wiringPi/wiringPi)
link_directories(/home/pi/wiringPi/devLib)
find_package(Threads)
find_package(OpenCV REQUIRED)
find_package(raspicam REQUIRED)

add_library(Glass SHARED
  include/ActivePollThread.cpp
  include/Camera.cpp
  include/Classifier.cpp
  include/ClassifierThread.cpp
  include/Display.cpp
  include/gpio-sysfs.cpp
  include/libServo.cpp
  include/Menu.cpp
  include/MenuThread.cpp
  include/MotorThread.cpp
  include/state.cpp
  include/SwitchThread.cpp)

target_link_libraries (Glass ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries (Glass wiringPi wiringPiDev)
target_link_libraries (Glass ${WIRINGPI_LIBRARIES})
target_link_libraries (Glass ${raspicam_LIBS})
target_link_libraries (Glass ${OpenCV_LIBS})

include_directories(include/)

add_executable(Glassify Glassify.cpp)
target_link_libraries(Glassify Glass)

add_library(Common SHARED
  include/ActivePollThread.cpp
  include/Classifier.cpp
  include/ClassifierThread.cpp
  include/Display.cpp
  include/gpio-sysfs.cpp
  include/libServo.cpp
  include/Menu.cpp
  include/MenuThread.cpp
  include/MotorThread.cpp
  include/state.cpp
  include/SwitchThread.cpp)

  target_link_libraries (Common ${CMAKE_THREAD_LIBS_INIT})
  target_link_libraries (Common wiringPi wiringPiDev)
  target_link_libraries (Common ${WIRINGPI_LIBRARIES})
  target_link_libraries (Common ${raspicam_LIBS})
  target_link_libraries (Common ${OpenCV_LIBS})
