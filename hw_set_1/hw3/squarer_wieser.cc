#include <iostream>
#include <string>
using namespace std;

float square(float to_square) {
  return to_square * to_square;
}

int main() {

  std::cout << "Enter a number: ";

  float number;
  std::cin >> number;
  std::cout << "The square of " << number << " is: " << square(number) << std::endl;

  return 0;
}


