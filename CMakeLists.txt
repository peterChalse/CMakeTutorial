cmake_minimum_required(VERSION 3.1)

# set the project name
project(Tutorial VERSION 1.0)
# add the executable

configure_file(TutorialConfig.h.in TutorialConfig.h)

add_executable(Tutorial tutorial.cxx)

#Since the configured file will be written into the binary tree, 
#we must add that directory to the list of paths to search for include files. 
#Add the following lines to the end of the CMakeLists.txt file:
target_include_directories(Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}"
)