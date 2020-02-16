// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:


/// The class Landscape is the parent class for a set of 3-D landscape functions.
/// useful sites: http://www.sfu.ca/~ssurjano/ackley.html
//                http://www.sfu.ca/~ssurjano/rastr.html
//                http://www.sfu.ca/~ssurjano/sumsqu.html
//                https://en.wikipedia.org/wiki/Test_functions_for_optimization

#include <cmath>
#include <iostream>
#include <memory>
#include "Landscape.hh"

using namespace std;
Landscape::Landscape() {}
Landscape::~Landscape() {}


SumSquares::SumSquares() : Landscape() {
}

SumSquares::~SumSquares() {}

double SumSquares::calculate_z(double x, double y) {
	return pow(x,2)+pow(y,2);
}

std::shared_ptr<Landscape> SumSquares::clone() {
	return std::shared_ptr<Landscape> ( new SumSquares(*this) );
}

Rastrigin::Rastrigin() : Landscape() {
}

Rastrigin::~Rastrigin() {}

double Rastrigin::calculate_z(double x, double y) {
	double pi = M_PI;
	return 20+pow((x-4),2)+pow((y-5),2)-10*(cos(2*pi*(x-4))+cos(2*pi*(y-5)));
}

std::shared_ptr<Landscape> Rastrigin::clone() {
	return std::shared_ptr<Landscape> ( new Rastrigin(*this) );
}

Ackley::Ackley() : Landscape() {
}

Ackley::~Ackley() {}

double Ackley::calculate_z(double x, double y) {
	double pi = M_PI;
	double e = exp(1.0);
	return -20*exp(-0.2*sqrt(0.5*(pow(x,2)+pow(y,2))))-exp(0.5*(cos(2*pi*x)+cos(2*pi*y))) + e + 20;
}

std::shared_ptr<Landscape> Ackley::clone() {
	return std::shared_ptr<Landscape> ( new Ackley(*this) );
}

