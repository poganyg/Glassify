# Define CMake Version
cmake_minimum_required(VERSION 2.8)

# Project Name
project (Classifier)

# Define Test Directories
# add_subdirectory (src)
add_subdirectory (test)
enable_testing()

set(raspicam_DIR "/usr/local/lib/cmake")
find_package(raspicam REQUIRED)
find_package(OpenCV REQUIRED)
add_executable (Classifier Provisional.cpp)
target_link_libraries (Classifier ${raspicam_LIBS})
target_link_libraries (Classifier ${OpenCV_LIBS})
