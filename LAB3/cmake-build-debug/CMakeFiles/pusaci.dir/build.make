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
CMAKE_SOURCE_DIR = /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pusaci.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pusaci.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pusaci.dir/flags.make

CMakeFiles/pusaci.dir/pusaci.cpp.o: CMakeFiles/pusaci.dir/flags.make
CMakeFiles/pusaci.dir/pusaci.cpp.o: ../pusaci.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pusaci.dir/pusaci.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pusaci.dir/pusaci.cpp.o -c /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/pusaci.cpp

CMakeFiles/pusaci.dir/pusaci.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pusaci.dir/pusaci.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/pusaci.cpp > CMakeFiles/pusaci.dir/pusaci.cpp.i

CMakeFiles/pusaci.dir/pusaci.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pusaci.dir/pusaci.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/pusaci.cpp -o CMakeFiles/pusaci.dir/pusaci.cpp.s

# Object files for target pusaci
pusaci_OBJECTS = \
"CMakeFiles/pusaci.dir/pusaci.cpp.o"

# External object files for target pusaci
pusaci_EXTERNAL_OBJECTS =

pusaci: CMakeFiles/pusaci.dir/pusaci.cpp.o
pusaci: CMakeFiles/pusaci.dir/build.make
pusaci: CMakeFiles/pusaci.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pusaci"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pusaci.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pusaci.dir/build: pusaci

.PHONY : CMakeFiles/pusaci.dir/build

CMakeFiles/pusaci.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pusaci.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pusaci.dir/clean

CMakeFiles/pusaci.dir/depend:
	cd /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3 /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3 /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug/CMakeFiles/pusaci.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pusaci.dir/depend
