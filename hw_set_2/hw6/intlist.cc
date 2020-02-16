#include <iostream>
#include <???>

// In this lab, you will create an instance of an STL list of integers and call several functions on
// this list.
//
// "STL" is for Stanard Template Library.  The type of the class you're instantiating is
// templated on "integer" - there are basically two aspects of being an integer list: 1) being
// a list with lots of functionality to append and delete items from the list that has nothing
// to do with integers, and 2) holding integers.  Using templates, the STL can provide all the
// complicated functionality for part 1) and leave it to you the user to tell it what it should
// hold for part 2).
//
// What should you do here?
//
// 1. Declare an instance of an integer list named "mylist."  You will need to replace the
// #include <???> above with the correct C++ file so that you can declare a list.  Google for
// "STL list c++" and you'll find the name of the correct file.  Now, the list class lives
// in namespace "std" (think "standard" instead of some other thing those three letters might
// suggest).  In order to use or declare a class that lives in a particular namespace, you
// have to provide the appropriate namespace scope.  That is, you will have to put "std::"
// in front of the name of the class (the class's name is "list", btw.).  Try to compile
// the code that simply declares the variable before going on to step 2.
//
// 2. Append 10 integers, 1..10, to the list with the help of a for loop.
//
// 3. Starting from the beginning of the list, iterate across all of its elements and
// write them to the screen.  Your code will look something like this:
//    std::cout << "Forwards iteration" << std::endl;
//    for ( XXX::const_iterator iter = mylist.YYY; iter != mylist.ZZZ; ++iter ) {
//       std::cout << "Next element: " << *iter << std::endl;
//    }
//    std::cout << "Done!" << std::endl;
// where you will fill in XXX, YYY, and ZZZ.  XXX is the name of your class, and YYY and ZZZ
// are class member functions and parentheses.
//
// 4. Starting from the end of the list, iterate backwards across all of its elements and
// write them to the screen.  Your code will look something like this:
//    std::cout << "Backwards iteration" << std::endl;
//    for ( XXX::const_reverse_iterator iter = mylist.YYY; iter != mylist.ZZZ; ++iter ) {
//       std::cout << "Next element: " << *iter << std::endl;
//    }
//    std::cout << "Done!" << std::endl;

int main() {

  std::cout << "Here we go!" << std::endl;

  // your code goes here

  return 0;
}
