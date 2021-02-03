#include <cmath>
//step1 / Specify the C++ Standard
//Next let’s add some C++11 features to our project by replacing atof with std::stod in tutorial.cxx. 
//At the same time, remove #include <cstdlib>.
//#include <cstdlib>
#include <iostream>
#include <string>
#include "TutorialConfig.h" //step1 / Adding a Version Number and Configured Header File

int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  //const double inputValue = atof(argv[1]); 
  const double inputValue = std::stod(argv[1]); //step1 / Specify the C++ Standard

  // calculate square root
  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
