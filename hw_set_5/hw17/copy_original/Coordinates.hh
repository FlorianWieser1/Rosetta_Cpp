// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

/// This Coordinates class contains three double numbers, x_, y_, z_,
/// which are used to describe the coordinates of a point in 3-D dimension.
/// Users can set and modify x_ and y_, which should trigger a calculation
/// of z_, using the perscribed Function.

#ifndef INCLUDED_Coordinates_hh
#define INCLUDED_Coordinates_hh

#include <iostream>
#include <stdexcept>
#include <memory>
#include "Landscape.hh"

///// This part is the declarations of the Coordinates Class /////
///// The only code you have to write in this file are the delcarations of member variables

class Coordinates {

public:
	// Default constructor for Coordinates class
	// TO DO: Implement this function in Coordinates.cc
	Coordinates();

	// Constructor with input Landscape function name,
	// currently, there are only three choices: "sum_squares", "ackley", and "rastrigin"
	// TO DO: Implement this function in Coordinates.cc
	Coordinates(std::string fxn);

	// Copy constructor
	// This constructor must copy all member variables from the "src" object, to the
	// Coordinates object being created by this constructor. Make sure that no data members
	// are skipped. For the "landscape_" data member, a shallow copy of the pointer itself
	// is ok.
	// TO DO: Implement this function in Coordinates.cc
	Coordinates(Coordinates & src);

	// Destructor. The destructor must be implemented in the .cc file, even though it will be
	// empty -- litterally, the function body will be "{}"
	// TO DO: Implement this function in Coordinates.cc
	~Coordinates();

	// X Getters and setters
	// TO DO: Implement this function in Coordinates.cc
	double get_x();

	// Changes x and recalculates z
	// TO DO: Implement this function in Coordinates.cc
	void set_x(double x);

	// Modify the stored X value by adding "delta" to it, and recalculate z
	// TO DO: Implement this function in Coordinates.cc
	void modify_x(double delta);

	// Y Getters and setters
	// TO DO: Implement this function in Coordinates.cc
	double get_y();
	// Changes y and recalculates z
	// TO DO: Implement this function in Coordinates.cc
	void set_y(double y);
	// Modify the stored Y value by adding "delta" to it, and recalculate z
	// TO DO: Implement this function in Coordinates.cc
	void modify_y(double delta);

	// Get the z value
	// Note: we are not providing a setter function for z, because the z value is calculated from (x,y)
	// by using the update_z() function;
	// The z value represents to the score of the (x,y) coordinate
	// This getter retrieves the cached z value saved in the member variable z_ :
	// The other functions in this class should make absolutely sure that
	// this member variable is updated if x or y are ever changed.
	// TO DO: Implement this function in Coordinates.cc
	double get_z();

	// Get/set a string representing the landscape function. We instantiate the appropriate function
	// to calculate the z value/score from this string name.
	// The implementation of this function has already been provided for you in Coordinates.cc
	void set_landscape_function(std::string new_function);

	// Get the name of the landscape function
	// TO DO: Implement this function in Coordinates.cc
	std::string const & get_landscape_function_name();

protected:
	// Update the stored z value (score) using the landscape energy function
	// TO DO: Implement this function in Coordinates.cc
	void update_z();

private:
	std::shared_ptr<Landscape> landscape_;
	std::string landscape_function_name_;
	double x_;
	double y_;
	double z_;

	// TODO for you: declare the additional class member variables you use here.
	// You will want to store the x and y coordinates and the "z" value returned by
	// the landscape_ object

};

#endif
