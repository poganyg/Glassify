cmake_minimum_required(VERSION 3.0)
enable_testing()
include_directories(
../include
)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(camera_test CameraTest.cpp)
target_link_libraries (camera_test Glass)
add_test(NAME CameraTest COMMAND camera_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(CameraTest PROPERTIES TIMEOUT 3)

add_executable(classifier_test ClassifierTest.cpp CameraTestRedefinitions.cpp ButtonsTestRedefinitions.cpp)
target_link_libraries (classifier_test Common)
add_test(NAME ClassifierTest COMMAND classifier_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(ClassifierTest PROPERTIES TIMEOUT 15)

add_executable(display_test DisplayTest.cpp)
target_link_libraries (display_test Glass)
add_test(NAME DisplayTest COMMAND display_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../test)
set_tests_properties(DisplayTest PROPERTIES TIMEOUT 3)

add_executable(servo_test ServoTest.cpp)
target_link_libraries (servo_test Glass)
add_test(NAME ServoTest COMMAND servo_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../test)
set_tests_properties(ServoTest PROPERTIES TIMEOUT 3)

add_executable(state_test StateTest.cpp StateTestThread.cpp)
target_link_libraries (state_test Glass)
add_test(NAME StateTest COMMAND state_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../test)
set_tests_properties(StateTest PROPERTIES TIMEOUT 3)
