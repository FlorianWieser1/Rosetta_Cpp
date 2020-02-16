// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
// You can ignore the two lines aboive: they're commands to the text editor to control how text displays.
// You'll get used to them with Rosetta code.

#include <iostream>
#include <string>
#include <vector> //HINT

using namespace std;

//This is the PARENT CLASS.  You won't be using it directly.  Don't
//try to instantiate it. (you can't, because of the funny = 0
//function, called a "pure virtual")
class MathlikeOperator {
public:

  std::string const & name() const { return name_; }

  virtual int operate_on(int input) const = 0;

protected: //don't worry about protected just yet
  MathlikeOperator( std::string const & name ) : name_(name) {}

private:
  std::string name_;

};

class Squarer : public MathlikeOperator { //This is where the inheritance happens.
public:

  //since name_ is actually stored in the parent class, we have to set
  //it in the contructor by passing it up to the MathlikeOperator
  //contstructor.
  Squarer() : MathlikeOperator("SQUARER") {}

  virtual int operate_on(int input) const { return (input * input); }

  //notice this class does not define name() - it's using its parent's!

};

class Doubler : public MathlikeOperator { //This is where the inheritance happens.
public:

  //since name_ is actually stored in the parent class, we have to set
  //it in the contructor by passing it up to the MathlikeOperator
  //contstructor.
  Doubler() : MathlikeOperator("DOUBLER") {}

  virtual int operate_on(int input) const { return (input + input); }

  //notice this class does not define name() - it's using its parent's!

};

class Cuber : public MathlikeOperator { //This is where the inheritance happens.
public:

  //since name_ is actually stored in the parent class, we have to set
  //it in the contructor by passing it up to the MathlikeOperator
  //contstructor.
  Cuber() : MathlikeOperator("CUBER") {}

  virtual int operate_on(int input) const { return (input * input * input); }

  //notice this class does not define name() - it's using its parent's!

};

int main() {

  //Looping over integers approach	
	cout << "looping over the integers approach: " << endl;
	MathlikeOperator * squarer = new Squarer;
	MathlikeOperator * doubler = new Doubler;
	MathlikeOperator * cuber = new Cuber;

  for ( int idx = 1; idx <= 10; idx++ )
	{
  	std::cout << "My name is class " << squarer->name() << " and my math operation on " << idx << " returns " << squarer->operate_on(idx) << std::endl;
  	std::cout << "My name is class " << doubler->name() << " and my math operation on " << idx << " returns " << doubler->operate_on(idx) << std::endl;
  	std::cout << "My name is class " << cuber->name() << " and my math operation on " << idx << " returns " << cuber->operate_on(idx) << std::endl; 
	}
	
	// Looping over classes approach:
	cout << endl << "looping over integers and child classes approach: " << endl;

	vector<MathlikeOperator*> vector_of_operators;
	vector_of_operators.push_back(squarer);
	vector_of_operators.push_back(doubler);
	vector_of_operators.push_back(cuber);

	for ( int idx2 = 1; idx2 <= 10; idx2++ )
	{
		for ( int idx3 = 0; idx3 <= 2; idx3++ )
		{
  	cout << "My name is class " << vector_of_operators[idx3]->name() << " and my math operation on " << idx2 << " returns " << vector_of_operators[idx3]->operate_on(idx2) << endl;
		}
	}
	delete squarer, doubler, cuber;
 
 	return 0;
}
