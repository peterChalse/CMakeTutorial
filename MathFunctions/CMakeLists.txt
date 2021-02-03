#Adding a Library (Step 2)
add_library(MathFunctions mysqrt.cxx)

#Adding Usage Requirements for Library (Step 3)

#We first state that 
#anybody linking to MathFunctions needs to include the current source directory, 
#while MathFunctions itself doesn’t. So this can become an INTERFACE usage requirement.

#Remember INTERFACE means things that consumers require but the producer doesn’t. 
#Add the following lines to the end of MathFunctions/CMakeLists.txt:
#[comme] consumer : source code, producer : MathFunction library
target_include_directories(MathFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
#Now that we’ve specified usage requirements for 
#MathFunctions we can safely remove our uses of the EXTRA_INCLUDES variable from the top-level CMakeLists.txt, here:


#Installing and Testing (Step 4)
#for MathFunctions we want to install the library and header file and 
#for the application we want to install the executable and configured header.
install(TARGETS MathFunctions DESTINATION ~/temp/lib)
install(FILES MathFunctions.h DESTINATION ~/temp/include)