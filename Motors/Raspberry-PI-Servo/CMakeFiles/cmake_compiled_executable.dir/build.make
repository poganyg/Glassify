# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/Glassify/Motors/Raspberry-PI-Servo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Glassify/Motors/Raspberry-PI-Servo

# Include any dependencies generated for this target.
include CMakeFiles/cmake_compiled_executable.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cmake_compiled_executable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmake_compiled_executable.dir/flags.make

CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o: CMakeFiles/cmake_compiled_executable.dir/flags.make
CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o: libServo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Glassify/Motors/Raspberry-PI-Servo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o -c /home/pi/Glassify/Motors/Raspberry-PI-Servo/libServo.cpp

CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Glassify/Motors/Raspberry-PI-Servo/libServo.cpp > CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.i

CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Glassify/Motors/Raspberry-PI-Servo/libServo.cpp -o CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.s

CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o.requires:

.PHONY : CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o.requires

CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o.provides: CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o.requires
	$(MAKE) -f CMakeFiles/cmake_compiled_executable.dir/build.make CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o.provides.build
.PHONY : CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o.provides

CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o.provides.build: CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o


CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o: CMakeFiles/cmake_compiled_executable.dir/flags.make
CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o: libServoSample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Glassify/Motors/Raspberry-PI-Servo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o -c /home/pi/Glassify/Motors/Raspberry-PI-Servo/libServoSample.cpp

CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Glassify/Motors/Raspberry-PI-Servo/libServoSample.cpp > CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.i

CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Glassify/Motors/Raspberry-PI-Servo/libServoSample.cpp -o CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.s

CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o.requires:

.PHONY : CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o.requires

CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o.provides: CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o.requires
	$(MAKE) -f CMakeFiles/cmake_compiled_executable.dir/build.make CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o.provides.build
.PHONY : CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o.provides

CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o.provides.build: CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o


# Object files for target cmake_compiled_executable
cmake_compiled_executable_OBJECTS = \
"CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o" \
"CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o"

# External object files for target cmake_compiled_executable
cmake_compiled_executable_EXTERNAL_OBJECTS =

cmake_compiled_executable: CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o
cmake_compiled_executable: CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o
cmake_compiled_executable: CMakeFiles/cmake_compiled_executable.dir/build.make
cmake_compiled_executable: /usr/local/lib/libwiringPi.so
cmake_compiled_executable: CMakeFiles/cmake_compiled_executable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Glassify/Motors/Raspberry-PI-Servo/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cmake_compiled_executable"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cmake_compiled_executable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cmake_compiled_executable.dir/build: cmake_compiled_executable

.PHONY : CMakeFiles/cmake_compiled_executable.dir/build

CMakeFiles/cmake_compiled_executable.dir/requires: CMakeFiles/cmake_compiled_executable.dir/libServo.cpp.o.requires
CMakeFiles/cmake_compiled_executable.dir/requires: CMakeFiles/cmake_compiled_executable.dir/libServoSample.cpp.o.requires

.PHONY : CMakeFiles/cmake_compiled_executable.dir/requires

CMakeFiles/cmake_compiled_executable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cmake_compiled_executable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cmake_compiled_executable.dir/clean

CMakeFiles/cmake_compiled_executable.dir/depend:
	cd /home/pi/Glassify/Motors/Raspberry-PI-Servo && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Glassify/Motors/Raspberry-PI-Servo /home/pi/Glassify/Motors/Raspberry-PI-Servo /home/pi/Glassify/Motors/Raspberry-PI-Servo /home/pi/Glassify/Motors/Raspberry-PI-Servo /home/pi/Glassify/Motors/Raspberry-PI-Servo/CMakeFiles/cmake_compiled_executable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cmake_compiled_executable.dir/depend
