#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int fib(int input_number)
{
    int *dyn_array = new int[input_number];
    dyn_array[0] = 1;
    dyn_array[1] = 1;

    for ( int i = 2; i <= input_number; i++ )
    {
        dyn_array[i] = dyn_array[i-1] + dyn_array[i-2];
    }

    int result = dyn_array[input_number - 1];
    delete dyn_array;

    return result;
}


int main() 
{
    std::cout << "Enter the nth Fibonacci number you would like: ";

    int which;

    std::cin >> which;
    std::cout << "The " << which << "th Fibonacci number is: " << fib( which ) << std::endl;

    float time_req = clock();
   
    for ( int idx2 = 0; idx2 < 500; idx2++ )
    {
        fib(which);
    }

    cout << "processing time (500 loops): " << (clock() - time_req) / CLOCKS_PER_SEC << endl;  
    cout << "While the processing time increased exponentially with the recursive approach,";
    cout << " with the iterative approach the processing time increases linearly." << endl;

    return 0;
}


