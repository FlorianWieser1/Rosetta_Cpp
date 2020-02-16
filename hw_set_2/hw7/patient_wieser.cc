#include <iostream>
#include <string>

using namespace std;

class Patient
{   
  private:
    string Patient_name;
    float Patient_height;
    float Patient_weight;
  
  public:

//getters    
    string get_name()
    {
        return Patient_name;
    }

    float get_height()
    {
        return Patient_height;
    }

    float get_weight()
    {
        return Patient_weight;
    }

     void set_name( string name )
    {
        Patient_name = name;
    }

//setters
    void set_height( float height )
    {
        Patient_height = height;
    }

    void set_weight( float weight )
    {
        Patient_weight = weight;
    }

//(default) constructor    
    Patient(string x = "", float y = 0, float z = 0 )
    {
        Patient_name = x;
        Patient_height = y;
        Patient_weight = z;
    }

    float bmi();
};

float Patient::bmi()
{
    if ( Patient_weight == 0 || Patient_height == 0 )
    {
        return 0;
    }
    else
    {
        return Patient_weight / ( Patient_height * Patient_height );
    }
}


int main() {

  Patient father("Andrew Nonymous");
  Patient mother("Ursula N. Known");
  Patient baby;

//Father's height and weight are unknown.
  mother.set_name("Ursula N. Nonymous");
  mother.set_height(1.65);
  mother.set_weight(58);

  baby.set_height(0.495);
  baby.set_weight(3.4);

  std::cout << "Baby: " << baby.get_name() << " BMI: " << baby.bmi() << std::endl;
  std::cout << "Mother: " << mother.get_name() << " BMI: " << mother.bmi() << std::endl;
  std::cout << "Father: " << father.get_name() << " BMI: " << father.bmi() << std::endl;

  return 0;
}
