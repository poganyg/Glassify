# Define CMake Version
cmake_minimum_required(VERSION 2.8)

# Project Name
project (raspicam_test)

# Define Test Directories
# add_subdirectory (src)
add_subdirectory (test)
enable_testing()

set(raspicam_DIR "/usr/local/lib/cmake")
find_package(raspicam REQUIRED)
find_package(OpenCV REQUIRED)
add_executable (raspicam_test testingClass.cpp)
target_link_libraries (raspicam_test ${raspicam_LIBS})
target_link_libraries (raspicam_test ${OpenCV_LIBS})
