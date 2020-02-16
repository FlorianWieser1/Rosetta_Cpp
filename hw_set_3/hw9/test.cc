#include <iostream>

using namespace std;

int main () {
int number = 3;
cout << "number   " << number << endl;
cout << "&number  " << &number << endl;
cout << "----------------------" << endl;

int *point = NULL;
point = &number;
cout << "point   " << point << endl;
cout << "*point  " << *point << endl;
cout << "&point  " << &point << endl;
   return 0;
}
