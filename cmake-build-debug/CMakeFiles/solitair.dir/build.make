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
CMAKE_SOURCE_DIR = /mnt/c/Users/giuli/CLionProjects/solitair

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/solitair.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/solitair.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/solitair.dir/flags.make

CMakeFiles/solitair.dir/main.c.o: CMakeFiles/solitair.dir/flags.make
CMakeFiles/solitair.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/solitair.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/solitair.dir/main.c.o   -c /mnt/c/Users/giuli/CLionProjects/solitair/main.c

CMakeFiles/solitair.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/solitair.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/giuli/CLionProjects/solitair/main.c > CMakeFiles/solitair.dir/main.c.i

CMakeFiles/solitair.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/solitair.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/giuli/CLionProjects/solitair/main.c -o CMakeFiles/solitair.dir/main.c.s

CMakeFiles/solitair.dir/lib/card/card.c.o: CMakeFiles/solitair.dir/flags.make
CMakeFiles/solitair.dir/lib/card/card.c.o: ../lib/card/card.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/solitair.dir/lib/card/card.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/solitair.dir/lib/card/card.c.o   -c /mnt/c/Users/giuli/CLionProjects/solitair/lib/card/card.c

CMakeFiles/solitair.dir/lib/card/card.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/solitair.dir/lib/card/card.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/giuli/CLionProjects/solitair/lib/card/card.c > CMakeFiles/solitair.dir/lib/card/card.c.i

CMakeFiles/solitair.dir/lib/card/card.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/solitair.dir/lib/card/card.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/giuli/CLionProjects/solitair/lib/card/card.c -o CMakeFiles/solitair.dir/lib/card/card.c.s

CMakeFiles/solitair.dir/lib/foundation/foundation.c.o: CMakeFiles/solitair.dir/flags.make
CMakeFiles/solitair.dir/lib/foundation/foundation.c.o: ../lib/foundation/foundation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/solitair.dir/lib/foundation/foundation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/solitair.dir/lib/foundation/foundation.c.o   -c /mnt/c/Users/giuli/CLionProjects/solitair/lib/foundation/foundation.c

CMakeFiles/solitair.dir/lib/foundation/foundation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/solitair.dir/lib/foundation/foundation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/giuli/CLionProjects/solitair/lib/foundation/foundation.c > CMakeFiles/solitair.dir/lib/foundation/foundation.c.i

CMakeFiles/solitair.dir/lib/foundation/foundation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/solitair.dir/lib/foundation/foundation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/giuli/CLionProjects/solitair/lib/foundation/foundation.c -o CMakeFiles/solitair.dir/lib/foundation/foundation.c.s

CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.o: CMakeFiles/solitair.dir/flags.make
CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.o: ../lib/discard_pile/discard_pile.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.o   -c /mnt/c/Users/giuli/CLionProjects/solitair/lib/discard_pile/discard_pile.c

CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/giuli/CLionProjects/solitair/lib/discard_pile/discard_pile.c > CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.i

CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/giuli/CLionProjects/solitair/lib/discard_pile/discard_pile.c -o CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.s

CMakeFiles/solitair.dir/lib/stock/stock.c.o: CMakeFiles/solitair.dir/flags.make
CMakeFiles/solitair.dir/lib/stock/stock.c.o: ../lib/stock/stock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/solitair.dir/lib/stock/stock.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/solitair.dir/lib/stock/stock.c.o   -c /mnt/c/Users/giuli/CLionProjects/solitair/lib/stock/stock.c

CMakeFiles/solitair.dir/lib/stock/stock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/solitair.dir/lib/stock/stock.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/giuli/CLionProjects/solitair/lib/stock/stock.c > CMakeFiles/solitair.dir/lib/stock/stock.c.i

CMakeFiles/solitair.dir/lib/stock/stock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/solitair.dir/lib/stock/stock.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/giuli/CLionProjects/solitair/lib/stock/stock.c -o CMakeFiles/solitair.dir/lib/stock/stock.c.s

CMakeFiles/solitair.dir/lib/deck/deck.c.o: CMakeFiles/solitair.dir/flags.make
CMakeFiles/solitair.dir/lib/deck/deck.c.o: ../lib/deck/deck.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/solitair.dir/lib/deck/deck.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/solitair.dir/lib/deck/deck.c.o   -c /mnt/c/Users/giuli/CLionProjects/solitair/lib/deck/deck.c

CMakeFiles/solitair.dir/lib/deck/deck.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/solitair.dir/lib/deck/deck.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/giuli/CLionProjects/solitair/lib/deck/deck.c > CMakeFiles/solitair.dir/lib/deck/deck.c.i

CMakeFiles/solitair.dir/lib/deck/deck.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/solitair.dir/lib/deck/deck.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/giuli/CLionProjects/solitair/lib/deck/deck.c -o CMakeFiles/solitair.dir/lib/deck/deck.c.s

# Object files for target solitair
solitair_OBJECTS = \
"CMakeFiles/solitair.dir/main.c.o" \
"CMakeFiles/solitair.dir/lib/card/card.c.o" \
"CMakeFiles/solitair.dir/lib/foundation/foundation.c.o" \
"CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.o" \
"CMakeFiles/solitair.dir/lib/stock/stock.c.o" \
"CMakeFiles/solitair.dir/lib/deck/deck.c.o"

# External object files for target solitair
solitair_EXTERNAL_OBJECTS =

solitair: CMakeFiles/solitair.dir/main.c.o
solitair: CMakeFiles/solitair.dir/lib/card/card.c.o
solitair: CMakeFiles/solitair.dir/lib/foundation/foundation.c.o
solitair: CMakeFiles/solitair.dir/lib/discard_pile/discard_pile.c.o
solitair: CMakeFiles/solitair.dir/lib/stock/stock.c.o
solitair: CMakeFiles/solitair.dir/lib/deck/deck.c.o
solitair: CMakeFiles/solitair.dir/build.make
solitair: /usr/lib/x86_64-linux-gnu/libcurses.so
solitair: /usr/lib/x86_64-linux-gnu/libform.so
solitair: CMakeFiles/solitair.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable solitair"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/solitair.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/solitair.dir/build: solitair

.PHONY : CMakeFiles/solitair.dir/build

CMakeFiles/solitair.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/solitair.dir/cmake_clean.cmake
.PHONY : CMakeFiles/solitair.dir/clean

CMakeFiles/solitair.dir/depend:
	cd /mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/giuli/CLionProjects/solitair /mnt/c/Users/giuli/CLionProjects/solitair /mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug /mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug /mnt/c/Users/giuli/CLionProjects/solitair/cmake-build-debug/CMakeFiles/solitair.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/solitair.dir/depend

