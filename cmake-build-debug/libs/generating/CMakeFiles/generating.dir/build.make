# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\oosko\CLionProjects\course

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\oosko\CLionProjects\course\cmake-build-debug

# Include any dependencies generated for this target.
include libs/generating/CMakeFiles/generating.dir/depend.make
# Include the progress variables for this target.
include libs/generating/CMakeFiles/generating.dir/progress.make

# Include the compile flags for this target's objects.
include libs/generating/CMakeFiles/generating.dir/flags.make

libs/generating/CMakeFiles/generating.dir/generatingFunc.c.obj: libs/generating/CMakeFiles/generating.dir/flags.make
libs/generating/CMakeFiles/generating.dir/generatingFunc.c.obj: ../libs/generating/generatingFunc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oosko\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/generating/CMakeFiles/generating.dir/generatingFunc.c.obj"
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\libs\generating && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\generating.dir\generatingFunc.c.obj -c C:\Users\oosko\CLionProjects\course\libs\generating\generatingFunc.c

libs/generating/CMakeFiles/generating.dir/generatingFunc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/generating.dir/generatingFunc.c.i"
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\libs\generating && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\oosko\CLionProjects\course\libs\generating\generatingFunc.c > CMakeFiles\generating.dir\generatingFunc.c.i

libs/generating/CMakeFiles/generating.dir/generatingFunc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/generating.dir/generatingFunc.c.s"
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\libs\generating && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\oosko\CLionProjects\course\libs\generating\generatingFunc.c -o CMakeFiles\generating.dir\generatingFunc.c.s

# Object files for target generating
generating_OBJECTS = \
"CMakeFiles/generating.dir/generatingFunc.c.obj"

# External object files for target generating
generating_EXTERNAL_OBJECTS =

libs/generating/libgenerating.a: libs/generating/CMakeFiles/generating.dir/generatingFunc.c.obj
libs/generating/libgenerating.a: libs/generating/CMakeFiles/generating.dir/build.make
libs/generating/libgenerating.a: libs/generating/CMakeFiles/generating.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\oosko\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libgenerating.a"
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\libs\generating && $(CMAKE_COMMAND) -P CMakeFiles\generating.dir\cmake_clean_target.cmake
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\libs\generating && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\generating.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/generating/CMakeFiles/generating.dir/build: libs/generating/libgenerating.a
.PHONY : libs/generating/CMakeFiles/generating.dir/build

libs/generating/CMakeFiles/generating.dir/clean:
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\libs\generating && $(CMAKE_COMMAND) -P CMakeFiles\generating.dir\cmake_clean.cmake
.PHONY : libs/generating/CMakeFiles/generating.dir/clean

libs/generating/CMakeFiles/generating.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\oosko\CLionProjects\course C:\Users\oosko\CLionProjects\course\libs\generating C:\Users\oosko\CLionProjects\course\cmake-build-debug C:\Users\oosko\CLionProjects\course\cmake-build-debug\libs\generating C:\Users\oosko\CLionProjects\course\cmake-build-debug\libs\generating\CMakeFiles\generating.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : libs/generating/CMakeFiles/generating.dir/depend

