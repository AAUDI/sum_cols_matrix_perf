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

# Utility rule file for ExperimentalUpdate.

# Include the progress variables for this target.
include kokkos/CMakeFiles/ExperimentalUpdate.dir/progress.make

kokkos/CMakeFiles/ExperimentalUpdate:
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos && /usr/bin/ctest -D ExperimentalUpdate

ExperimentalUpdate: kokkos/CMakeFiles/ExperimentalUpdate
ExperimentalUpdate: kokkos/CMakeFiles/ExperimentalUpdate.dir/build.make

.PHONY : ExperimentalUpdate

# Rule to build all files generated by this target.
kokkos/CMakeFiles/ExperimentalUpdate.dir/build: ExperimentalUpdate

.PHONY : kokkos/CMakeFiles/ExperimentalUpdate.dir/build

kokkos/CMakeFiles/ExperimentalUpdate.dir/clean:
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalUpdate.dir/cmake_clean.cmake
.PHONY : kokkos/CMakeFiles/ExperimentalUpdate.dir/clean

kokkos/CMakeFiles/ExperimentalUpdate.dir/depend:
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aaudi/work/work_numscale_kokkos /home/aaudi/work/work_numscale_kokkos/kokkos /home/aaudi/work/work_numscale_kokkos/build_openmp /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/CMakeFiles/ExperimentalUpdate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : kokkos/CMakeFiles/ExperimentalUpdate.dir/depend

