// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#ifndef INCLUDED_Landscape_hh
#define INCLUDED_Landscape_hh

/// The class Landscape is the parent class for a set of 3-D landscape functions.
/// useful sites: http://www.sfu.ca/~ssurjano/ackley.html
//                http://www.sfu.ca/~ssurjano/rastr.html
//                http://www.sfu.ca/~ssurjano/sumsqu.html
//                https://en.wikipedia.org/wiki/Test_functions_for_optimization

#include <cmath>
#include <iostream>
#include <memory>

class Landscape;
//////////  Abstract base class
class Landscape {
public:

	Landscape();
	virtual ~Landscape();

	virtual double calculate_z(double x, double y) = 0;

	virtual std::shared_ptr<Landscape> clone() = 0;

};

//////////  A derived class: SumSquares function
//////////  function: z = x^2 + y^2
//////////  the global minimum will be x = 0, y = 0, z = 0;
class SumSquares: public Landscape {
public:
	SumSquares();
	virtual ~SumSquares();

	virtual double calculate_z(double x, double y);

	virtual std::shared_ptr<Landscape> clone();

};

//////////  A derived class: Rastrigin function
//////////  function: z = 20 + (x-4)^2 + (y-5)^2 - 10( cos(2pi(x-4))+cos(2pi(y-5)) );
//////////  the global minimum will be x = 4, y = 5, z = 0;
class Rastrigin: public Landscape {
public:
	Rastrigin();
	virtual ~Rastrigin();

	double calculate_z(double x, double y);

	virtual std::shared_ptr<Landscape> clone();

};

//////////  A derived class: Ackley function
//////////  function: z =  -20*exp(-0.2*sqrt(0.5*(x^2+y^2)))-exp(0.5*(cos(2*pi*x)+cos(2*pi*y))) + e + 20;
//////////  the global minimum will be x = 0, y = 0, z = 0;
class Ackley: public Landscape {
public:
	Ackley();
	virtual ~Ackley();

	double calculate_z(double x, double y);

	virtual std::shared_ptr<Landscape> clone();

};

#endif
