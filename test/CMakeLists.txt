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

add_executable(mat_convert_test MatConvert.cpp)
target_link_libraries (mat_convert_test Glass)
add_test(MatConvert mat_convert_test)

add_executable(display_test DisplayTest.cpp)
target_link_libraries (display_test Glass)
add_test(DisplayTest display_test)

add_executable(servo_test ServoTest.cpp)
target_link_libraries (servo_test Glass)
add_test(ServoTest servo_test)

add_executable(state_test StateTest.cpp StateTestThread.cpp)
target_link_libraries (state_test Glass)
add_test(StateTest state_test)
