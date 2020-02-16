#include <iostream>
#include <cstdlib> 
#include <string> 

using namespace std;

void add ( int first_argument, int second_argument, int &result )
{
    result = first_argument + second_argument; 
}

void subtract ( int first_argument, int second_argument, int &result )
{
    result = first_argument - second_argument;
}


int main( int argc, char *argv[] ) {

	// Pull String args
	int first_arg = atoi(argv[1]);
	int second_arg = atoi(argv[3]); 
	std::string operator_arg = argv[2];

	// 1. Initialize a new integer variable, result, to 0.  This variable
	// will be passed by reference into the functions you will write. 
    int result = 0;

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
