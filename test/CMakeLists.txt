cmake_minimum_required(VERSION 3.0)
enable_testing()
include_directories(
../include
)

add_executable(camera_test CameraTest.cpp)
target_link_libraries (camera_test Glass)
add_test(CameraTest camera_test)

add_executable(classifier_test ClassifierTest.cpp CameraTestRedefinitions.cpp)
target_link_libraries (classifier_test Common)
add_test(ClassifierTest classifier_test)

add_executable(mat_convert MatConvert.cpp)
target_link_libraries (mat_convert Glass)
add_test(MatConvert mat_convert)

add_executable(mat_convert MatConvert.cpp)
target_link_libraries (mat_convert Glass)
add_test(MatConvert mat_convert)
