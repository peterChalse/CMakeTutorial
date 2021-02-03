cmake_minimum_required(VERSION 3.1)

# set the project name
project(Tutorial VERSION 1.0)
# add the executable

#step1. Specify the C++ Standard
#The easiest way to enable support for a specific C++ standard in CMake is by using the CMAKE_CXX_STANDARD variable. 
#For this tutorial, set the CMAKE_CXX_STANDARD variable in the CMakeLists.txt file 
#to 11 and CMAKE_CXX_STANDARD_REQUIRED to True. 
#Make sure to add the CMAKE_CXX_STANDARD declarations above the call to add_executable.
# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(TutorialConfig.h.in TutorialConfig.h)

add_executable(Tutorial tutorial.cxx)

#Since the configured file will be written into the binary tree, 
#we must add that directory to the list of paths to search for include files. 
#Add the following lines to the end of the CMakeLists.txt file:
target_include_directories(Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}"
)