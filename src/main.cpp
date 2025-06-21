#include <iostream>
#include "GenericLibrary/GenericLibrary.h"

int main(int argc, char** argv)
{
  std::cout << "We are on a " << CMAKEPROVA << " machine" << std::endl;
  std::cout << AddNumbers(8, 5) << std::endl;
  return 0;
}
