// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#include <cstdlib>
#include <cmath>
#include "Coordinates.hh"
#include "MonteCarlo.hh"
#include "Uniform.hh"

using namespace std;


///// The following part contains the implementations of the MonteCarlo Class /////
///// TO DO: Write the implementations of functions in class MonteCarlo


// default constructor

MonteCarlo::MonteCarlo() {};

// constructors

MonteCarlo::MonteCarlo( Coordinates & xy, float temperature )
{
	last_accepted_xy_ = xy;	
	temperature_ = temperature;
}

// destructor
MonteCarlo::~MonteCarlo() {}

// getters & setters
float MonteCarlo::get_temperature() const { return temperature_; };
void MonteCarlo::set_temperature( float temp ) { temperature_ = temp; };

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

bool MonteCarlo::boltzmann(Coordinates & new_xy )
{ 
	double	p;

	if ( new_xy.get_z() < last_accepted_xy_.get_z() )
	{
		last_accepted_xy_ = new_xy;
		return 1;
	}
	else
	{
		p = exp ( - ( new_xy.get_z() - last_accepted_xy_.get_z() ) / temperature_ );
		
		if ( uniformRG_.getRandom() < p )	
		{
			last_accepted_xy_ = new_xy;
			return 1;	
		}
		else
		{
			new_xy = last_accepted_xy_;
			return 0;	
		}
	}
}

// The last Coordinates values that was accepted
Coordinates const & MonteCarlo::get_last_accepted_coordinates() const
{
	return last_accepted_xy_;
}

// The last z (score) value that was accepted
double MonteCarlo::last_accepted_z()
{
	return last_accepted_xy_.get_z(); 
}
