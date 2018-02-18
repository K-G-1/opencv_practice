# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/kg/Soft/opencv_practice/two_value

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kg/Soft/opencv_practice/two_value

# Include any dependencies generated for this target.
include CMakeFiles/opencv_two_value.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opencv_two_value.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opencv_two_value.dir/flags.make

CMakeFiles/opencv_two_value.dir/two-value.cpp.o: CMakeFiles/opencv_two_value.dir/flags.make
CMakeFiles/opencv_two_value.dir/two-value.cpp.o: two-value.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kg/Soft/opencv_practice/two_value/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opencv_two_value.dir/two-value.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_two_value.dir/two-value.cpp.o -c /home/kg/Soft/opencv_practice/two_value/two-value.cpp

CMakeFiles/opencv_two_value.dir/two-value.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_two_value.dir/two-value.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kg/Soft/opencv_practice/two_value/two-value.cpp > CMakeFiles/opencv_two_value.dir/two-value.cpp.i

CMakeFiles/opencv_two_value.dir/two-value.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_two_value.dir/two-value.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kg/Soft/opencv_practice/two_value/two-value.cpp -o CMakeFiles/opencv_two_value.dir/two-value.cpp.s

CMakeFiles/opencv_two_value.dir/two-value.cpp.o.requires:

.PHONY : CMakeFiles/opencv_two_value.dir/two-value.cpp.o.requires

CMakeFiles/opencv_two_value.dir/two-value.cpp.o.provides: CMakeFiles/opencv_two_value.dir/two-value.cpp.o.requires
	$(MAKE) -f CMakeFiles/opencv_two_value.dir/build.make CMakeFiles/opencv_two_value.dir/two-value.cpp.o.provides.build
.PHONY : CMakeFiles/opencv_two_value.dir/two-value.cpp.o.provides

CMakeFiles/opencv_two_value.dir/two-value.cpp.o.provides.build: CMakeFiles/opencv_two_value.dir/two-value.cpp.o


# Object files for target opencv_two_value
opencv_two_value_OBJECTS = \
"CMakeFiles/opencv_two_value.dir/two-value.cpp.o"

# External object files for target opencv_two_value
opencv_two_value_EXTERNAL_OBJECTS =

opencv_two_value: CMakeFiles/opencv_two_value.dir/two-value.cpp.o
opencv_two_value: CMakeFiles/opencv_two_value.dir/build.make
opencv_two_value: /opt/ros/kinetic/lib/libopencv_stitching3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_superres3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_videostab3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_aruco3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_bgsegm3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_bioinspired3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_ccalib3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_cvv3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_dpm3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_face3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_fuzzy3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_hdf3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_img_hash3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_line_descriptor3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_optflow3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_reg3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_rgbd3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_saliency3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_stereo3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_structured_light3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_surface_matching3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_tracking3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_xfeatures2d3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_ximgproc3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_xobjdetect3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_xphoto3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_shape3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_photo3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_calib3d3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_viz3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_phase_unwrapping3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_video3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_datasets3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_plot3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_text3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_dnn3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_features2d3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_flann3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_highgui3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_ml3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_videoio3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_imgcodecs3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_objdetect3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_imgproc3.so.3.3.1
opencv_two_value: /opt/ros/kinetic/lib/libopencv_core3.so.3.3.1
opencv_two_value: CMakeFiles/opencv_two_value.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kg/Soft/opencv_practice/two_value/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opencv_two_value"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_two_value.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opencv_two_value.dir/build: opencv_two_value

.PHONY : CMakeFiles/opencv_two_value.dir/build

CMakeFiles/opencv_two_value.dir/requires: CMakeFiles/opencv_two_value.dir/two-value.cpp.o.requires

.PHONY : CMakeFiles/opencv_two_value.dir/requires

CMakeFiles/opencv_two_value.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opencv_two_value.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opencv_two_value.dir/clean

CMakeFiles/opencv_two_value.dir/depend:
	cd /home/kg/Soft/opencv_practice/two_value && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kg/Soft/opencv_practice/two_value /home/kg/Soft/opencv_practice/two_value /home/kg/Soft/opencv_practice/two_value /home/kg/Soft/opencv_practice/two_value /home/kg/Soft/opencv_practice/two_value/CMakeFiles/opencv_two_value.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv_two_value.dir/depend
