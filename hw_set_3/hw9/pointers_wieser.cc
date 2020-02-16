#include <iostream>
#include <string>

using namespace std;

// Run this program and give the value "10" when prompted.
// A. What is the value printed on the output line that starts with "END"?
//    printed output after END: "12"
// B. Where did that value come from?
//    The function for incrementing the input value "10" by "1" was called three times in total.
//    Since one time an instance with a NULL pointer created, the END value was just incremented two times.
//    The "myint" pointer points to a memory loaction that stores the actual value of myint.
//    New instances of Incrementer are created w/o a preceeding asterics of myint, therefore passing just the memory adress.
//    In this way the actual value of myint (*myint) can be changed directly, although set to private in Incrementer class.
// C. What does inc2 do?
//    inc2 passes a NULL pointer, which is than rejected by the if statement.

class Incrementer {
public:
  Incrementer( std::string const & name, int * intptr ) :
    name_( name ),
    intptr_( intptr )
  {}

  void increment() {
      std::cout << name_ << " call to increment; ";
    if (intptr_) {
      std::cout << "incrementing value stored at " << intptr_;
      *intptr_ = *intptr_ + 1;
      std::cout << "; new value of " << *intptr_ << std::endl;
    } else {
      std::cout << "no valid memory address to increment" << std::endl;
    }
  }

private:
  std::string name_;
  int * intptr_;

};

int main() {
  int * myint = new int;
  std::cout << "Please enter an integer: ";
  std::cin  >> *myint;
  std::cout << std::endl;

  Incrementer * inc1 = new Incrementer( "inc1", myint );
  Incrementer * inc2 = new Incrementer( "inc2", 0     );
  Incrementer * inc3 = new Incrementer( "inc3", myint );

  std::cout << "START " << *myint << std::endl;
  
  inc1 -> increment();
  (*inc2).increment();
  inc3 -> increment();

  std::cout << "END " << *myint << std::endl;

  delete myint;
  delete inc1;
  delete inc2;
  delete inc3;

  return 0;
}
