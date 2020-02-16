// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

// This program functions as a sort of integration test, and can be run to see if your implementations
// of the Coordinate and MonteCarlow classes are working. We have already run this test program
// on a working version of these classes, and saved the output into "expected_test.out". The
// test_program.sh script compares this expected output with your program's output

#include <cstdlib>
#include <cmath>
#include <vector>
#include "MonteCarlo.hh"
#include "Uniform.hh"
#include "Coordinates.hh"
#include "run.hh"

int main(){

	std::vector <std::string> function_names = { "sum_squares", "ackley", "rastrigin" };
	std::vector <double> starting_x_values = { 1.0, 10.0, 32.0, 110.0, 1300.0 };
	std::vector <double> starting_y_values = { 1.0, 10.0, 32.0, 110.0, 1300.0 };
	int outer = 10; // Outer cycles
	int inner = 1000; // Inner cycles

	Uniform uniform;
	uniform.setSeed( 0 ); // set the global seed to a constant value for reproducibility purposes

	try {

		for ( std::string function_name : function_names ) {

			// Loop through all combinations of starting x values with starting y values
			for ( double input_x : starting_x_values ) {
				for ( double input_y : starting_y_values ) {
					run(
						function_name, input_x, input_y, outer, inner,
						300 // output text from the inner loop every 300 steps
					);
				}
			}
		}
		return 0;
	} catch ( std::invalid_argument const & exception ) {
		std::cerr << "Caught an exception:\n" << exception.what() << std::endl;
		return 1;
	}
}
