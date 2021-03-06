# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/handy/work/yacc/metacc/dev/out/calc/out

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/handy/work/yacc/metacc/dev/out/calc/out/build

# Include any dependencies generated for this target.
include CMakeFiles/out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/out.dir/flags.make

parser.tab.cc: ../parser.yy
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/handy/work/yacc/metacc/dev/out/calc/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][parser] Building parser with bison 3.5.1"
	cd /home/handy/work/yacc/metacc/dev/out/calc/out && /usr/bin/bison -d -o /home/handy/work/yacc/metacc/dev/out/calc/out/build/parser.tab.cc parser.yy

parser.tab.hh: parser.tab.cc
	@$(CMAKE_COMMAND) -E touch_nocreate parser.tab.hh

parser.yy.cc: ../parser.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/handy/work/yacc/metacc/dev/out/calc/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[FLEX][lexer] Building scanner with flex 2.6.4"
	cd /home/handy/work/yacc/metacc/dev/out/calc/out && /usr/bin/flex -o/home/handy/work/yacc/metacc/dev/out/calc/out/build/parser.yy.cc parser.l

CMakeFiles/out.dir/parser_ast.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/parser_ast.cpp.o: ../parser_ast.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/handy/work/yacc/metacc/dev/out/calc/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/out.dir/parser_ast.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/parser_ast.cpp.o -c /home/handy/work/yacc/metacc/dev/out/calc/out/parser_ast.cpp

CMakeFiles/out.dir/parser_ast.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/parser_ast.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/handy/work/yacc/metacc/dev/out/calc/out/parser_ast.cpp > CMakeFiles/out.dir/parser_ast.cpp.i

CMakeFiles/out.dir/parser_ast.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/parser_ast.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/handy/work/yacc/metacc/dev/out/calc/out/parser_ast.cpp -o CMakeFiles/out.dir/parser_ast.cpp.s

CMakeFiles/out.dir/parser.tab.cc.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/parser.tab.cc.o: parser.tab.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/handy/work/yacc/metacc/dev/out/calc/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/out.dir/parser.tab.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/parser.tab.cc.o -c /home/handy/work/yacc/metacc/dev/out/calc/out/build/parser.tab.cc

CMakeFiles/out.dir/parser.tab.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/parser.tab.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/handy/work/yacc/metacc/dev/out/calc/out/build/parser.tab.cc > CMakeFiles/out.dir/parser.tab.cc.i

CMakeFiles/out.dir/parser.tab.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/parser.tab.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/handy/work/yacc/metacc/dev/out/calc/out/build/parser.tab.cc -o CMakeFiles/out.dir/parser.tab.cc.s

CMakeFiles/out.dir/parser.yy.cc.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/parser.yy.cc.o: parser.yy.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/handy/work/yacc/metacc/dev/out/calc/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/out.dir/parser.yy.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/parser.yy.cc.o -c /home/handy/work/yacc/metacc/dev/out/calc/out/build/parser.yy.cc

CMakeFiles/out.dir/parser.yy.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/parser.yy.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/handy/work/yacc/metacc/dev/out/calc/out/build/parser.yy.cc > CMakeFiles/out.dir/parser.yy.cc.i

CMakeFiles/out.dir/parser.yy.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/parser.yy.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/handy/work/yacc/metacc/dev/out/calc/out/build/parser.yy.cc -o CMakeFiles/out.dir/parser.yy.cc.s

# Object files for target out
out_OBJECTS = \
"CMakeFiles/out.dir/parser_ast.cpp.o" \
"CMakeFiles/out.dir/parser.tab.cc.o" \
"CMakeFiles/out.dir/parser.yy.cc.o"

# External object files for target out
out_EXTERNAL_OBJECTS =

out: CMakeFiles/out.dir/parser_ast.cpp.o
out: CMakeFiles/out.dir/parser.tab.cc.o
out: CMakeFiles/out.dir/parser.yy.cc.o
out: CMakeFiles/out.dir/build.make
out: CMakeFiles/out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/handy/work/yacc/metacc/dev/out/calc/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/out.dir/build: out

.PHONY : CMakeFiles/out.dir/build

CMakeFiles/out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/out.dir/clean

CMakeFiles/out.dir/depend: parser.tab.cc
CMakeFiles/out.dir/depend: parser.tab.hh
CMakeFiles/out.dir/depend: parser.yy.cc
	cd /home/handy/work/yacc/metacc/dev/out/calc/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/handy/work/yacc/metacc/dev/out/calc/out /home/handy/work/yacc/metacc/dev/out/calc/out /home/handy/work/yacc/metacc/dev/out/calc/out/build /home/handy/work/yacc/metacc/dev/out/calc/out/build /home/handy/work/yacc/metacc/dev/out/calc/out/build/CMakeFiles/out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/out.dir/depend

