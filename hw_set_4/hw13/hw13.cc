// In this exercise, you will be working with classes and derived classes.
// Inheritance is an important concept in object-oriented design
// because it allows us to define one class in terms of another class.
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

#include <iostream>

class shape {
public:
  float get_area(){return area_;} //Getter function: returns the area stored in area_

protected:

  // Setter function: changes the value of the area stored in area_
  // what does it meant that this function is protected?
  float set_area(float a){area_ = a;} 

private:
  float area_;
};

//write a derived class rectangle from the base class shape
class rectangle : public shape{
public:
  // note that the rectangle is responsible for informing the base class of its area
  rectangle( float b, float h ) { base_ = b; height_ = h; set_area( calculate_area() ); } //constructor that sets-up default values

  float calculate_area() {return base_ * height_;} //calculates the area of a rectangle using the formula base*height

  //float whats_area(){return area_;} //THIS LINE WILL NOT COMPILE. Why not?

  void set_base( float b ) { base_ = b; set_area( calculate_area() ); }
  void set_height( float h ) { height_ = h; set_area( calculate_area() ); }

private:
  float base_;
  float height_;
};

// Write a derived class, circle, from the base class shape. A circle can be defined
// by a single radius and thus the constructor should take a single argument and assign
// the value to the radius. There should also be a calculate_area function that
// calculates the area of the circle.

// Write a derived class, triangle, from the base class shape.  A triangle can be
// defined by the lengths of its three sides.  Make sure your triangle is able to
// calculate its area.  If the three lengths do not define a proper triangle (e.g.
// if one lenght is 1 another length is 2 and the third length is 100, then you
// don't have a closed triangle), then set the area to be -1.

int main(){
  
  float user_base, user_height;

  std::cout << "Please enter a base length: ";
  std::cin >> user_base;
  std::cout << "Please enter a height: ";
  std::cin >> user_height;

  //Create rectangle object
  rectangle rec1(user_base, user_height);


  //Test your circle class
  float user_radius;
  std::cout << "Please enter a circle radius: ";
  std::cin >> user_radius;

  //create an object of the circle class with radius equal to user_radius
  
  // Test your triangle class
  float length1, length2, length3;
  std::cout << "Please enter length 1 for your triangle: ";
  std::cin >> length1;
  std::cout << "Please enter length 2 for your triangle: ";
  std::cin >> length2;
  std::cout << "Please enter length 3 for your triangle: ";
  std::cin >> length3;

  // create an object of the triangle class with the three lengths.
  // Your triangle class should probably make sure that these lengths
  // are sensical.  (do the distances satisfy the "triangle inequality"?)

  std::cout << "The area of the rectangle is: " << rec1.get_area() << std::endl;
  std::cout << "The area of the circle is: " << std::endl;
  std::cout << "The area of the triangle is: " << std::endl;

  return 0;

}
