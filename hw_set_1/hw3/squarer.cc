#include <iostream>

// Your assignment is to write a function that takes a float and returns a float
// and the float that it returns should be the square of the input float.
// The name of this function must be "square" so that the code in main() below
// runs succesfully.

int main() {

  std::cout << "Enter a number: ";

  float number;
  std::cin >> number;
  std::cout << "The square of " << number << " is: " << square( number ) << std::endl;

  return 0;
}
