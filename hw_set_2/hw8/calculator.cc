#include <iostream>
#include <cstdlib> 
#include <string> 

using namespace std;

// Instructions: 
//
// In this assingment, you will get practice passing values by reference in C++. 
// A reference is an alias for a variable - its just a different way of accessing the data
// stored in a variable in memory. You can access a variable by reference using the "&" operator. 
//
// References have many uses. First they help to conserve memory. When you pass a variable 
// into a function, that function makes a copy of it at runtime. This can become expensive when
// passing large arrays or data strucutres. References are also helpful when writing functions. 
// A function can only return one value, but sometimes you might want to modify a pair of values at
// once. You can then write a void-returning function in which both results are passed by reference
// as arguments to the functions. 
//
// In this homework, you wrill write a simple calculator that **only** works with
// values passed by reference. This will give you practice writing functions
// that take and modify these references. 
//
// Write code where it is specified. Do not modify any code in the "do not modify blocks"
// Start with "1.", found in the body of the main function below.

// 2. Write add function here.
// This function will take two integer arguments and a third integer reference argument.
// The function should compute the sum of the first two arguments and store the value
// in the third argument.  It should return void.



// 3. Write subtract function here.
// Again, this function should take two integer arguments and a third integer reference argument.
// The function should compute the difference of the first two arguments and store the value
// in the third argument.  It should return void.



// 4.
// Instead of prompting the user for input, this program will read from the command line.
// If you use the following g++ command to compile the program:
// > g++ -o cacluator.g++ calculator.cc
// Then you should test your program with the following two commands
// > ./calculator.g++ 50 + 3
// > ./calculator.g++ 14 - 12
// Does it give you the results you would expect?



int main( int argc, char *argv[] ) {

	// Pull String args
	int first_arg = atoi(argv[1]);
	int second_arg = atoi(argv[3]); 
	std::string operator_arg = argv[2];

	// 1. Initialize a new integer variable, result, to 0.  This variable
	// will be passed by reference into the functions you will write.

	///// DO NOT MODIFY CODE BELOW THIS LINE!!! //////

	// Pick a method
	if ( operator_arg.compare("+") == 0 ) {

		add( first_arg, second_arg, result );
	
	} else if ( operator_arg.compare("-") == 0 ) {
	
		subtract( first_arg, second_arg, result ); 
	
	}

	// Print the result
	std::cout << "Result: " << result << std::endl;

	return 0; 
}
