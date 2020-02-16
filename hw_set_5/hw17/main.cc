// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:


//    This is the class to decide whether to accept or reject pretubed (x, y).
//
// Through this exercise, we will be familiar with putting different pieces of codes together.
// Question:
// What are the purposes of those identifiers "#ifndef xxx", "#define xxx", and "#endif",
// such as, in "Uniform.cc", "#ifndef INCLUDED_Uniform_cc", "#define INCLUDED_Uniform_cc"?
//

#include <cstdlib>
#include <cmath>
#include "MonteCarlo.hh"
#include "Uniform.hh"
#include "Coordinates.hh"
#include "run.hh"

int main(){

	// Declare a Coordinates Ojbect: xyz, and initial it with one of the three Landscape functions.
	// Current choices: "sum_squares", "ackley", "rastrigin"

	std::cout << "Please choose a landscape function (choices: sum_squares, ackley, and rastrigin): ";
	std::string function_name;
	std::cin >> function_name;

	// set up the starting x (such as 30);
	double input_x = 30;
	std::cout << "Please enter an x: ";
	std::cin >> input_x;

	// set up the starting y (such as 30);
	double input_y = 30;
	std::cout << "Please enter an y: ";
	std::cin >> input_y;

	std::cout << "Please enter an outer cycle number: ";
	int outer = 10;
	std::cin >> outer;

	std::cout << "Please enter an inner cycle number: ";
	int inner = 1000;
	std::cin >> inner;

	try {
		return run( function_name, input_x, input_y, outer, inner );
	} catch ( std::invalid_argument const & exception ) {
		std::cerr << "Caught an exception:\n" << exception.what() << std::endl;
		return 1;
	}

}
