# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lymondgl/Desktop/s21_MultilayerPerceptron

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/s21_MultilayerPerceptron.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/s21_MultilayerPerceptron.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/s21_MultilayerPerceptron.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/s21_MultilayerPerceptron.dir/flags.make

CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.o: CMakeFiles/s21_MultilayerPerceptron.dir/flags.make
CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.o: ../src/matrix/s21_matrix.cpp
CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.o: CMakeFiles/s21_MultilayerPerceptron.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.o -MF CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.o.d -o CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.o -c /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/matrix/s21_matrix.cpp

CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/matrix/s21_matrix.cpp > CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.i

CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/matrix/s21_matrix.cpp -o CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.s

CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/flags.make
CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.o: ../src/matrix/s21_support_func.cc
CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.o -MF CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.o.d -o CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.o -c /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/matrix/s21_support_func.cc

CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/matrix/s21_support_func.cc > CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.i

CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/matrix/s21_support_func.cc -o CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.s

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/flags.make
CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.o: ../src/model/neuron.cc
CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.o -MF CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.o.d -o CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.o -c /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/neuron.cc

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/neuron.cc > CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.i

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/neuron.cc -o CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.s

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/flags.make
CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.o: ../src/model/graph_network.cc
CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.o -MF CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.o.d -o CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.o -c /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/graph_network.cc

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/graph_network.cc > CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.i

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/graph_network.cc -o CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.s

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/flags.make
CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.o: ../src/model/matrix.cc
CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.o -MF CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.o.d -o CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.o -c /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/matrix.cc

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/matrix.cc > CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.i

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/matrix.cc -o CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.s

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/flags.make
CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.o: ../src/model/reader.cc
CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.o -MF CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.o.d -o CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.o -c /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/reader.cc

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/reader.cc > CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.i

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/reader.cc -o CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.s

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/flags.make
CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.o: ../src/model/data.cc
CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.o: CMakeFiles/s21_MultilayerPerceptron.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.o -MF CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.o.d -o CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.o -c /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/data.cc

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/data.cc > CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.i

CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lymondgl/Desktop/s21_MultilayerPerceptron/src/model/data.cc -o CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.s

CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.o: CMakeFiles/s21_MultilayerPerceptron.dir/flags.make
CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.o: ../main.cpp
CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.o: CMakeFiles/s21_MultilayerPerceptron.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.o -MF CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.o.d -o CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.o -c /Users/lymondgl/Desktop/s21_MultilayerPerceptron/main.cpp

CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lymondgl/Desktop/s21_MultilayerPerceptron/main.cpp > CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.i

CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lymondgl/Desktop/s21_MultilayerPerceptron/main.cpp -o CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.s

# Object files for target s21_MultilayerPerceptron
s21_MultilayerPerceptron_OBJECTS = \
"CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.o" \
"CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.o" \
"CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.o" \
"CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.o" \
"CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.o" \
"CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.o" \
"CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.o" \
"CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.o"

# External object files for target s21_MultilayerPerceptron
s21_MultilayerPerceptron_EXTERNAL_OBJECTS =

s21_MultilayerPerceptron: CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_matrix.cpp.o
s21_MultilayerPerceptron: CMakeFiles/s21_MultilayerPerceptron.dir/src/matrix/s21_support_func.cc.o
s21_MultilayerPerceptron: CMakeFiles/s21_MultilayerPerceptron.dir/src/model/neuron.cc.o
s21_MultilayerPerceptron: CMakeFiles/s21_MultilayerPerceptron.dir/src/model/graph_network.cc.o
s21_MultilayerPerceptron: CMakeFiles/s21_MultilayerPerceptron.dir/src/model/matrix.cc.o
s21_MultilayerPerceptron: CMakeFiles/s21_MultilayerPerceptron.dir/src/model/reader.cc.o
s21_MultilayerPerceptron: CMakeFiles/s21_MultilayerPerceptron.dir/src/model/data.cc.o
s21_MultilayerPerceptron: CMakeFiles/s21_MultilayerPerceptron.dir/main.cpp.o
s21_MultilayerPerceptron: CMakeFiles/s21_MultilayerPerceptron.dir/build.make
s21_MultilayerPerceptron: CMakeFiles/s21_MultilayerPerceptron.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable s21_MultilayerPerceptron"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/s21_MultilayerPerceptron.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/s21_MultilayerPerceptron.dir/build: s21_MultilayerPerceptron
.PHONY : CMakeFiles/s21_MultilayerPerceptron.dir/build

CMakeFiles/s21_MultilayerPerceptron.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/s21_MultilayerPerceptron.dir/cmake_clean.cmake
.PHONY : CMakeFiles/s21_MultilayerPerceptron.dir/clean

CMakeFiles/s21_MultilayerPerceptron.dir/depend:
	cd /Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lymondgl/Desktop/s21_MultilayerPerceptron /Users/lymondgl/Desktop/s21_MultilayerPerceptron /Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug /Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug /Users/lymondgl/Desktop/s21_MultilayerPerceptron/cmake-build-debug/CMakeFiles/s21_MultilayerPerceptron.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/s21_MultilayerPerceptron.dir/depend

