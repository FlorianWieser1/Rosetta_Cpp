// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#include <string>
#include <iostream>
#include "Coordinates.hh"
#include "MonteCarlo.hh"

int run(
	std::string const & function_name,
	double input_x,
	double input_y,
	int outer,
	int inner,
	int output_every_n_steps = 1 // in between however many inner steps do we output
) {

	Coordinates xy(function_name);
	xy.set_x(input_x);
	xy.set_y(input_y);

	std::cout << "The starting point: X = " << xy.get_x() << " Y = " << xy.get_y() << std::endl;
	std::cout << "The starting Z value: " << xy.get_z() << std::endl;

	// Declare and initial a MonteCarlo Ojbect: mc,
	// we initial it with the starting Coordinates xy, and temperature 0;
	// we will set the temperature before we use the Boltmann function.
	MonteCarlo mc(xy, 0);

	// set up a uniform random number generator.
	Uniform uniform_RG;

	// You can play with this step scalar.
	// This will directly related to the estimate distance between the starting point the global minimum
	float largest_possible_step = 1000;
	float smallest_possible_step = 0.01;
	float step_size;

	float high_temp = 0.1;
	float low_temp = 0.00001;
	float temperature;

	bool output_this_cycle;

	//////// This is the outer cycle for simulated annealing process ///////////
	// useful webpages: https://en.wikipedia.org/wiki/Simulated_annealing
	// https://www.rosettacommons.org/docs/latest/scripting_documentation/RosettaScripts/Movers/movers_pages/GenericSimulatedAnnealerMover
	for ( int i = 0 ; i < outer; i++ ) {

		//// What is the purpose
		temperature = (high_temp - low_temp) * std::exp(-i) + low_temp;
		mc.set_temperature(temperature);

		step_size = (largest_possible_step - smallest_possible_step) * std::exp(-i) + smallest_possible_step;

		std::cout << "================ Outer cycle #: " << i+1 << " ================" << std::endl;

		for ( int j=0 ; j < inner ; j++ ) {
			if ( j % output_every_n_steps == 0 || j+1 == inner ) {
				output_this_cycle = true;
			} else {
				output_this_cycle = false;
			}

			if (output_this_cycle) {
				std::cout << "===== Inner cycle #: " << j+1 << " =====" << std::endl;
			}

			double delta1 = uniform_RG.getRandom() - 0.5;
			double delta2 = uniform_RG.getRandom() - 0.5;
			if (output_this_cycle) {
				std::cout << "Previous X: " << xy.get_x() << " Previous Y: "<< xy.get_y() << " Previous Z: "<< xy.get_z() << std::endl;
			}

			xy.modify_x( step_size * delta1 );
			xy.modify_y( step_size * delta2 );

			bool whether_to_accept = mc.boltzmann(xy);

			if (output_this_cycle) {
				std::cout << "X changed: "<< step_size * delta1 << " Y changed: "<< step_size * delta2 << std::endl;
				std::cout << "New X: " << xy.get_x() << " New Y: " << xy.get_y() << " New Z: " << xy.get_z() << std::endl;
				std::cout << "Accept? " << whether_to_accept << std::endl;
				std::cout << "Saved X: " << xy.get_x() << " Saved Y: " << xy.get_y() << std::endl;
				std::cout << "After_boltzmann Z: " << xy.get_z() << std::endl;
			}
		}

        std::cout << "==================== The predicted global minimum for " << xy.get_landscape_function_name() << " function ===============" << std::endl;

		std::cout << "Final X: " << xy.get_x() << " Final Y: " << xy.get_y() << std::endl;
		std::cout << "Final Z: " << xy.get_z() << std::endl;
	}
	return 0;
}
