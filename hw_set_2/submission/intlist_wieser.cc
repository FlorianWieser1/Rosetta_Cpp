#include <iostream>
#include <list>

using namespace std;

int main()
{
    list <int> mylist;

    for (int idx = 1; idx <= 10; idx++ )
    {
        mylist.push_back(idx);
    }

    std::cout << "Here we go!" << std::endl;

    std::cout << "Forwards iteration" << std::endl;
    for (list<int>::const_iterator iter = mylist.begin(); iter != mylist.end(); ++iter )
    {
        std::cout << "Next element: " << *iter << std::endl;
    }
    std::cout << "Done!" << std::endl;

    std::cout << "Backwards iteration" << std::endl;
    for (list<int>::const_reverse_iterator iter2 = mylist.rbegin(); iter2 != mylist.rend(); ++iter2 ) 
    {
        std:cout << "Next element: " << *iter2 << std::endl;
    }
    std::cout << "Done!" << std::endl;

return 0;
}
