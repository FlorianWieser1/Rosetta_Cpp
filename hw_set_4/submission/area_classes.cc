#include <math.h>
#include <string>

using namespace std;

class shape {
public:
  float get_area() {return area_;} //Getter function: returns the area stored in area_
	string get_name() {return name_;}
	virtual string name() = 0;

protected:
  // Setter function: changes the value of the area stored in area_
  // what does it meant that this function is protected?
	// --> only classes derived from this class can access this function
	float set_area(float a){area_ = a;} 
	string name_;

private:
  float area_;
};

// write a derived class rectangle from the base class shape
class rectangle : public shape{
public:
  // note that the rectangle is responsible for informing the base class of its area
  rectangle( float b, float h ) { base_ = b; height_ = h; set_area( calculate_area() ); name_ = "rectangle"; } //constructor that sets-up default values

  float calculate_area() {return base_ * height_;} //calculates the area of a rectangle using the formula base*height

	// float whats_area(){return area_;} //THIS LINE WILL NOT COMPILE. Why not?

  void set_base( float b ) { base_ = b; set_area( calculate_area() ); }
  void set_height( float h ) { height_ = h; set_area( calculate_area() ); }
	
	string name() { return get_name(); }

private:
  float base_;
  float height_;
};

// class circle
class circle : public shape{
public:
	circle( float r) { radius_ = r; set_area( calculate_area() ); name_ = "circle"; }

	float calculate_area() {return radius_ * radius_ * 3.1416;}

	void set_radius( float r ) { radius_ = r; }
	
	string name() { return get_name(); }

private:
	float radius_;
};

// class triangle
class triangle : public shape{
public:
	triangle( float a, float b, float c) { lengtha_ = a; lengthb_ = b; lengthc_ = c; set_area( calculate_area() ); name_ = "triangle"; }

	float calculate_area() {
		if ( lengthc_ <= lengtha_ + lengthb_ && lengtha_ <= lengthb_ + lengthc_ && lengthb_ <= lengtha_ + lengthc_ ) {
			return ( sqrt ( ( lengtha_ + lengthb_ + lengthc_ ) * ( lengtha_ + lengthb_ - lengthc_ ) * ( lengthb_ + lengthc_ - lengtha_ )
			* (lengthc_ + lengtha_ - lengthb_ ) ) / 4 );
		}
		else { return -1; }
	}

	void set_lengtha( float a ) { lengtha_ = a; }
	void set_lengthb( float b ) { lengthb_ = b; }
	void set_lengthc( float c ) { lengthc_ = c; }

	string name() { return get_name(); }

private:
	float lengtha_;
	float lengthb_;
	float lengthc_;
};
