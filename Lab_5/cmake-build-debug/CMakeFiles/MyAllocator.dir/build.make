# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = C:\Users\Aslan\CLionProjects\MyAllocator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Aslan\CLionProjects\MyAllocator\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MyAllocator.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/MyAllocator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyAllocator.dir/flags.make

CMakeFiles/MyAllocator.dir/main.cpp.obj: CMakeFiles/MyAllocator.dir/flags.make
CMakeFiles/MyAllocator.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Aslan\CLionProjects\MyAllocator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyAllocator.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MyAllocator.dir\main.cpp.obj -c C:\Users\Aslan\CLionProjects\MyAllocator\main.cpp

CMakeFiles/MyAllocator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyAllocator.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Aslan\CLionProjects\MyAllocator\main.cpp > CMakeFiles\MyAllocator.dir\main.cpp.i

CMakeFiles/MyAllocator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyAllocator.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Aslan\CLionProjects\MyAllocator\main.cpp -o CMakeFiles\MyAllocator.dir\main.cpp.s

# Object files for target MyAllocator
MyAllocator_OBJECTS = \
"CMakeFiles/MyAllocator.dir/main.cpp.obj"

# External object files for target MyAllocator
MyAllocator_EXTERNAL_OBJECTS =

MyAllocator.exe: CMakeFiles/MyAllocator.dir/main.cpp.obj
MyAllocator.exe: CMakeFiles/MyAllocator.dir/build.make
MyAllocator.exe: CMakeFiles/MyAllocator.dir/linklibs.rsp
MyAllocator.exe: CMakeFiles/MyAllocator.dir/objects1.rsp
MyAllocator.exe: CMakeFiles/MyAllocator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Aslan\CLionProjects\MyAllocator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyAllocator.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MyAllocator.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyAllocator.dir/build: MyAllocator.exe
.PHONY : CMakeFiles/MyAllocator.dir/build

CMakeFiles/MyAllocator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MyAllocator.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MyAllocator.dir/clean

CMakeFiles/MyAllocator.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Aslan\CLionProjects\MyAllocator C:\Users\Aslan\CLionProjects\MyAllocator C:\Users\Aslan\CLionProjects\MyAllocator\cmake-build-debug C:\Users\Aslan\CLionProjects\MyAllocator\cmake-build-debug C:\Users\Aslan\CLionProjects\MyAllocator\cmake-build-debug\CMakeFiles\MyAllocator.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyAllocator.dir/depend

