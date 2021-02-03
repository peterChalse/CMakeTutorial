#Adding a Custom Command and Generated File (Step 6)
#First, at the top of MathFunctions/CMakeLists.txt, 
#the executable for MakeTable is added as any other executable would be added.
add_executable(MakeTable MakeTable.cxx)

#Adding a Custom Command and Generated File (Step 6)
#Then we add a custom command that specifies how to produce Table.h by running MakeTable.
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
  )

#Adding a Custom Command and Generated File (Step 6)
#Next we have to let CMake know that mysqrt.cxx depends on the generated file Table.h. 
#This is done by adding the generated Table.h to the list of sources for the library MathFunctions.
#Adding a Library (Step 2)
add_library(MathFunctions 
            mysqrt.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/Table.h)#Adding a Custom Command and Generated File (Step 6)

#Adding Usage Requirements for Library (Step 3)

#We first state that 
#anybody linking to MathFunctions needs to include the current source directory, 
#while MathFunctions itself doesn’t. So this can become an INTERFACE usage requirement.

#Remember INTERFACE means things that consumers require but the producer doesn’t. 
#Add the following lines to the end of MathFunctions/CMakeLists.txt:
#[comme] consumer : source code, producer : MathFunction library
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PRIVATE ${CMAKE_CURRENT_BINARY_DIR} # Table.h
          #We also have to add the current binary directory to the list of include directories 
          #so that Table.h can be found and included by mysqrt.cxx.
          )
message(STATUS "[info/MathFunctions] CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}, CMAKE_CURRENT_BINARY_DIR : ${CMAKE_CURRENT_BINARY_DIR}")
#Now that we’ve specified usage requirements for 
#MathFunctions we can safely remove our uses of the EXTRA_INCLUDES variable from the top-level CMakeLists.txt





#Installing and Testing (Step 4)
#for MathFunctions we want to install the library and header file and 
#for the application we want to install the executable and configured header.
install(TARGETS MathFunctions DESTINATION ~/temp/lib)
install(FILES MathFunctions.h DESTINATION ~/temp/include)