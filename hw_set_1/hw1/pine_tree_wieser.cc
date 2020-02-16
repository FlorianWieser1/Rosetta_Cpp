#include <iostream>
#include <string>
using namespace std;

int main() {
  
  std::cout << "Enter the pine tree's height as an integer: ";
  int height;
  std::cin >> height;
  
  char char_space = ' ';
  int space_width = height - 1;
  string space_width_old(space_width, char_space);
  string stars = "*";
  string pine_tree_row;

  for(int idx = 0; idx < height; idx++)  {
      string space(space_width, char_space);
      pine_tree_row = space + stars + space;
      cout << pine_tree_row << endl;
      space_width--;
      stars = "*" + stars + "*";
      }

      cout << space_width_old << "|" << space_width_old << endl;
  return 0;
}
