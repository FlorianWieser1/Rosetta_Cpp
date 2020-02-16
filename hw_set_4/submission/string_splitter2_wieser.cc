// This assignment builds on the string splitter function you wrote in
// the previous one.  In this assignment, instead of your input consisting
// of only 1s and 0s, it may now consist of any number of different
// numbers (between 0 and 9).  In this case, you care about the 1s
// and the 0s, but there might be 2s and 3s etc. mixed in.
//
// Your function should report the beginning and ending possition for
// each block of 0s and 1s.  Use the struct below to report a pair of
// positions:
// 
// So for example, the input string (ignore the two ruler lines)
//
// 00000000001111111111222222222233333333334 <-- ruler tens
// 01234567890123456789012345678901234567890 <-- ruler ones
//
// 00001110293411111887888880000222333311111 <-- the input string
// should report the following starting and stopping
// positions:
// start stop
//     0    3
//     4    6
//     7    7
//    12   16
//    25   28
//    36   40
// Notice that the blocks of non-0s and non-1s are basically ignored.
//
// Your function should have the following signature.
// std::vector< start_and_stop >
// split_zeros_and_ones_blocks_from_string( std::string const & input_string );
//
// Grading will work as it did for the previous assignment -- your int main() will
// be replaced with another one that will call your function and make sure it 
// produces the correct answers.  Think hard about edge cases.

// string splitter function

#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

struct start_and_stop {
	int start_;
	int stop_;
};
 
vector< start_and_stop > split_zeros_and_ones_blocks_from_string( string const & input_string ) 
{
	int length_of_substring = 0;
	int idx2;
	struct start_and_stop positions;
	vector< start_and_stop > output_vector;

	for ( int idx1 = 0; idx1 <= input_string.length(); idx1++ )
	{
		length_of_substring = 0;

		if ( ( input_string[idx1] == '1' || input_string[idx1] == '0') && ( input_string[idx1] != input_string[idx1 - 1] ) )
		{
			positions.start_ = idx1;
			idx2 = idx1;
			while ( input_string[idx2] == input_string[idx2 + 1] )
			{
				length_of_substring++;
				idx2++;
			}
			positions.stop_ = positions.start_ + length_of_substring;
			output_vector.push_back( positions );
		}		
	}
	return output_vector;
}

// print vector (for debugging reasons)
void print( vector< start_and_stop > const & vector_to_print )
{
	for ( int idx3 = 0; idx3 < vector_to_print.size(); idx3++ )
	{
		std::cout << vector_to_print[idx3].start_ << " " << vector_to_print[idx3].stop_ << endl;
	}
}

int main() {

string test_string = "311150003223111055001111101912 -- input_string";
string ruler_ones = "012345678901234567890123456789 -- ruler ones";
string ruler_tens = "000000000011111111112222222222 -- ruler tens";
cout << ruler_tens << endl;
cout << ruler_ones << endl;
cout << test_string << endl;
print(split_zeros_and_ones_blocks_from_string(test_string));
cout << endl;

return 0;
}

