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
include CMakeFiles/partibrejker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/partibrejker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/partibrejker.dir/flags.make

CMakeFiles/partibrejker.dir/partibrejker.cpp.o: CMakeFiles/partibrejker.dir/flags.make
CMakeFiles/partibrejker.dir/partibrejker.cpp.o: ../partibrejker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/partibrejker.dir/partibrejker.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/partibrejker.dir/partibrejker.cpp.o -c /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/partibrejker.cpp

CMakeFiles/partibrejker.dir/partibrejker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/partibrejker.dir/partibrejker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/partibrejker.cpp > CMakeFiles/partibrejker.dir/partibrejker.cpp.i

CMakeFiles/partibrejker.dir/partibrejker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/partibrejker.dir/partibrejker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/partibrejker.cpp -o CMakeFiles/partibrejker.dir/partibrejker.cpp.s

# Object files for target partibrejker
partibrejker_OBJECTS = \
"CMakeFiles/partibrejker.dir/partibrejker.cpp.o"

# External object files for target partibrejker
partibrejker_EXTERNAL_OBJECTS =

partibrejker: CMakeFiles/partibrejker.dir/partibrejker.cpp.o
partibrejker: CMakeFiles/partibrejker.dir/build.make
partibrejker: CMakeFiles/partibrejker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable partibrejker"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/partibrejker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/partibrejker.dir/build: partibrejker

.PHONY : CMakeFiles/partibrejker.dir/build

CMakeFiles/partibrejker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/partibrejker.dir/cmake_clean.cmake
.PHONY : CMakeFiles/partibrejker.dir/clean

CMakeFiles/partibrejker.dir/depend:
	cd /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3 /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3 /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug /home/iva/Desktop/FER/6.semestar/OS/Labosi/LAB3/cmake-build-debug/CMakeFiles/partibrejker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/partibrejker.dir/depend
