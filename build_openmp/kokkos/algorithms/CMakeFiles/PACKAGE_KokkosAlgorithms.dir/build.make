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

# Include any dependencies generated for this target.
include kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/depend.make

# Include the progress variables for this target.
include kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/progress.make

# Include the compile flags for this target's objects.
include kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/flags.make

kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.o: kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/flags.make
kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.o: kokkos/algorithms/dummy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aaudi/work/work_numscale_kokkos/build_openmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.o"
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/algorithms && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.o -c /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/algorithms/dummy.cpp

kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.i"
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/algorithms && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/algorithms/dummy.cpp > CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.i

kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.s"
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/algorithms && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/algorithms/dummy.cpp -o CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.s

# Object files for target PACKAGE_KokkosAlgorithms
PACKAGE_KokkosAlgorithms_OBJECTS = \
"CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.o"

# External object files for target PACKAGE_KokkosAlgorithms
PACKAGE_KokkosAlgorithms_EXTERNAL_OBJECTS =

kokkos/algorithms/libPACKAGE_KokkosAlgorithms.a: kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/dummy.cpp.o
kokkos/algorithms/libPACKAGE_KokkosAlgorithms.a: kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/build.make
kokkos/algorithms/libPACKAGE_KokkosAlgorithms.a: kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aaudi/work/work_numscale_kokkos/build_openmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libPACKAGE_KokkosAlgorithms.a"
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/algorithms && $(CMAKE_COMMAND) -P CMakeFiles/PACKAGE_KokkosAlgorithms.dir/cmake_clean_target.cmake
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/algorithms && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PACKAGE_KokkosAlgorithms.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/build: kokkos/algorithms/libPACKAGE_KokkosAlgorithms.a

.PHONY : kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/build

kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/clean:
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/algorithms && $(CMAKE_COMMAND) -P CMakeFiles/PACKAGE_KokkosAlgorithms.dir/cmake_clean.cmake
.PHONY : kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/clean

kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/depend:
	cd /home/aaudi/work/work_numscale_kokkos/build_openmp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aaudi/work/work_numscale_kokkos /home/aaudi/work/work_numscale_kokkos/kokkos/algorithms /home/aaudi/work/work_numscale_kokkos/build_openmp /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/algorithms /home/aaudi/work/work_numscale_kokkos/build_openmp/kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : kokkos/algorithms/CMakeFiles/PACKAGE_KokkosAlgorithms.dir/depend
