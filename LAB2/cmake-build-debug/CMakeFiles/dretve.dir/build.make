# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion-2019.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dretve.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dretve.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dretve.dir/flags.make

CMakeFiles/dretve.dir/dretve.cpp.o: CMakeFiles/dretve.dir/flags.make
CMakeFiles/dretve.dir/dretve.cpp.o: ../dretve.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dretve.dir/dretve.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dretve.dir/dretve.cpp.o -c /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2/dretve.cpp

CMakeFiles/dretve.dir/dretve.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dretve.dir/dretve.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2/dretve.cpp > CMakeFiles/dretve.dir/dretve.cpp.i

CMakeFiles/dretve.dir/dretve.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dretve.dir/dretve.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2/dretve.cpp -o CMakeFiles/dretve.dir/dretve.cpp.s

# Object files for target dretve
dretve_OBJECTS = \
"CMakeFiles/dretve.dir/dretve.cpp.o"

# External object files for target dretve
dretve_EXTERNAL_OBJECTS =

dretve: CMakeFiles/dretve.dir/dretve.cpp.o
dretve: CMakeFiles/dretve.dir/build.make
dretve: CMakeFiles/dretve.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dretve"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dretve.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dretve.dir/build: dretve

.PHONY : CMakeFiles/dretve.dir/build

CMakeFiles/dretve.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dretve.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dretve.dir/clean

CMakeFiles/dretve.dir/depend:
	cd /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2 /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2 /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2/cmake-build-debug /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2/cmake-build-debug /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB2/cmake-build-debug/CMakeFiles/dretve.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dretve.dir/depend

