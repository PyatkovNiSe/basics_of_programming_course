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
include string/tasks/CMakeFiles/tasks.dir/depend.make
# Include the progress variables for this target.
include string/tasks/CMakeFiles/tasks.dir/progress.make

# Include the compile flags for this target's objects.
include string/tasks/CMakeFiles/tasks.dir/flags.make

string/tasks/CMakeFiles/tasks.dir/string_.c.obj: string/tasks/CMakeFiles/tasks.dir/flags.make
string/tasks/CMakeFiles/tasks.dir/string_.c.obj: ../string/tasks/string_.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oosko\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object string/tasks/CMakeFiles/tasks.dir/string_.c.obj"
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\string\tasks && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\tasks.dir\string_.c.obj -c C:\Users\oosko\CLionProjects\course\string\tasks\string_.c

string/tasks/CMakeFiles/tasks.dir/string_.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tasks.dir/string_.c.i"
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\string\tasks && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\oosko\CLionProjects\course\string\tasks\string_.c > CMakeFiles\tasks.dir\string_.c.i

string/tasks/CMakeFiles/tasks.dir/string_.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tasks.dir/string_.c.s"
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\string\tasks && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\oosko\CLionProjects\course\string\tasks\string_.c -o CMakeFiles\tasks.dir\string_.c.s

string/tasks/CMakeFiles/tasks.dir/string_test.c.obj: string/tasks/CMakeFiles/tasks.dir/flags.make
string/tasks/CMakeFiles/tasks.dir/string_test.c.obj: ../string/tasks/string_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\oosko\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object string/tasks/CMakeFiles/tasks.dir/string_test.c.obj"
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\string\tasks && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\tasks.dir\string_test.c.obj -c C:\Users\oosko\CLionProjects\course\string\tasks\string_test.c

string/tasks/CMakeFiles/tasks.dir/string_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tasks.dir/string_test.c.i"
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\string\tasks && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\oosko\CLionProjects\course\string\tasks\string_test.c > CMakeFiles\tasks.dir\string_test.c.i

string/tasks/CMakeFiles/tasks.dir/string_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tasks.dir/string_test.c.s"
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\string\tasks && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\oosko\CLionProjects\course\string\tasks\string_test.c -o CMakeFiles\tasks.dir\string_test.c.s

# Object files for target tasks
tasks_OBJECTS = \
"CMakeFiles/tasks.dir/string_.c.obj" \
"CMakeFiles/tasks.dir/string_test.c.obj"

# External object files for target tasks
tasks_EXTERNAL_OBJECTS =

string/tasks/libtasks.a: string/tasks/CMakeFiles/tasks.dir/string_.c.obj
string/tasks/libtasks.a: string/tasks/CMakeFiles/tasks.dir/string_test.c.obj
string/tasks/libtasks.a: string/tasks/CMakeFiles/tasks.dir/build.make
string/tasks/libtasks.a: string/tasks/CMakeFiles/tasks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\oosko\CLionProjects\course\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libtasks.a"
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\string\tasks && $(CMAKE_COMMAND) -P CMakeFiles\tasks.dir\cmake_clean_target.cmake
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\string\tasks && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tasks.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
string/tasks/CMakeFiles/tasks.dir/build: string/tasks/libtasks.a
.PHONY : string/tasks/CMakeFiles/tasks.dir/build

string/tasks/CMakeFiles/tasks.dir/clean:
	cd /d C:\Users\oosko\CLionProjects\course\cmake-build-debug\string\tasks && $(CMAKE_COMMAND) -P CMakeFiles\tasks.dir\cmake_clean.cmake
.PHONY : string/tasks/CMakeFiles/tasks.dir/clean

string/tasks/CMakeFiles/tasks.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\oosko\CLionProjects\course C:\Users\oosko\CLionProjects\course\string\tasks C:\Users\oosko\CLionProjects\course\cmake-build-debug C:\Users\oosko\CLionProjects\course\cmake-build-debug\string\tasks C:\Users\oosko\CLionProjects\course\cmake-build-debug\string\tasks\CMakeFiles\tasks.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : string/tasks/CMakeFiles/tasks.dir/depend

