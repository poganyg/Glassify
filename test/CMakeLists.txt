cmake_minimum_required(VERSION 3.0)
enable_testing()
include_directories(
../include

)

set(raspicam_DIR "/usr/local/lib/cmake")
find_package(raspicam REQUIRED)
find_package(OpenCV REQUIRED)


add_executable(camera_test CameraTest.cpp Camera.cpp)
target_link_libraries (camera_test ${raspicam_LIBS})
target_link_libraries (camera_test ${OpenCV_LIBS})
add_test(CameraTest camera_test)

add_executable(mat_convert MatConvert.cpp)
target_link_libraries (mat_convert ${raspicam_LIBS})
target_link_libraries (mat_convert ${OpenCV_LIBS})
add_test(MatConvert mat_convert)
