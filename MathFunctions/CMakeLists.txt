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
          PRIVATE ${CMAKE_BINARY_DIR}
          )
#Now that we’ve specified usage requirements for 
#MathFunctions we can safely remove our uses of the EXTRA_INCLUDES variable from the top-level CMakeLists.txt

#Adding System Introspection (Step 5)
#We’re going to use the new defines in TutorialConfig.h.in, 
#so be sure to set them before that file is configured.
# does this system provide the log and exp functions?
include(CheckSymbolExists)
message(STATUS "[info/MathFunctions] check_symbol_exists step0")
check_symbol_exists(log "math.h" HAVE_LOG)
message(STATUS "[info/MathFunctions] check_symbol_exists step1")
check_symbol_exists(exp "math.h" HAVE_EXP)
message(STATUS "[info/MathFunctions] check_symbol_exists step2")
message(STATUS "[info/MathFunctions] HAVE_LOG : ${HAVE_LOG}, HAVE_EXP : ${HAVE_EXP}")
if(NOT (HAVE_LOG AND HAVE_EXP))
  unset(HAVE_LOG CACHE)
  unset(HAVE_EXP CACHE)
  set(CMAKE_REQUIRED_LIBRARIES "m")
  check_symbol_exists(log "math.h" HAVE_LOG)
  check_symbol_exists(exp "math.h" HAVE_EXP)
  message(STATUS "[info/MathFunctions] inside loop. HAVE_LOG : ${HAVE_LOG}, HAVE_EXP : ${HAVE_EXP}")
  if(HAVE_LOG AND HAVE_EXP)
    target_link_libraries(MathFunctions PRIVATE m)
  endif()
endif()

# add compile definitions
if(HAVE_LOG AND HAVE_EXP)
  target_compile_definitions(MathFunctions
                             PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()


#Installing and Testing (Step 4)
#for MathFunctions we want to install the library and header file and 
#for the application we want to install the executable and configured header.
install(TARGETS MathFunctions DESTINATION ~/temp/lib)
install(FILES MathFunctions.h DESTINATION ~/temp/include)