#include <iostream>
#include <string>

using namespace std;

int main() {
  
  cout << "Enter the pine tree's height as an integer: ";
  int height, half_width;
  char a = ' ';
  string stars, pine_tree_row;
  
  cin >> height;

  half_width = height - 1;
  string half_width_old(half_width, a);
  stars = "*";

  for(int idx = 0; idx < height; idx++) {
    string space(half_width, a);
    pine_tree_row = space + stars + space;
    cout << pine_tree_row << endl;
    half_width--;
    stars = "*" + stars + "*";
 }

  cout << half_width_old << "|" << half_width_old;
  // Assignment:
  // Write code here to draw a pine tree.
  // If the height given is "3" then the pine tree should look like this:
  //   *
  //  ***
  // *****
  //   |
  //
  // If the height given is "5" then the pine tree should look like this:
  //     *
  //    ***
  //   *****
  //  *******
  // *********
  //     |
  //
  // where the height represents the number of rows of stars.  The trunk should
  // always be there.  Don't worry about writing code to verify that the input
  // is an integer (though, kudos if you did think about that being necessary!)

    
  return 0;
}
