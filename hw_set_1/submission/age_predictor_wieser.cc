#include <iostream>
#include <string>
using namespace std;

int main() {

  std::cout << "I say 'up up down down left right left right b a', you say: ";
  std::string response1;
  std::getline( std::cin, response1 );
  
  std::cout << "What are records made out of? ";
  std::string response2;
  std::getline( std::cin, response2 );

  if(response1 == "select start" & response2 != "vinyl") {
    cout << "You are old \n";
  }
    else  {
      if(response1 == "select start" & response2 == "vinyl")  {
        cout << "You are very old \n";
      }
      else  {
        cout << "You are young \n";
      }
    }
  return 0;
}
