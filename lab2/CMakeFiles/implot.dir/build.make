# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kodor/proj/sem_iv_algos/lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kodor/proj/sem_iv_algos/lab2

# Include any dependencies generated for this target.
include CMakeFiles/implot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/implot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/implot.dir/flags.make

CMakeFiles/implot.dir/external/implot/implot_items.cpp.o: CMakeFiles/implot.dir/flags.make
CMakeFiles/implot.dir/external/implot/implot_items.cpp.o: external/implot/implot_items.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kodor/proj/sem_iv_algos/lab2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/implot.dir/external/implot/implot_items.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/implot.dir/external/implot/implot_items.cpp.o -c /home/kodor/proj/sem_iv_algos/lab2/external/implot/implot_items.cpp

CMakeFiles/implot.dir/external/implot/implot_items.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/implot.dir/external/implot/implot_items.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kodor/proj/sem_iv_algos/lab2/external/implot/implot_items.cpp > CMakeFiles/implot.dir/external/implot/implot_items.cpp.i

CMakeFiles/implot.dir/external/implot/implot_items.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/implot.dir/external/implot/implot_items.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kodor/proj/sem_iv_algos/lab2/external/implot/implot_items.cpp -o CMakeFiles/implot.dir/external/implot/implot_items.cpp.s

CMakeFiles/implot.dir/external/implot/implot.cpp.o: CMakeFiles/implot.dir/flags.make
CMakeFiles/implot.dir/external/implot/implot.cpp.o: external/implot/implot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kodor/proj/sem_iv_algos/lab2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/implot.dir/external/implot/implot.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/implot.dir/external/implot/implot.cpp.o -c /home/kodor/proj/sem_iv_algos/lab2/external/implot/implot.cpp

CMakeFiles/implot.dir/external/implot/implot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/implot.dir/external/implot/implot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kodor/proj/sem_iv_algos/lab2/external/implot/implot.cpp > CMakeFiles/implot.dir/external/implot/implot.cpp.i

CMakeFiles/implot.dir/external/implot/implot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/implot.dir/external/implot/implot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kodor/proj/sem_iv_algos/lab2/external/implot/implot.cpp -o CMakeFiles/implot.dir/external/implot/implot.cpp.s

CMakeFiles/implot.dir/external/imgui/imgui.cpp.o: CMakeFiles/implot.dir/flags.make
CMakeFiles/implot.dir/external/imgui/imgui.cpp.o: external/imgui/imgui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kodor/proj/sem_iv_algos/lab2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/implot.dir/external/imgui/imgui.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/implot.dir/external/imgui/imgui.cpp.o -c /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui.cpp

CMakeFiles/implot.dir/external/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/implot.dir/external/imgui/imgui.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui.cpp > CMakeFiles/implot.dir/external/imgui/imgui.cpp.i

CMakeFiles/implot.dir/external/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/implot.dir/external/imgui/imgui.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui.cpp -o CMakeFiles/implot.dir/external/imgui/imgui.cpp.s

CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.o: CMakeFiles/implot.dir/flags.make
CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.o: external/imgui/imgui_draw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kodor/proj/sem_iv_algos/lab2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.o -c /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_draw.cpp

CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_draw.cpp > CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.i

CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_draw.cpp -o CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.s

CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.o: CMakeFiles/implot.dir/flags.make
CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.o: external/imgui/imgui_widgets.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kodor/proj/sem_iv_algos/lab2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.o -c /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_widgets.cpp

CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_widgets.cpp > CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.i

CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_widgets.cpp -o CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.s

CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.o: CMakeFiles/implot.dir/flags.make
CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.o: external/imgui/imgui_impl_glfw.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kodor/proj/sem_iv_algos/lab2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.o -c /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_impl_glfw.cpp

CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_impl_glfw.cpp > CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.i

CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_impl_glfw.cpp -o CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.s

CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.o: CMakeFiles/implot.dir/flags.make
CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.o: external/imgui/imgui_impl_opengl3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kodor/proj/sem_iv_algos/lab2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.o -c /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_impl_opengl3.cpp

CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_impl_opengl3.cpp > CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.i

CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kodor/proj/sem_iv_algos/lab2/external/imgui/imgui_impl_opengl3.cpp -o CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.s

# Object files for target implot
implot_OBJECTS = \
"CMakeFiles/implot.dir/external/implot/implot_items.cpp.o" \
"CMakeFiles/implot.dir/external/implot/implot.cpp.o" \
"CMakeFiles/implot.dir/external/imgui/imgui.cpp.o" \
"CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.o" \
"CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.o" \
"CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.o" \
"CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.o"

# External object files for target implot
implot_EXTERNAL_OBJECTS =

libimplot.a: CMakeFiles/implot.dir/external/implot/implot_items.cpp.o
libimplot.a: CMakeFiles/implot.dir/external/implot/implot.cpp.o
libimplot.a: CMakeFiles/implot.dir/external/imgui/imgui.cpp.o
libimplot.a: CMakeFiles/implot.dir/external/imgui/imgui_draw.cpp.o
libimplot.a: CMakeFiles/implot.dir/external/imgui/imgui_widgets.cpp.o
libimplot.a: CMakeFiles/implot.dir/external/imgui/imgui_impl_glfw.cpp.o
libimplot.a: CMakeFiles/implot.dir/external/imgui/imgui_impl_opengl3.cpp.o
libimplot.a: CMakeFiles/implot.dir/build.make
libimplot.a: CMakeFiles/implot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kodor/proj/sem_iv_algos/lab2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libimplot.a"
	$(CMAKE_COMMAND) -P CMakeFiles/implot.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/implot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/implot.dir/build: libimplot.a

.PHONY : CMakeFiles/implot.dir/build

CMakeFiles/implot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/implot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/implot.dir/clean

CMakeFiles/implot.dir/depend:
	cd /home/kodor/proj/sem_iv_algos/lab2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kodor/proj/sem_iv_algos/lab2 /home/kodor/proj/sem_iv_algos/lab2 /home/kodor/proj/sem_iv_algos/lab2 /home/kodor/proj/sem_iv_algos/lab2 /home/kodor/proj/sem_iv_algos/lab2/CMakeFiles/implot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/implot.dir/depend
