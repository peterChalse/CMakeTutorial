cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial VERSION 1.0)
# add the executable

list (APPEND CMAKE_MODULE_PATH  ${PROJECT_SOURCE_DIR}/build-tools/cmake)
message(STATUS "[info/root] CMAKE_MODULE_PATH : ${CMAKE_MODULE_PATH}")


#step1. Specify the C++ Standard
#The easiest way to enable support for a specific C++ standard in CMake is by using the CMAKE_CXX_STANDARD variable. 
#For this tutorial, set the CMAKE_CXX_STANDARD variable in the CMakeLists.txt file 
#to 11 and CMAKE_CXX_STANDARD_REQUIRED to True. 
#Make sure to add the CMAKE_CXX_STANDARD declarations above the call to add_executable.
# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Adding a Library (Step 2)
#Now let us make the MathFunctions library optional.
option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file(TutorialConfig.h.in TutorialConfig.h)

#Adding a Library (Step 2)
#The next change is to make building and linking the MathFunctions library conditional. 
#To do this we change the end of the top-level CMakeLists.txt file to look like the following:


#Adding a Library (Step 2)
#To make use of the new library we will add an add_subdirectory() call in the top-level CMakeLists.txt file 
#so that the library will get built. 
#We add the new library to the executable, and add MathFunctions as an include directory 
#so that the mqsqrt.h header file can be found. 

if(USE_MYMATH)
    # add the MathFunctions library
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions) # library path

    #Adding Usage Requirements for Library (Step 3)
    #list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions") # headerfile path
endif()

add_executable(Tutorial tutorial.cxx)

#target_link_libraries(Tutorial PUBLIC MathFunctions)
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

##Since the configured file will be written into the binary tree, 
##we must add that directory to the list of paths to search for include files. 
##Add the following lines to the end of the CMakeLists.txt file:
#target_include_directories(Tutorial PUBLIC
#    "${PROJECT_BINARY_DIR}"
#)


#Adding a Library (Step 2)
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}" #TutorialConfig.h
                          #Adding Usage Requirements for Library (Step 3)
                          #${EXTRA_INCLUDES} #"${PROJECT_SOURCE_DIR}/MathFunctions" #MathFunctions/MathFunctions.h
                          )

#Installing and Testing (Step 4)
install(TARGETS Tutorial DESTINATION ~/temp/bin) #그냥 bin : /usr/local/bin을 의미. 설치가 안됨. 권한이 없어서??
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" 
                            DESTINATION ~/temp/include #그냥 include : /usr/local/include. 
                            )


include(BuildTest)