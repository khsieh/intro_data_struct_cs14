#include <iostream>
//~ #include "ex2.h"

using namespace std;

template <class T>
unsigned binary_1(T n)
{
    if(n == 1)
        return 1;
    if(n == 0)
        return 0;
    else
    {
        unsigned one_count = 0;
        one_count = binary_1( n / 2);
        
        if(n % 2)
            return one_count + 1;
        return one_count;
    }
}

int main()
{
    cout << "=========ex1========" << endl;
    int i = 15;
    char c = 'k';
    //~ unsigned count = binary_1(i);
    cout << "one's: " << binary_1(i) << endl;
    cout << "one's: " << binary_1(c) << endl;
    
    return 0;
}
