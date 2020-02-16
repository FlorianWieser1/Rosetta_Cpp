// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#ifndef INCLUDED_Uniform_hh
#define INCLUDED_Uniform_hh

// This class generates uniform random numbers, using a seed
// For the Rosetta equivalent, see the source code in Rosetta/main/source/src/numeric/random/

// NOTE:
// Don't change the seed functionality; this will let you compare your output to the expected program output

class Uniform {
public:
	Uniform();

	~Uniform();

	void setSeed(int const seed);
	int getSeed();

	// Returns a random number in the range [0..1)
	double getRandom();

private:
	int seed_;
};

#endif
