# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_BINARY_DIR = /home/xetql/Dropbox/projects/cpp/nbody/liblj

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/home/xetql/clion-2017.3/bin/cmake/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/home/xetql/clion-2017.3/bin/cmake/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/home/xetql/clion-2017.3/bin/cmake/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/home/xetql/clion-2017.3/bin/cmake/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/home/xetql/clion-2017.3/bin/cmake/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/home/xetql/clion-2017.3/bin/cmake/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/home/xetql/clion-2017.3/bin/cmake/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/home/xetql/clion-2017.3/bin/cmake/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/xetql/Dropbox/projects/cpp/nbody/liblj/CMakeFiles /home/xetql/Dropbox/projects/cpp/nbody/liblj/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/xetql/Dropbox/projects/cpp/nbody/liblj/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named lj

# Build rule for target.
lj: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 lj
.PHONY : lj

# fast build rule for target.
lj/fast:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/build
.PHONY : lj/fast

src/common.o: src/common.cpp.o

.PHONY : src/common.o

# target to build an object file
src/common.cpp.o:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/common.cpp.o
.PHONY : src/common.cpp.o

src/common.i: src/common.cpp.i

.PHONY : src/common.i

# target to preprocess a source file
src/common.cpp.i:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/common.cpp.i
.PHONY : src/common.cpp.i

src/common.s: src/common.cpp.s

.PHONY : src/common.s

# target to generate assembly for a file
src/common.cpp.s:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/common.cpp.s
.PHONY : src/common.cpp.s

src/linkedlist.o: src/linkedlist.cpp.o

.PHONY : src/linkedlist.o

# target to build an object file
src/linkedlist.cpp.o:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/linkedlist.cpp.o
.PHONY : src/linkedlist.cpp.o

src/linkedlist.i: src/linkedlist.cpp.i

.PHONY : src/linkedlist.i

# target to preprocess a source file
src/linkedlist.cpp.i:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/linkedlist.cpp.i
.PHONY : src/linkedlist.cpp.i

src/linkedlist.s: src/linkedlist.cpp.s

.PHONY : src/linkedlist.s

# target to generate assembly for a file
src/linkedlist.cpp.s:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/linkedlist.cpp.s
.PHONY : src/linkedlist.cpp.s

src/nbody_bin_io.o: src/nbody_bin_io.cpp.o

.PHONY : src/nbody_bin_io.o

# target to build an object file
src/nbody_bin_io.cpp.o:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/nbody_bin_io.cpp.o
.PHONY : src/nbody_bin_io.cpp.o

src/nbody_bin_io.i: src/nbody_bin_io.cpp.i

.PHONY : src/nbody_bin_io.i

# target to preprocess a source file
src/nbody_bin_io.cpp.i:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/nbody_bin_io.cpp.i
.PHONY : src/nbody_bin_io.cpp.i

src/nbody_bin_io.s: src/nbody_bin_io.cpp.s

.PHONY : src/nbody_bin_io.s

# target to generate assembly for a file
src/nbody_bin_io.cpp.s:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/nbody_bin_io.cpp.s
.PHONY : src/nbody_bin_io.cpp.s

src/nbody_txt_io.o: src/nbody_txt_io.cpp.o

.PHONY : src/nbody_txt_io.o

# target to build an object file
src/nbody_txt_io.cpp.o:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/nbody_txt_io.cpp.o
.PHONY : src/nbody_txt_io.cpp.o

src/nbody_txt_io.i: src/nbody_txt_io.cpp.i

.PHONY : src/nbody_txt_io.i

# target to preprocess a source file
src/nbody_txt_io.cpp.i:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/nbody_txt_io.cpp.i
.PHONY : src/nbody_txt_io.cpp.i

src/nbody_txt_io.s: src/nbody_txt_io.cpp.s

.PHONY : src/nbody_txt_io.s

# target to generate assembly for a file
src/nbody_txt_io.cpp.s:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/nbody_txt_io.cpp.s
.PHONY : src/nbody_txt_io.cpp.s

src/params.o: src/params.cpp.o

.PHONY : src/params.o

# target to build an object file
src/params.cpp.o:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/params.cpp.o
.PHONY : src/params.cpp.o

src/params.i: src/params.cpp.i

.PHONY : src/params.i

# target to preprocess a source file
src/params.cpp.i:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/params.cpp.i
.PHONY : src/params.cpp.i

src/params.s: src/params.cpp.s

.PHONY : src/params.s

# target to generate assembly for a file
src/params.cpp.s:
	$(MAKE) -f CMakeFiles/lj.dir/build.make CMakeFiles/lj.dir/src/params.cpp.s
.PHONY : src/params.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... lj"
	@echo "... src/common.o"
	@echo "... src/common.i"
	@echo "... src/common.s"
	@echo "... src/linkedlist.o"
	@echo "... src/linkedlist.i"
	@echo "... src/linkedlist.s"
	@echo "... src/nbody_bin_io.o"
	@echo "... src/nbody_bin_io.i"
	@echo "... src/nbody_bin_io.s"
	@echo "... src/nbody_txt_io.o"
	@echo "... src/nbody_txt_io.i"
	@echo "... src/nbody_txt_io.s"
	@echo "... src/params.o"
	@echo "... src/params.i"
	@echo "... src/params.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

