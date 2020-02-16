#include <iostream>
#include <string>
#include <set>

// You are writing a new video game to be played by 50-somethings
// on Facebook.  The player will accumulate pets and feed them
// and take them to get pedicures and to eat hand made rosemary and
// olive oil biscuis.  The players will pay small amounts of money 
// each day to keep their pets happy and affectionate.  You will
// be a billionare.

// But first you must write the game.

// All pets in this game will derive from a common base class, class Pet.
// This class will do a lot of work in keeping track of how much the pet
// has eaten, the quality of food that it has been given (the higher
// quality the food, the shinier its coat will be and the more affectionate
// the pet will become, and of course, the more the player will have to
// pay you for it).  You will derive a new pet, class TabbyCat, from Pet.

// Your class should *derive publicly* from class Pet.  In its *constructor*
// it should invoke the four initialization subroutines of the base class;
// set_initial_weight, set_ideal_adult_weight, set_age_of_adulthood,
// and set_metabolic_rate.  For a tabby cat, go with an initial weight of
// 0.5 lbs, an ideal adult weight of 12 lbs, an age of adulthood at 10 days
// (it's a video game), and a metabolic rate of 6 calories per hour per pound.
// The code already provided in main() should be used, though, you might want
// to play around with how much the tabby cat ought to be fed.


// HW12
// Now, with your base class (Pet) and your derived class (TabbyCat) in
// place, you will be adding a virtual function to the Pet class that you
// will also add to the TabbyCat class.
//
// Typically, pets also have a favorite food that they love eating. Add a
// private membrane variable favorite_food_ to the Pet class and initialize
// it in the constructor with "seeds". Add a public getter and setter (taking
// a string) to this class as well:
//
// virtual void set_favorite_food( std::string ); and
// std::string get_favorite_food();
//
// (What does the keyword "virtual" do?)
//
// This function is called in the "train_at_salad_bar" function (below), where
// players can pay $7.50 to feed their pets all the salad they can eat, and
// as a side effect, change the food preferences of their pets.  On a trip
// to the salad bar, their favorite food becomes spinach.
//
// Now with TabbyCats the thing is a bit different. Their evolutionary ties
// to tigers seem to be stronger than for other cats (after all, their fur
// resembles that of a tiger more closely) so they LOVE meat. They don't
// like seeds or spinach at all. To account for this, *override* the base class's
// implementation of the set_favorite_food method by adding a setter that has
// the same function signature as in the (parent) Pet class, but that instead
// of altering the favorite_food_ data member, prints out a big warning, saying
// something like you aren't allowed to set the favorite food for a TabbyCat,
// because the only thing they eat is meat.  Make sure to call the parent class's
// version of set_favorite_food( "meat" ) in the TabbyCat's constructor -- you'll
// have to figure out how to call the parent class's version of this function.
//
// What should happen when Snookums is sent to the salad bar?

class Pet {
public:
  Pet();
  ~Pet();

  void feed( float quality, float calories );

  void increment_hour();
  float weight() const;
  float happiness() const;
  float calorie_reserve() const;

  // Add the two methods, set_favorite_food and get_favorite_food here

protected:
  void set_initial_weight( float weight ); // in pounds
  void set_ideal_adult_weight( float weight ); // in pounds
  void set_age_of_adulthood( int nhours ); // in hours
  void set_metabolic_rate( float rate ); // calories per hour per pound

private:
  float initial_weight_;
  float ideal_adult_weight_;
  float weight_;
  float metabolic_rate_;
  int age_; // number hours old
  int age_of_adulthood_; // number of hours at which the pet is full grown
  float happiness_;
  float calorie_reserve_;
  // Add a data member here to store the Pet's favorite food

};

Pet::Pet() :
  initial_weight_( -1.0 ),
  weight_( -1.0 ),
  ideal_adult_weight_( -1.0 ),
  age_( -1.0 ),
  happiness_( 1.0 ),
  calorie_reserve_( 400 ),
  // make sure you initialize the favorite food data member in the constructor 
{}

Pet::~Pet() {}

void Pet::feed( float quality, float calories )
{
  float happiness_alpha_ = 0.1;

  happiness_ = happiness_alpha_ * ( happiness_ * ( .5 + quality ) ) + (1 - happiness_alpha_ );
  calorie_reserve_ += calories;

  if ( calorie_reserve_ > weight_ * metabolic_rate_ * 10 ) {
    happiness_ *= 0.9; // overfull!
  }

}

void Pet::increment_hour()
{
  float calories_burned = weight_ * metabolic_rate_;
  if ( age_ < age_of_adulthood_ ) {
    calories_burned += 350 * ( ideal_adult_weight_ - initial_weight_ ) / age_of_adulthood_;
  }

  std::cout << "calories burned: " << calories_burned << std::endl;
  if ( calorie_reserve_ > calories_burned ) {
    calorie_reserve_ -= calories_burned;
    if ( age_ < age_of_adulthood_ ) {
      weight_ += ( ideal_adult_weight_ - initial_weight_ ) / age_of_adulthood_;
    }
    weight_ += 0.05 * calorie_reserve_ / 3500;
  } else {
    float deficit = calories_burned - calorie_reserve_;
    calorie_reserve_ = 0;
    happiness_ *= .85; // you get grumpy real quick on an empty stomach
    weight_ -= deficit / 3500;
  }
  age_ += 1;

  if ( age_ > age_of_adulthood_ && weight_ > ideal_adult_weight_ ) {
    happiness_ *= .9; // overweight animals are less happy
  }

}

float
Pet::weight() const { return weight_; }

float
Pet::happiness() const { return happiness_; }

float
Pet::calorie_reserve() const { return calorie_reserve_; }

void
Pet::set_initial_weight( float weight )
{
  initial_weight_ = weight_ = weight;
}

void
Pet::set_ideal_adult_weight( float weight )
{
  ideal_adult_weight_ = weight;
}

void
Pet::set_age_of_adulthood( int nhours )
{
  age_ = 0;
  age_of_adulthood_ = nhours;
}

void
Pet::set_metabolic_rate( float rate )
{
  metabolic_rate_ = rate;
}

void
train_at_salad_bar( Pet & pet, int num_helpings ) {
  pet.set_favorite_food( "spinach" );

  std::set< std::string > salad_bar_food;
  salad_bar_food.insert( "spinach" );
  salad_bar_food.insert( "beets" );
  salad_bar_food.insert( "brocolli" );
  salad_bar_food.insert( "carrots" );
  salad_bar_food.insert( "peas" );

  float quality = 1.0;
  if ( std::find( salad_bar_food.begin(), salad_bar_food.end(), pet.get_favorite_food() ) != salad_bar_food.end()  ) {
    quality = 1.2; // if the food at the salad bar is the Pet's favorite, then set it as higher quality
  }

  for ( int ii = 0; ii < num_helpings; ++ii ) {
    pet.feed( quality, 30 );
  }

}


int main() {
  TabbyCat snookums;

  // simulate fifteen days, feeding snookums every 8 hours. Since she's growing,
  // she'll need more and more food each time she is fed until day 10

  for ( int ii = 0; ii < 45; ++ii ) {
    float ncalories( 0 );
    if ( ii < 30 ) {
      ncalories = 200 + ii*10;
    } else {
      ncalories = 12 * 8 * 6;
    }
    snookums.feed( 1.0, ncalories );
    for ( int jj = 0; jj < 8; ++jj ) {
      snookums.increment_hour();
      std::cout << "Snookums status, hour " << ii*8 + jj + 1 << " " << snookums.weight() << " " << snookums.happiness() << " " << snookums.calorie_reserve() << std::endl;
    }
  }

  // Send snookums to the salad bar.  Does that change snookums' favorite food?

  std::cout << "Before going to the salad bar, Snookums loves: " << snookums.get_favorite_food() << std::endl;
  train_at_salad_bar( snookums, 10 ); // ten helpings of fresh leafy greens!
  std::cout << "After going to the salad bar, Snookums loves: " << snookums.get_favorite_food() << std::endl;

}
