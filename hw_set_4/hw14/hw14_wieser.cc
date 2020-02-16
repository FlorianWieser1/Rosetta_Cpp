// Conceptually, one class ought to derive from another class if it passes
// the "is a" test.  If you can say X is a Y, then X should derive from Y.
// For instance, a "Dog" is a "Mammal".  It would be appropriate to encode
// this relationship by by creating a "Dog" class as a derivative of
// the "Mammal" class.

// Here are a few references to get you started on this concept:
// http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
// http://en.wikibooks.org/wiki/C%2B%2B_Programming/Classes/Inheritance

// For this exercise, we can think of a "triangle" and a "rectangle" as
// derivatives of the parent class "shape".

// Your mission, should you choose to accept it, will be to define two classes
// circle and triangle that will calculate the area of a circle and a triangle.
// This area will be stored in a private member variable defined in the
// parent class "shape", which will only be accessible by the base classe's get_area
// and set_area functions. You will test your new derived classes by creating
// instances of each in main() and printing their areas.

// Question (Answer here):
// Why does the whats_area() function in the rectangle class generate an error?

// For Homework 14, You should create a separate cc file that contains your base
// and derived classes. For this exercise, you should add a pure virtual function
// to the base class called "name", which returns a string giving the name for the
// class. You'll use this to make reporting the areas of your objects easier: you
// can construct a std::vector< shape * > and load up the individual instances
// (constructed using "new" and put into pointers) into this vector.  Then you can
// use a for loop to visit each shape and to output its name and its area.  The
// output should remain identical to that in hw13, but it should come from a for loop
// instead of from individual cout statements.

#include <iostream>
#include <string>
#include "area_classes.cc"
#include <vector>

using namespace std;

int main(){
  
  float user_base, user_height;
	float user_radius;
	float length1, length2, length3;

	vector<shape*> vector_of_shapes;

  std::cout << "Please enter a base length: ";
  std::cin >> user_base;
  std::cout << "Please enter a height: ";
  std::cin >> user_height;

  std::cout << "Please enter a circle radius: ";
  std::cin >> user_radius;

  std::cout << "Please enter length 1 for your triangle: ";
  std::cin >> length1;
  std::cout << "Please enter length 2 for your triangle: ";
  std::cin >> length2;
  std::cout << "Please enter length 3 for your triangle: ";
  std::cin >> length3;

	shape * rec1 = new rectangle(user_base, user_height);
	shape * cir1 = new circle( user_radius );
	shape * tri1 = new triangle ( length1, length2, length3 ); 

	vector_of_shapes.push_back(rec1);
	vector_of_shapes.push_back(cir1);
	vector_of_shapes.push_back(tri1);
	
	for ( int idx = 0; idx < 3; idx++ )
	{
		cout << "The area of the " << vector_of_shapes[idx]->get_name() << " is: " 
		<< vector_of_shapes[idx]->get_area()	<< endl;
	}
	
	for ( int idx2 = 0; idx2 < 3; idx2++ )
	{
		delete vector_of_shapes[idx2];
	}
	vector_of_shapes.clear();
	
  return 0;
}
