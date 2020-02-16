#include <iostream>

// In this assignment, you will write the iterative version of the Fibonacci function.
// In this function, you will allocate an array using "new", compute and save a result,
// and then delete the array using "delete []".  (You must use new and delete).
//
// So what do you compute?
// Well, solving for the ith Fibonacci number means your recursive algorithm had to
// call fib(3) many many times before it completed.  What if you could solve
// fib(3) once and store the result?  Well, you can!  In fact, you don't even need
// to look at the result of fib(3) very many times: only when computing fib(4) and
// fib(5).
//
// So your new function will start by allocating an array of n+1 integers (where n
// is the index of the Fibonacci number you need to compute.)  Then you'll set the
// values for positions [1] and [2] in the array to 1.  Then you will write a for
// loop that iterates from 3 to n.  The value you store in position i in the array
// is then the sum of the i-1st and i-2nd positions. When the loop completes, the
// nth position in the array holds the nth Fibonacci number. BOOM! Your done.
// Save the value of the nth position in an integer.  Deallocate the array.
// Return the saved value.
//
// Does this version get the same answers as your other version? How does the running 
// time compare to your recursive implementation?  Write similar time measurement
// code as that which you wrote for hw4.  How does the running time for this function
// scale as a function of the input parameter?  (i.e. Is there a polynomial that
// describes the running time, and if so, what degree is this polynomial?)

int main() {
  std::cout << "Enter the nth Fibonacci number you would like: ";

  int which;
  std::cin >> which;

  std::cout << "The " << which << "th Fibonacci number is: " << fib( which ) << std::endl;
  return 0;
}
