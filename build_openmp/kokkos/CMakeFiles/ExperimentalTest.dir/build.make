# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /home/aaudi/work/work_numscale_kokkos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aaudi/work/work_numscale_kokkos/build_openmp

# Utility rule file for ExperimentalTest.

# Include the progress variables for this target.
include kokkos/CMakeFiles/ExperimentalTest.dir/progress.make

kokkos/CMakeFiles/ExperimentalTest:
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos && /usr/bin/ctest -D ExperimentalTest

ExperimentalTest: kokkos/CMakeFiles/ExperimentalTest
ExperimentalTest: kokkos/CMakeFiles/ExperimentalTest.dir/build.make

.PHONY : ExperimentalTest

# Rule to build all files generated by this target.
kokkos/CMakeFiles/ExperimentalTest.dir/build: ExperimentalTest

.PHONY : kokkos/CMakeFiles/ExperimentalTest.dir/build

kokkos/CMakeFiles/ExperimentalTest.dir/clean:
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalTest.dir/cmake_clean.cmake
.PHONY : kokkos/CMakeFiles/ExperimentalTest.dir/clean

kokkos/CMakeFiles/ExperimentalTest.dir/depend:
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aaudi/work/work_numscale_kokkos /home/aaudi/work/work_numscale_kokkos/kokkos /home/aaudi/work/work_numscale_kokkos/build_openmp /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/CMakeFiles/ExperimentalTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : kokkos/CMakeFiles/ExperimentalTest.dir/depend

