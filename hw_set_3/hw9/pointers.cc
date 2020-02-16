#include <iostream>
#include <string>

// In this exercise, you will be working with pointers.  There are only six lines of code
// that you will be writing, but in addition, you will need to explain what is happening to
// value pointed to by the "myint" pointer.
//
// Here are the lines of code you'll need to change.
// 1. Null pointer check; write code on this line to make sure that you do not try to access
// invalid memory addresses.  The "0" address is flagged as an invalid address, and if you
// try to de-reference a pointer (that is, to use the * operator ) when that pointer holds the
// value 0, then the program will segfault.
// 2. Memory allocation; write code on this line to create a new integer instance.
// 3. Function invocation on pointer objects; write code on this line to call the increment function
// on the inc1 pointer.
// 4. & 5. Same as 3, but for inc2 and inc3.
// 6. Memory deallocation; write code below this line to delete the four pieces of memory that
// were allocated inside of main.

// Run this program and give the value "10" when prompted.
// A. What is the value printed on the output line that starts with "END"?
// B. Where did that value come from?
// C. What does inc2 do?
// Provide your answers here.

class Incrementer {
public:
  Incrementer( std::string const & name, int * intptr ) :
    name_( name ),
    intptr_( intptr )
  {}

  void increment() {
    std::cout << name_ << " call to increment; ";
    if ( /* write code here to make sure that if intptr_ is 0, to skip the block below */ ) {   // 1.
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
  int * myint = /* write code here to allocate a new integer */; // 2.
  std::cout << "Please enter an integer: ";
  std::cin  >> *myint; /* note, this code will segfault if you haven't allocated an integer above */
  std::cout << std::endl;

  Incrementer * inc1 = new Incrementer( "inc1", myint );
  Incrementer * inc2 = new Incrementer( "inc2", 0     );
  Incrementer * inc3 = new Incrementer( "inc3", myint );

  std::cout << "START " << *myint << std::endl;

  // 3. call increment on inc1
  // 4. call increment on inc2
  // 5. call increment on inc3

  std::cout << "END " << *myint << std::endl;

  /* write code here to deallocate myint, inc1, inc2, and inc3 so that you do not leak memory */ // 6.

  return 0;
}
