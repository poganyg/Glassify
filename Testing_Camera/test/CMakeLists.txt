cmake_minimum_required(VERSION 3.0)
enable_testing()
include_directories(
..
)

set(raspicam_DIR "/usr/local/lib/cmake")
find_package(raspicam REQUIRED)
find_package(OpenCV REQUIRED)
add_executable(test_functionality test.cpp)
target_link_libraries (test_functionality ${raspicam_LIBS})
target_link_libraries (test_functionality ${OpenCV_LIBS})
add_test(TestFunctionality test_functionality)
