cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(libServo)

# Locate libraries and headers
find_package(WiringPi REQUIRED)
# Include headers
include_directories(${WIRINGPI_INCLUDE_DIRS}) 

add_executable(
        cmake_compiled_executable
        libServo.cpp
	libServoSample.cpp
)

target_link_libraries(cmake_compiled_executable ${WIRINGPI_LIBRARIES})



