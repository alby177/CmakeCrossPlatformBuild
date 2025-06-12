#include <iostream>

auto sum(int a, int b)
{
  return a + b;
}

int main(int argc, char** argv)
{
  std::cout << "We are on a " << CMAKEPROVA << " machine" << std::endl;
  std::cout << sum(8, 5) << std::endl;
  return 0;
}
