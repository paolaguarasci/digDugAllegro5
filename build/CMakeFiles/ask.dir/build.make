# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build"

# Include any dependencies generated for this target.
include CMakeFiles/ask.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ask.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ask.dir/flags.make

CMakeFiles/ask.dir/main.cpp.o: CMakeFiles/ask.dir/flags.make
CMakeFiles/ask.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ask.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ask.dir/main.cpp.o -c "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/main.cpp"

CMakeFiles/ask.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ask.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/main.cpp" > CMakeFiles/ask.dir/main.cpp.i

CMakeFiles/ask.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ask.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/main.cpp" -o CMakeFiles/ask.dir/main.cpp.s

CMakeFiles/ask.dir/app.cpp.o: CMakeFiles/ask.dir/flags.make
CMakeFiles/ask.dir/app.cpp.o: ../app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ask.dir/app.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ask.dir/app.cpp.o -c "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/app.cpp"

CMakeFiles/ask.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ask.dir/app.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/app.cpp" > CMakeFiles/ask.dir/app.cpp.i

CMakeFiles/ask.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ask.dir/app.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/app.cpp" -o CMakeFiles/ask.dir/app.cpp.s

CMakeFiles/ask.dir/map.cpp.o: CMakeFiles/ask.dir/flags.make
CMakeFiles/ask.dir/map.cpp.o: ../map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ask.dir/map.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ask.dir/map.cpp.o -c "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/map.cpp"

CMakeFiles/ask.dir/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ask.dir/map.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/map.cpp" > CMakeFiles/ask.dir/map.cpp.i

CMakeFiles/ask.dir/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ask.dir/map.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/map.cpp" -o CMakeFiles/ask.dir/map.cpp.s

CMakeFiles/ask.dir/player.cpp.o: CMakeFiles/ask.dir/flags.make
CMakeFiles/ask.dir/player.cpp.o: ../player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ask.dir/player.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ask.dir/player.cpp.o -c "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/player.cpp"

CMakeFiles/ask.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ask.dir/player.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/player.cpp" > CMakeFiles/ask.dir/player.cpp.i

CMakeFiles/ask.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ask.dir/player.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/player.cpp" -o CMakeFiles/ask.dir/player.cpp.s

CMakeFiles/ask.dir/Screen.cpp.o: CMakeFiles/ask.dir/flags.make
CMakeFiles/ask.dir/Screen.cpp.o: ../Screen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ask.dir/Screen.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ask.dir/Screen.cpp.o -c "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/Screen.cpp"

CMakeFiles/ask.dir/Screen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ask.dir/Screen.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/Screen.cpp" > CMakeFiles/ask.dir/Screen.cpp.i

CMakeFiles/ask.dir/Screen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ask.dir/Screen.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/Screen.cpp" -o CMakeFiles/ask.dir/Screen.cpp.s

CMakeFiles/ask.dir/Object.cpp.o: CMakeFiles/ask.dir/flags.make
CMakeFiles/ask.dir/Object.cpp.o: ../Object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/ask.dir/Object.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ask.dir/Object.cpp.o -c "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/Object.cpp"

CMakeFiles/ask.dir/Object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ask.dir/Object.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/Object.cpp" > CMakeFiles/ask.dir/Object.cpp.i

CMakeFiles/ask.dir/Object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ask.dir/Object.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/Object.cpp" -o CMakeFiles/ask.dir/Object.cpp.s

# Object files for target ask
ask_OBJECTS = \
"CMakeFiles/ask.dir/main.cpp.o" \
"CMakeFiles/ask.dir/app.cpp.o" \
"CMakeFiles/ask.dir/map.cpp.o" \
"CMakeFiles/ask.dir/player.cpp.o" \
"CMakeFiles/ask.dir/Screen.cpp.o" \
"CMakeFiles/ask.dir/Object.cpp.o"

# External object files for target ask
ask_EXTERNAL_OBJECTS =

ask: CMakeFiles/ask.dir/main.cpp.o
ask: CMakeFiles/ask.dir/app.cpp.o
ask: CMakeFiles/ask.dir/map.cpp.o
ask: CMakeFiles/ask.dir/player.cpp.o
ask: CMakeFiles/ask.dir/Screen.cpp.o
ask: CMakeFiles/ask.dir/Object.cpp.o
ask: CMakeFiles/ask.dir/build.make
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_acodec.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_acodec.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_acodec.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_audio.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_audio.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_audio.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_color.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_color.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_color.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_dialog.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_dialog.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_dialog.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_font.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_font.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_font.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_image.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_image.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_image.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_main.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_main.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_main.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_memfile.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_memfile.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_memfile.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_physfs.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_physfs.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_physfs.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_primitives.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_primitives.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_primitives.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_ttf.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_ttf.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_ttf.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_video.5.2.5.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_video.5.2.dylib
ask: /usr/local/Cellar/allegro/5.2.5.0/lib/liballegro_video.dylib
ask: /usr/local/lib/liballegro_tiled.dylib
ask: CMakeFiles/ask.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable ask"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ask.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ask.dir/build: ask

.PHONY : CMakeFiles/ask.dir/build

CMakeFiles/ask.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ask.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ask.dir/clean

CMakeFiles/ask.dir/depend:
	cd "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit" "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit" "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build" "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build" "/Users/paola/Library/CloudStorage/iCloud Drive/Desktop/workspace/_cpp/allegroStarterKit/build/CMakeFiles/ask.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ask.dir/depend

