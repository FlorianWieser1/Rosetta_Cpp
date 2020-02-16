// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#ifndef INCLUDED_MonteCarlo_hh
#define INCLUDED_MonteCarlo_hh

#include "Coordinates.hh"
#include "Uniform.hh"

///// This part is the declarations of the MonteCarlo Class /////
///// The only code you have to write in this file are delcarations of member variables
///// You will need at least two variables. One of their names will be last_accepted_xy_.
///// You will need to figure out the name and purpose of the other member variable(s?).

class MonteCarlo {
public:
	MonteCarlo();

	// Constructor
	// Usage: MonteCarlo mc( xy, temp );
	// TO DO: Implement this function in MonteCarlo.cc
	MonteCarlo( Coordinates & xy, float temperature );

	// TO DO: Implement this function in MonteCarlo.cc
	~MonteCarlo();

	// Get/Set the stored temperature factor used in the boltzmann calculation
	// TO DO: Implement this function in MonteCarlo.cc
	void set_temperature( float temp );

	// Return the temperature factor
	// TO DO: Implement this function in MonteCarlo.cc
	float get_temperature() const;

	// The bolztmann function below is the workhorse for MonteCarlo Class
	// This function compares the z values of the new Coordinates "new_xy" and the stored Coordinates "last_accepted_xy_".
	//
	// Behavior:
	// If the "new_xy" has a lower z (score), the function will always accept the new_xy
	// If the "new_xy" has a higher z (score), the function will still sometimes accept the "new_xy" with a
	// probability given by the Metropolis criterion:
	// p = exp( -(deltaZ/temperature) )
	// where deltaZ is defined to be positive if new_xy has a larger z value than last_accepted_xy_.
	// The higher the temperature, the easier to accept higher z values.
	// (You may wonder where the "k" in "kT" went. Consider k to be rolled into the temperature.)
	// After computing p, you will sample from the uniform distribution between 0 and 1; if your
	// random number is less than p, accept the new coordinate.
	//
	// If the "new_xy" coordinate is accepted, the stored "last_accepted_xy_" must be set to this new value, and return true.
	// If the new coordinate "new_xy" is rejected, the passed-in "new_xy" coordinate will be overwritten with the stored
	// "last_accepted_xy_" value, and false will be returned. I.e. the proposed perturbation will be rejected.
	// TO DO: implement this function in MonteCarlo.cc
	bool boltzmann(Coordinates & new_xy);

	// The last Coordinates value that was accepted
	// TO DO: implement this function in MonteCarlo.cc
	Coordinates const & get_last_accepted_coordinates() const;

	// The last z (score) value that was accepted
	// TO DO: implement this function in MonteCarlo.cc
	double last_accepted_z();

private:
	Uniform uniformRG_; // You shouldn't need to do anything in MonteCarlo.cc to initialize this - just use it!
	double temperature_;
	Coordinates last_accepted_xy_;
	double last_accepted_z_;
	double p;

	// TODO for you: declare the additional class member variables you use here

};

#endif
