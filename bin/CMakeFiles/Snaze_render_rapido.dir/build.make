# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin

# Include any dependencies generated for this target.
include CMakeFiles/Snaze_render_rapido.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Snaze_render_rapido.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Snaze_render_rapido.dir/flags.make

CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o: CMakeFiles/Snaze_render_rapido.dir/flags.make
CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o: ../src/Level.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o -c /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Level.cpp

CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Level.cpp > CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.i

CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Level.cpp -o CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.s

CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o.requires:

.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o.requires

CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o.provides: CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o.requires
	$(MAKE) -f CMakeFiles/Snaze_render_rapido.dir/build.make CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o.provides.build
.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o.provides

CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o.provides.build: CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o


CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o: CMakeFiles/Snaze_render_rapido.dir/flags.make
CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o: ../src/Snaze.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o -c /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Snaze.cpp

CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Snaze.cpp > CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.i

CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Snaze.cpp -o CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.s

CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o.requires:

.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o.requires

CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o.provides: CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o.requires
	$(MAKE) -f CMakeFiles/Snaze_render_rapido.dir/build.make CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o.provides.build
.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o.provides

CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o.provides.build: CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o


CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o: CMakeFiles/Snaze_render_rapido.dir/flags.make
CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o: ../src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o -c /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Player.cpp

CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Player.cpp > CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.i

CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Player.cpp -o CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.s

CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o.requires:

.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o.requires

CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o.provides: CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o.requires
	$(MAKE) -f CMakeFiles/Snaze_render_rapido.dir/build.make CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o.provides.build
.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o.provides

CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o.provides.build: CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o


CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o: CMakeFiles/Snaze_render_rapido.dir/flags.make
CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o: ../src/Servicos.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o -c /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Servicos.cpp

CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Servicos.cpp > CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.i

CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Servicos.cpp -o CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.s

CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o.requires:

.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o.requires

CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o.provides: CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o.requires
	$(MAKE) -f CMakeFiles/Snaze_render_rapido.dir/build.make CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o.provides.build
.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o.provides

CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o.provides.build: CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o


CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o: CMakeFiles/Snaze_render_rapido.dir/flags.make
CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o: ../src/Snake.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o -c /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Snake.cpp

CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Snake.cpp > CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.i

CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/Snake.cpp -o CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.s

CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o.requires:

.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o.requires

CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o.provides: CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o.requires
	$(MAKE) -f CMakeFiles/Snaze_render_rapido.dir/build.make CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o.provides.build
.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o.provides

CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o.provides.build: CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o


CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o: CMakeFiles/Snaze_render_rapido.dir/flags.make
CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o: ../src/SnakeGame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o -c /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/SnakeGame.cpp

CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/SnakeGame.cpp > CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.i

CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/SnakeGame.cpp -o CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.s

CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o.requires:

.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o.requires

CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o.provides: CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o.requires
	$(MAKE) -f CMakeFiles/Snaze_render_rapido.dir/build.make CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o.provides.build
.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o.provides

CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o.provides.build: CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o


CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o: CMakeFiles/Snaze_render_rapido.dir/flags.make
CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o: ../src/ArrestaGrafo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o -c /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/ArrestaGrafo.cpp

CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/ArrestaGrafo.cpp > CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.i

CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/src/ArrestaGrafo.cpp -o CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.s

CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o.requires:

.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o.requires

CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o.provides: CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o.requires
	$(MAKE) -f CMakeFiles/Snaze_render_rapido.dir/build.make CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o.provides.build
.PHONY : CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o.provides

CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o.provides.build: CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o


# Object files for target Snaze_render_rapido
Snaze_render_rapido_OBJECTS = \
"CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o" \
"CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o" \
"CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o" \
"CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o" \
"CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o" \
"CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o" \
"CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o"

# External object files for target Snaze_render_rapido
Snaze_render_rapido_EXTERNAL_OBJECTS =

Snaze_render_rapido: CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o
Snaze_render_rapido: CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o
Snaze_render_rapido: CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o
Snaze_render_rapido: CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o
Snaze_render_rapido: CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o
Snaze_render_rapido: CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o
Snaze_render_rapido: CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o
Snaze_render_rapido: CMakeFiles/Snaze_render_rapido.dir/build.make
Snaze_render_rapido: CMakeFiles/Snaze_render_rapido.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Snaze_render_rapido"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Snaze_render_rapido.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Snaze_render_rapido.dir/build: Snaze_render_rapido

.PHONY : CMakeFiles/Snaze_render_rapido.dir/build

CMakeFiles/Snaze_render_rapido.dir/requires: CMakeFiles/Snaze_render_rapido.dir/src/Level.cpp.o.requires
CMakeFiles/Snaze_render_rapido.dir/requires: CMakeFiles/Snaze_render_rapido.dir/src/Snaze.cpp.o.requires
CMakeFiles/Snaze_render_rapido.dir/requires: CMakeFiles/Snaze_render_rapido.dir/src/Player.cpp.o.requires
CMakeFiles/Snaze_render_rapido.dir/requires: CMakeFiles/Snaze_render_rapido.dir/src/Servicos.cpp.o.requires
CMakeFiles/Snaze_render_rapido.dir/requires: CMakeFiles/Snaze_render_rapido.dir/src/Snake.cpp.o.requires
CMakeFiles/Snaze_render_rapido.dir/requires: CMakeFiles/Snaze_render_rapido.dir/src/SnakeGame.cpp.o.requires
CMakeFiles/Snaze_render_rapido.dir/requires: CMakeFiles/Snaze_render_rapido.dir/src/ArrestaGrafo.cpp.o.requires

.PHONY : CMakeFiles/Snaze_render_rapido.dir/requires

CMakeFiles/Snaze_render_rapido.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Snaze_render_rapido.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Snaze_render_rapido.dir/clean

CMakeFiles/Snaze_render_rapido.dir/depend:
	cd /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789 /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789 /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin /home/runner/Trabalho-Snaze-LP1/trabalho-3-humberto789/bin/CMakeFiles/Snaze_render_rapido.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Snaze_render_rapido.dir/depend

