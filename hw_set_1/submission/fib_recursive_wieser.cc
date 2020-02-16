#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int fib(int input_number) {
  if((input_number == 1) || (input_number == 2)) {
    return 1;
  }
  else {
    for(int idx = 0; idx < input_number; idx++) {
      return fib(input_number - 1) + fib(input_number - 2);
    }
  }  
}

int main() {
  std::cout << "Enter the nth Fibonacci number you would like: ";

  int which;
  std::cin >> which;

  std::cout << "The " << which << "th Fibonacci number is: " << fib( which ) << std::endl;
  
  float time_req = clock();
  for(int idx2 = 0; idx2 < 500; idx2++) {
    fib(which);
  }
  cout << "processing time (500 loops): " << (clock() - time_req) / CLOCKS_PER_SEC << endl;
  return 0;
}
