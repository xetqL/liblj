# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/xetql/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/xetql/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xetql/Dropbox/projects/cpp/nbody/liblj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xetql/Dropbox/projects/cpp/nbody/liblj/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/liblj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/liblj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/liblj.dir/flags.make

CMakeFiles/liblj.dir/common.cpp.o: CMakeFiles/liblj.dir/flags.make
CMakeFiles/liblj.dir/common.cpp.o: ../common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xetql/Dropbox/projects/cpp/nbody/liblj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/liblj.dir/common.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/liblj.dir/common.cpp.o -c /home/xetql/Dropbox/projects/cpp/nbody/liblj/common.cpp

CMakeFiles/liblj.dir/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/liblj.dir/common.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xetql/Dropbox/projects/cpp/nbody/liblj/common.cpp > CMakeFiles/liblj.dir/common.cpp.i

CMakeFiles/liblj.dir/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/liblj.dir/common.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xetql/Dropbox/projects/cpp/nbody/liblj/common.cpp -o CMakeFiles/liblj.dir/common.cpp.s

CMakeFiles/liblj.dir/common.cpp.o.requires:

.PHONY : CMakeFiles/liblj.dir/common.cpp.o.requires

CMakeFiles/liblj.dir/common.cpp.o.provides: CMakeFiles/liblj.dir/common.cpp.o.requires
	$(MAKE) -f CMakeFiles/liblj.dir/build.make CMakeFiles/liblj.dir/common.cpp.o.provides.build
.PHONY : CMakeFiles/liblj.dir/common.cpp.o.provides

CMakeFiles/liblj.dir/common.cpp.o.provides.build: CMakeFiles/liblj.dir/common.cpp.o


CMakeFiles/liblj.dir/linkedlist.cpp.o: CMakeFiles/liblj.dir/flags.make
CMakeFiles/liblj.dir/linkedlist.cpp.o: ../linkedlist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xetql/Dropbox/projects/cpp/nbody/liblj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/liblj.dir/linkedlist.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/liblj.dir/linkedlist.cpp.o -c /home/xetql/Dropbox/projects/cpp/nbody/liblj/linkedlist.cpp

CMakeFiles/liblj.dir/linkedlist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/liblj.dir/linkedlist.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xetql/Dropbox/projects/cpp/nbody/liblj/linkedlist.cpp > CMakeFiles/liblj.dir/linkedlist.cpp.i

CMakeFiles/liblj.dir/linkedlist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/liblj.dir/linkedlist.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xetql/Dropbox/projects/cpp/nbody/liblj/linkedlist.cpp -o CMakeFiles/liblj.dir/linkedlist.cpp.s

CMakeFiles/liblj.dir/linkedlist.cpp.o.requires:

.PHONY : CMakeFiles/liblj.dir/linkedlist.cpp.o.requires

CMakeFiles/liblj.dir/linkedlist.cpp.o.provides: CMakeFiles/liblj.dir/linkedlist.cpp.o.requires
	$(MAKE) -f CMakeFiles/liblj.dir/build.make CMakeFiles/liblj.dir/linkedlist.cpp.o.provides.build
.PHONY : CMakeFiles/liblj.dir/linkedlist.cpp.o.provides

CMakeFiles/liblj.dir/linkedlist.cpp.o.provides.build: CMakeFiles/liblj.dir/linkedlist.cpp.o


CMakeFiles/liblj.dir/nbody_bin_io.cpp.o: CMakeFiles/liblj.dir/flags.make
CMakeFiles/liblj.dir/nbody_bin_io.cpp.o: ../nbody_bin_io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xetql/Dropbox/projects/cpp/nbody/liblj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/liblj.dir/nbody_bin_io.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/liblj.dir/nbody_bin_io.cpp.o -c /home/xetql/Dropbox/projects/cpp/nbody/liblj/nbody_bin_io.cpp

CMakeFiles/liblj.dir/nbody_bin_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/liblj.dir/nbody_bin_io.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xetql/Dropbox/projects/cpp/nbody/liblj/nbody_bin_io.cpp > CMakeFiles/liblj.dir/nbody_bin_io.cpp.i

CMakeFiles/liblj.dir/nbody_bin_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/liblj.dir/nbody_bin_io.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xetql/Dropbox/projects/cpp/nbody/liblj/nbody_bin_io.cpp -o CMakeFiles/liblj.dir/nbody_bin_io.cpp.s

CMakeFiles/liblj.dir/nbody_bin_io.cpp.o.requires:

.PHONY : CMakeFiles/liblj.dir/nbody_bin_io.cpp.o.requires

CMakeFiles/liblj.dir/nbody_bin_io.cpp.o.provides: CMakeFiles/liblj.dir/nbody_bin_io.cpp.o.requires
	$(MAKE) -f CMakeFiles/liblj.dir/build.make CMakeFiles/liblj.dir/nbody_bin_io.cpp.o.provides.build
.PHONY : CMakeFiles/liblj.dir/nbody_bin_io.cpp.o.provides

CMakeFiles/liblj.dir/nbody_bin_io.cpp.o.provides.build: CMakeFiles/liblj.dir/nbody_bin_io.cpp.o


CMakeFiles/liblj.dir/nbody_txt_io.cpp.o: CMakeFiles/liblj.dir/flags.make
CMakeFiles/liblj.dir/nbody_txt_io.cpp.o: ../nbody_txt_io.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xetql/Dropbox/projects/cpp/nbody/liblj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/liblj.dir/nbody_txt_io.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/liblj.dir/nbody_txt_io.cpp.o -c /home/xetql/Dropbox/projects/cpp/nbody/liblj/nbody_txt_io.cpp

CMakeFiles/liblj.dir/nbody_txt_io.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/liblj.dir/nbody_txt_io.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xetql/Dropbox/projects/cpp/nbody/liblj/nbody_txt_io.cpp > CMakeFiles/liblj.dir/nbody_txt_io.cpp.i

CMakeFiles/liblj.dir/nbody_txt_io.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/liblj.dir/nbody_txt_io.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xetql/Dropbox/projects/cpp/nbody/liblj/nbody_txt_io.cpp -o CMakeFiles/liblj.dir/nbody_txt_io.cpp.s

CMakeFiles/liblj.dir/nbody_txt_io.cpp.o.requires:

.PHONY : CMakeFiles/liblj.dir/nbody_txt_io.cpp.o.requires

CMakeFiles/liblj.dir/nbody_txt_io.cpp.o.provides: CMakeFiles/liblj.dir/nbody_txt_io.cpp.o.requires
	$(MAKE) -f CMakeFiles/liblj.dir/build.make CMakeFiles/liblj.dir/nbody_txt_io.cpp.o.provides.build
.PHONY : CMakeFiles/liblj.dir/nbody_txt_io.cpp.o.provides

CMakeFiles/liblj.dir/nbody_txt_io.cpp.o.provides.build: CMakeFiles/liblj.dir/nbody_txt_io.cpp.o


CMakeFiles/liblj.dir/params.cpp.o: CMakeFiles/liblj.dir/flags.make
CMakeFiles/liblj.dir/params.cpp.o: ../params.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xetql/Dropbox/projects/cpp/nbody/liblj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/liblj.dir/params.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/liblj.dir/params.cpp.o -c /home/xetql/Dropbox/projects/cpp/nbody/liblj/params.cpp

CMakeFiles/liblj.dir/params.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/liblj.dir/params.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xetql/Dropbox/projects/cpp/nbody/liblj/params.cpp > CMakeFiles/liblj.dir/params.cpp.i

CMakeFiles/liblj.dir/params.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/liblj.dir/params.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xetql/Dropbox/projects/cpp/nbody/liblj/params.cpp -o CMakeFiles/liblj.dir/params.cpp.s

CMakeFiles/liblj.dir/params.cpp.o.requires:

.PHONY : CMakeFiles/liblj.dir/params.cpp.o.requires

CMakeFiles/liblj.dir/params.cpp.o.provides: CMakeFiles/liblj.dir/params.cpp.o.requires
	$(MAKE) -f CMakeFiles/liblj.dir/build.make CMakeFiles/liblj.dir/params.cpp.o.provides.build
.PHONY : CMakeFiles/liblj.dir/params.cpp.o.provides

CMakeFiles/liblj.dir/params.cpp.o.provides.build: CMakeFiles/liblj.dir/params.cpp.o


# Object files for target liblj
liblj_OBJECTS = \
"CMakeFiles/liblj.dir/common.cpp.o" \
"CMakeFiles/liblj.dir/linkedlist.cpp.o" \
"CMakeFiles/liblj.dir/nbody_bin_io.cpp.o" \
"CMakeFiles/liblj.dir/nbody_txt_io.cpp.o" \
"CMakeFiles/liblj.dir/params.cpp.o"

# External object files for target liblj
liblj_EXTERNAL_OBJECTS =

liblj: CMakeFiles/liblj.dir/common.cpp.o
liblj: CMakeFiles/liblj.dir/linkedlist.cpp.o
liblj: CMakeFiles/liblj.dir/nbody_bin_io.cpp.o
liblj: CMakeFiles/liblj.dir/nbody_txt_io.cpp.o
liblj: CMakeFiles/liblj.dir/params.cpp.o
liblj: CMakeFiles/liblj.dir/build.make
liblj: CMakeFiles/liblj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xetql/Dropbox/projects/cpp/nbody/liblj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable liblj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/liblj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/liblj.dir/build: liblj

.PHONY : CMakeFiles/liblj.dir/build

CMakeFiles/liblj.dir/requires: CMakeFiles/liblj.dir/common.cpp.o.requires
CMakeFiles/liblj.dir/requires: CMakeFiles/liblj.dir/linkedlist.cpp.o.requires
CMakeFiles/liblj.dir/requires: CMakeFiles/liblj.dir/nbody_bin_io.cpp.o.requires
CMakeFiles/liblj.dir/requires: CMakeFiles/liblj.dir/nbody_txt_io.cpp.o.requires
CMakeFiles/liblj.dir/requires: CMakeFiles/liblj.dir/params.cpp.o.requires

.PHONY : CMakeFiles/liblj.dir/requires

CMakeFiles/liblj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/liblj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/liblj.dir/clean

CMakeFiles/liblj.dir/depend:
	cd /home/xetql/Dropbox/projects/cpp/nbody/liblj/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xetql/Dropbox/projects/cpp/nbody/liblj /home/xetql/Dropbox/projects/cpp/nbody/liblj /home/xetql/Dropbox/projects/cpp/nbody/liblj/cmake-build-debug /home/xetql/Dropbox/projects/cpp/nbody/liblj/cmake-build-debug /home/xetql/Dropbox/projects/cpp/nbody/liblj/cmake-build-debug/CMakeFiles/liblj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/liblj.dir/depend
