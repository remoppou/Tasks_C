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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CProjects\C_Task6_var7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CProjects\C_Task6_var7\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Task6_var7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Task6_var7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Task6_var7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Task6_var7.dir/flags.make

CMakeFiles/Task6_var7.dir/main.cpp.obj: CMakeFiles/Task6_var7.dir/flags.make
CMakeFiles/Task6_var7.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Task6_var7.dir/main.cpp.obj: CMakeFiles/Task6_var7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CProjects\C_Task6_var7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Task6_var7.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Task6_var7.dir/main.cpp.obj -MF CMakeFiles\Task6_var7.dir\main.cpp.obj.d -o CMakeFiles\Task6_var7.dir\main.cpp.obj -c D:\CProjects\C_Task6_var7\main.cpp

CMakeFiles/Task6_var7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Task6_var7.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CProjects\C_Task6_var7\main.cpp > CMakeFiles\Task6_var7.dir\main.cpp.i

CMakeFiles/Task6_var7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Task6_var7.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CProjects\C_Task6_var7\main.cpp -o CMakeFiles\Task6_var7.dir\main.cpp.s

# Object files for target Task6_var7
Task6_var7_OBJECTS = \
"CMakeFiles/Task6_var7.dir/main.cpp.obj"

# External object files for target Task6_var7
Task6_var7_EXTERNAL_OBJECTS =

Task6_var7.exe: CMakeFiles/Task6_var7.dir/main.cpp.obj
Task6_var7.exe: CMakeFiles/Task6_var7.dir/build.make
Task6_var7.exe: CMakeFiles/Task6_var7.dir/linklibs.rsp
Task6_var7.exe: CMakeFiles/Task6_var7.dir/objects1.rsp
Task6_var7.exe: CMakeFiles/Task6_var7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CProjects\C_Task6_var7\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Task6_var7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Task6_var7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Task6_var7.dir/build: Task6_var7.exe
.PHONY : CMakeFiles/Task6_var7.dir/build

CMakeFiles/Task6_var7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Task6_var7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Task6_var7.dir/clean

CMakeFiles/Task6_var7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CProjects\C_Task6_var7 D:\CProjects\C_Task6_var7 D:\CProjects\C_Task6_var7\cmake-build-debug D:\CProjects\C_Task6_var7\cmake-build-debug D:\CProjects\C_Task6_var7\cmake-build-debug\CMakeFiles\Task6_var7.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Task6_var7.dir/depend
