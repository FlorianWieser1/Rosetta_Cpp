// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#include "Uniform.hh"
#include <cstdlib>

Uniform::Uniform():
	seed_(0) // Clear, for consistent starting state
{}

Uniform::~Uniform() {}

void Uniform::setSeed(int const seed) { seed_ = seed; srand( seed_ ); }

int Uniform::getSeed() { return seed_; }

// oh no! This class is communicating with global state of the program
// via this call to the C-provided random number generator. This code
// is not threadsafe for this reason. Fortunately, we are not going to
// be using multiple threads in this program. This code, however, would
// be dangerous to put into Rosetta.
double Uniform::getRandom() { return (double)rand() / (double)RAND_MAX; }

