#include <iostream>
#include <string>
using namespace std;

class Person
{
    private:
    int b_age_;

    public:
    void set_age(int age);
    
    public:
    Person();
    ~Person();
    int get_age();
};

// constructor
Person::Person() :
    b_age_(12)
{}

// deconstructor
Person::~Person() {}

// setter
void Person::set_age(int age )
{
    b_age_ = age;
}

// getter
int Person::get_age()
{
    return b_age_;
}

// ---------------------inherited class-------------------------------- //

class Student : public Person
{   
    private:
    int student_number_;

    public:
    Student();
    int get_student_number();
    void set_student_number(int student_number);
};

// constructor
Student::Student() :
    student_number_(1123234)
{
    set_age(34);
}

// setter
void Student::set_student_number(int student_number )
{
    student_number_ = student_number;
}

// getter
int Student::get_student_number()
{
    return student_number_;
}

//---------------------main-------------------------------------------- //

int main ()
{
    Person flo;
    Student wael;
    cout << flo.get_age() << endl;
    cout << wael.get_student_number() << endl;
    cout << wael.get_age() << endl;
    return 0;
}
