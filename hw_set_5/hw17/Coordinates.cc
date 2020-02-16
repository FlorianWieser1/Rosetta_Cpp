// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

/// This Coordinates class contains three double numbers, x_, y_, z_,
/// which are used to describe the coordinates of a point in 3-D dimension.
/// Users can set and modify x_ and y_, and calculate z_, according certain Function.
/// In this exercise, we are only dealing with three functions

#include <iostream>
#include <stdexcept>
#include "Landscape.hh"
#include "Coordinates.hh"


// We have already implemented this function for you. You should invoke
// this function in the constructor.
void
Coordinates::set_landscape_function(std::string new_function) {

	landscape_function_name_ = new_function;

	if ( landscape_function_name_ == "sum_squares" ) {
		landscape_ = std::shared_ptr<Landscape> ( new SumSquares() );
	} else if ( landscape_function_name_ == "rastrigin" ) {
		landscape_ = std::shared_ptr<Landscape> ( new Rastrigin() );
	} else if ( landscape_function_name_ == "ackley" ) {
		landscape_ = std::shared_ptr<Landscape> ( new Ackley() );
	} else {
		throw std::invalid_argument( "The function '" + new_function + "' hasn't been defined! Valid options are 'sum_squares', 'rastrigin', and 'ackley'" );
	}
}

// TO DO -- Write the methods for class Coordinates below.
