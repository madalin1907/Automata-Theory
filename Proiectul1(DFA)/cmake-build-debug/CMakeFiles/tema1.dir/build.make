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
CMAKE_COMMAND = "C:\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\CLion 2021.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA)

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA)\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tema1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tema1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tema1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tema1.dir/flags.make

CMakeFiles/tema1.dir/main.cpp.obj: CMakeFiles/tema1.dir/flags.make
CMakeFiles/tema1.dir/main.cpp.obj: ../main.cpp
CMakeFiles/tema1.dir/main.cpp.obj: CMakeFiles/tema1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA)\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tema1.dir/main.cpp.obj"
	C:\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tema1.dir/main.cpp.obj -MF CMakeFiles\tema1.dir\main.cpp.obj.d -o CMakeFiles\tema1.dir\main.cpp.obj -c C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA)\main.cpp

CMakeFiles/tema1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tema1.dir/main.cpp.i"
	C:\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA)\main.cpp > CMakeFiles\tema1.dir\main.cpp.i

CMakeFiles/tema1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tema1.dir/main.cpp.s"
	C:\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA)\main.cpp -o CMakeFiles\tema1.dir\main.cpp.s

# Object files for target tema1
tema1_OBJECTS = \
"CMakeFiles/tema1.dir/main.cpp.obj"

# External object files for target tema1
tema1_EXTERNAL_OBJECTS =

tema1.exe: CMakeFiles/tema1.dir/main.cpp.obj
tema1.exe: CMakeFiles/tema1.dir/build.make
tema1.exe: CMakeFiles/tema1.dir/linklibs.rsp
tema1.exe: CMakeFiles/tema1.dir/objects1.rsp
tema1.exe: CMakeFiles/tema1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA)\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tema1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tema1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tema1.dir/build: tema1.exe
.PHONY : CMakeFiles/tema1.dir/build

CMakeFiles/tema1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tema1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tema1.dir/clean

CMakeFiles/tema1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA) C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA) C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA)\cmake-build-debug C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA)\cmake-build-debug C:\Users\Madalin\Desktop\LFA\Proiectul1(DFA)\cmake-build-debug\CMakeFiles\tema1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tema1.dir/depend

