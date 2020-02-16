#include <iostream>

int main() {

  std::cout << "I say 'up up down down left right left right b a', you say: ";
  std::string response1;
  std::getline( std::cin, response1 );

  std::cout << "What are records made out of? ";
  std::string response2;
  std::getline( std::cin, response2 );


  // In this assignment, you will tell the user whether they are old or not
  // based on their response to the above questions.  This requires you use
  // "if" and "else" control of flow constructs.
  // If the user knows the answer to the first question ("select start"), then
  // they are old. If they don't know the answer to the first question, then
  // they might be young or they might be very old.  You'll need to look at
  // their answer to the second question.  If they get the answer to the second
  // question right ("vinyl") then they are very old.
  // Your code should send one of these three output messages to the screen:
  // "You are young"
  // "You are old"
  // "You are very old"
  // depending on their answers.

  return 0;
}
