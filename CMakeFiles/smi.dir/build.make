# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/nico/Projects/CPP/SMI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nico/Projects/CPP/SMI

# Include any dependencies generated for this target.
include CMakeFiles/smi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/smi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/smi.dir/flags.make

CMakeFiles/smi.dir/main.cpp.o: CMakeFiles/smi.dir/flags.make
CMakeFiles/smi.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nico/Projects/CPP/SMI/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/smi.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/smi.dir/main.cpp.o -c /home/nico/Projects/CPP/SMI/main.cpp

CMakeFiles/smi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smi.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nico/Projects/CPP/SMI/main.cpp > CMakeFiles/smi.dir/main.cpp.i

CMakeFiles/smi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smi.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nico/Projects/CPP/SMI/main.cpp -o CMakeFiles/smi.dir/main.cpp.s

CMakeFiles/smi.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/smi.dir/main.cpp.o.requires

CMakeFiles/smi.dir/main.cpp.o.provides: CMakeFiles/smi.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/smi.dir/build.make CMakeFiles/smi.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/smi.dir/main.cpp.o.provides

CMakeFiles/smi.dir/main.cpp.o.provides.build: CMakeFiles/smi.dir/main.cpp.o

CMakeFiles/smi.dir/Token.cpp.o: CMakeFiles/smi.dir/flags.make
CMakeFiles/smi.dir/Token.cpp.o: Token.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nico/Projects/CPP/SMI/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/smi.dir/Token.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/smi.dir/Token.cpp.o -c /home/nico/Projects/CPP/SMI/Token.cpp

CMakeFiles/smi.dir/Token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smi.dir/Token.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nico/Projects/CPP/SMI/Token.cpp > CMakeFiles/smi.dir/Token.cpp.i

CMakeFiles/smi.dir/Token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smi.dir/Token.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nico/Projects/CPP/SMI/Token.cpp -o CMakeFiles/smi.dir/Token.cpp.s

CMakeFiles/smi.dir/Token.cpp.o.requires:
.PHONY : CMakeFiles/smi.dir/Token.cpp.o.requires

CMakeFiles/smi.dir/Token.cpp.o.provides: CMakeFiles/smi.dir/Token.cpp.o.requires
	$(MAKE) -f CMakeFiles/smi.dir/build.make CMakeFiles/smi.dir/Token.cpp.o.provides.build
.PHONY : CMakeFiles/smi.dir/Token.cpp.o.provides

CMakeFiles/smi.dir/Token.cpp.o.provides.build: CMakeFiles/smi.dir/Token.cpp.o

CMakeFiles/smi.dir/Interpreter.cpp.o: CMakeFiles/smi.dir/flags.make
CMakeFiles/smi.dir/Interpreter.cpp.o: Interpreter.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nico/Projects/CPP/SMI/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/smi.dir/Interpreter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/smi.dir/Interpreter.cpp.o -c /home/nico/Projects/CPP/SMI/Interpreter.cpp

CMakeFiles/smi.dir/Interpreter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/smi.dir/Interpreter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nico/Projects/CPP/SMI/Interpreter.cpp > CMakeFiles/smi.dir/Interpreter.cpp.i

CMakeFiles/smi.dir/Interpreter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/smi.dir/Interpreter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nico/Projects/CPP/SMI/Interpreter.cpp -o CMakeFiles/smi.dir/Interpreter.cpp.s

CMakeFiles/smi.dir/Interpreter.cpp.o.requires:
.PHONY : CMakeFiles/smi.dir/Interpreter.cpp.o.requires

CMakeFiles/smi.dir/Interpreter.cpp.o.provides: CMakeFiles/smi.dir/Interpreter.cpp.o.requires
	$(MAKE) -f CMakeFiles/smi.dir/build.make CMakeFiles/smi.dir/Interpreter.cpp.o.provides.build
.PHONY : CMakeFiles/smi.dir/Interpreter.cpp.o.provides

CMakeFiles/smi.dir/Interpreter.cpp.o.provides.build: CMakeFiles/smi.dir/Interpreter.cpp.o

# Object files for target smi
smi_OBJECTS = \
"CMakeFiles/smi.dir/main.cpp.o" \
"CMakeFiles/smi.dir/Token.cpp.o" \
"CMakeFiles/smi.dir/Interpreter.cpp.o"

# External object files for target smi
smi_EXTERNAL_OBJECTS =

smi: CMakeFiles/smi.dir/main.cpp.o
smi: CMakeFiles/smi.dir/Token.cpp.o
smi: CMakeFiles/smi.dir/Interpreter.cpp.o
smi: CMakeFiles/smi.dir/build.make
smi: CMakeFiles/smi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable smi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/smi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/smi.dir/build: smi
.PHONY : CMakeFiles/smi.dir/build

CMakeFiles/smi.dir/requires: CMakeFiles/smi.dir/main.cpp.o.requires
CMakeFiles/smi.dir/requires: CMakeFiles/smi.dir/Token.cpp.o.requires
CMakeFiles/smi.dir/requires: CMakeFiles/smi.dir/Interpreter.cpp.o.requires
.PHONY : CMakeFiles/smi.dir/requires

CMakeFiles/smi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/smi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/smi.dir/clean

CMakeFiles/smi.dir/depend:
	cd /home/nico/Projects/CPP/SMI && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nico/Projects/CPP/SMI /home/nico/Projects/CPP/SMI /home/nico/Projects/CPP/SMI /home/nico/Projects/CPP/SMI /home/nico/Projects/CPP/SMI/CMakeFiles/smi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/smi.dir/depend
