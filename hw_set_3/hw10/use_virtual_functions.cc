// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:
// You can ignore the two lines aboive: they're commands to the text editor to control how text displays.
// You'll get used to them with Rosetta code.

#include <iostream>
#include <string>
#include <vector> //HINT

// In this exercise, you will be using virtual functions.  In C++,
// classes “inherit” from each other – a “child class” has access to
// things it got from the “parent class” it was based on.  A key
// feature of this is “virtual functions” - functions which are
// defined with the same function signature for all members of the
// class family, but behave differently for each member of the class.
// (You should have heard about / read about virtual functions much
// more deeply than I can introduce here...but those are the basics).

// Inheritance lets you have a pointer of type class A, that points
// to an actual instantiated object of class B, where type B is a child
// class of type A.  This means that the class interface defined by A
// can be implemented differently by the child classes, but called with
// the same function call!

// The assignment is simple: I have supplied a class hierarchy for you
// of simple classes with a name and math function.  Your job is to
// call these classes' functions to produce output like so:

// (begin sample output)
// My name is class DOUBLER and my math operation on 6 returns 12.
// My name is class SQUARER and my math operation on 9 returns 81.
// …
// (end sample output)

// Repeat for all classes (doubler, squarer, cuber) and all integers
// 1-10.  Use a loop over the integers!  Megabonus points for using a
// loop over the CLASSES.  (This is possible but we haven't covered
// it.  Hint: instantiate instances of each class, then figure out how
// to put them in a container like std::vector or std::list that you
// can iterate over.)

//For now, feel free to skip to the top of int main(), and return to
//the class definitions as needed.




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

  //here's an example for one class and one integer:
  MathlikeOperator * cuber = new Cuber; //wow!  MathlikeOperator*, but pointing at a Cuber!
  int j = 9;
  std::cout << "My name is class " << cuber->name() << " and my math operation on " << j << " returns " << cuber->operate_on(j) << std::endl;
  //if you are not familiar with the -> nomenclature, it means the same as (*cuber).name()
  delete cuber;

  //now, comment that above out, and do that output for all of
  //doubler, squarer, and cuber over integers 1-10.  Loop over the
  //integers, and loop over the classes as well by putting them in a
  //container if you can figure out how.

  //DO NOT directly instantiate objects of class Cuber, Doubler, or
  //Squarer: you may only point to them via MathlikeOperator pointers.
	//Cuber cuber; // ILLEGAL! (it compiles, but it's against the assignment)
	//Cuber * cuber = new Cuber; // ALSO ILLEGAL! (it compiles, but it's against the assignment)

  //did you remember to deallocate the pointers?
  return 0;
}
