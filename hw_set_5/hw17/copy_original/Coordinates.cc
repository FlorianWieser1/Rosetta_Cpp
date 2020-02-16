// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

/// This Coordinates class contains three double numbers, x_, y_, z_,
/// which are used to describe the coordinates of a point in 3-D dimension.
/// Users can set and modify x_ and y_, and calculate z_, according certain Function.
/// In this exercise, we are only dealing with three functions

#include <string>
#include <iostream>
#include <stdexcept>
#include "Landscape.hh"
#include "Coordinates.hh"

using namespace std;

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

// Default constructor for Coordinate class 
Coordinates::Coordinates() {}

// Constructor
Coordinates::Coordinates( string fxn )
{
	set_landscape_function( fxn );
	this->update_z();
}

// Copy constructor
Coordinates::Coordinates(Coordinates & src)
{
	cout << "copy constructor called" << endl;
	landscape_ = src.landscape_;
	landscape_function_name_ = src.landscape_function_name_;
	x_ = src.x_;
	y_ = src.y_;
	z_ = src.z_;
	src.update_z();
}

// Destructor
Coordinates::~Coordinates() {}

// getters and setters
double Coordinates::get_x() { return x_; };
double Coordinates::get_y() { return y_; };
double Coordinates::get_z() { return z_; };
string const & Coordinates::get_landscape_function_name() { return landscape_function_name_; };

void Coordinates::set_x( double x ) { x_ = x; update_z(); };
void Coordinates::set_y( double y ) { y_ = y; update_z(); };

// modifiers
void Coordinates::modify_x( double delta ) { x_ += delta; update_z(); };
void Coordinates::modify_y( double delta ) { y_ += delta; update_z(); };

// functions
void Coordinates::update_z()
{
	z_ = landscape_->calculate_z( x_, y_ );
}


