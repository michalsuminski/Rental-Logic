# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\MICHU13\Desktop\filmy\nowy\program

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\MICHU13\Desktop\filmy\nowy\program\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Program.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Program.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Program.dir/flags.make

CMakeFiles/Program.dir/src/main.cpp.obj: CMakeFiles/Program.dir/flags.make
CMakeFiles/Program.dir/src/main.cpp.obj: CMakeFiles/Program.dir/includes_CXX.rsp
CMakeFiles/Program.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\MICHU13\Desktop\filmy\nowy\program\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Program.dir/src/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Program.dir\src\main.cpp.obj -c C:\Users\MICHU13\Desktop\filmy\nowy\program\src\main.cpp

CMakeFiles/Program.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Program.dir/src/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\MICHU13\Desktop\filmy\nowy\program\src\main.cpp > CMakeFiles\Program.dir\src\main.cpp.i

CMakeFiles/Program.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Program.dir/src/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\MICHU13\Desktop\filmy\nowy\program\src\main.cpp -o CMakeFiles\Program.dir\src\main.cpp.s

# Object files for target Program
Program_OBJECTS = \
"CMakeFiles/Program.dir/src/main.cpp.obj"

# External object files for target Program
Program_EXTERNAL_OBJECTS =

Program.exe: CMakeFiles/Program.dir/src/main.cpp.obj
Program.exe: CMakeFiles/Program.dir/build.make
Program.exe: CMakeFiles/Program.dir/linklibs.rsp
Program.exe: CMakeFiles/Program.dir/objects1.rsp
Program.exe: CMakeFiles/Program.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\MICHU13\Desktop\filmy\nowy\program\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Program.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Program.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Program.dir/build: Program.exe

.PHONY : CMakeFiles/Program.dir/build

CMakeFiles/Program.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Program.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Program.dir/clean

CMakeFiles/Program.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\MICHU13\Desktop\filmy\nowy\program C:\Users\MICHU13\Desktop\filmy\nowy\program C:\Users\MICHU13\Desktop\filmy\nowy\program\cmake-build-debug C:\Users\MICHU13\Desktop\filmy\nowy\program\cmake-build-debug C:\Users\MICHU13\Desktop\filmy\nowy\program\cmake-build-debug\CMakeFiles\Program.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Program.dir/depend
