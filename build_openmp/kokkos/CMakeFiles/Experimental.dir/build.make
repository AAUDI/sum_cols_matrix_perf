# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/aaudi/Bureau/kokkos_numscale_work/sum_cols_matrix_perf

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aaudi/Bureau/kokkos_numscale_work/sum_cols_matrix_perf/build_openmp

# Utility rule file for Experimental.

# Include the progress variables for this target.
include kokkos/CMakeFiles/Experimental.dir/progress.make

kokkos/CMakeFiles/Experimental:
	cd /home/aaudi/Bureau/kokkos_numscale_work/sum_cols_matrix_perf/build_openmp/kokkos && /usr/bin/ctest -D Experimental

Experimental: kokkos/CMakeFiles/Experimental
Experimental: kokkos/CMakeFiles/Experimental.dir/build.make

.PHONY : Experimental

# Rule to build all files generated by this target.
kokkos/CMakeFiles/Experimental.dir/build: Experimental

.PHONY : kokkos/CMakeFiles/Experimental.dir/build

kokkos/CMakeFiles/Experimental.dir/clean:
	cd /home/aaudi/Bureau/kokkos_numscale_work/sum_cols_matrix_perf/build_openmp/kokkos && $(CMAKE_COMMAND) -P CMakeFiles/Experimental.dir/cmake_clean.cmake
.PHONY : kokkos/CMakeFiles/Experimental.dir/clean

kokkos/CMakeFiles/Experimental.dir/depend:
	cd /home/aaudi/Bureau/kokkos_numscale_work/sum_cols_matrix_perf/build_openmp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aaudi/Bureau/kokkos_numscale_work/sum_cols_matrix_perf /home/aaudi/Bureau/kokkos_numscale_work/sum_cols_matrix_perf/kokkos /home/aaudi/Bureau/kokkos_numscale_work/sum_cols_matrix_perf/build_openmp /home/aaudi/Bureau/kokkos_numscale_work/sum_cols_matrix_perf/build_openmp/kokkos /home/aaudi/Bureau/kokkos_numscale_work/sum_cols_matrix_perf/build_openmp/kokkos/CMakeFiles/Experimental.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : kokkos/CMakeFiles/Experimental.dir/depend

