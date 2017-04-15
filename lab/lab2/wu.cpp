#include <iostream>

using namespace std;

void FizzBuzz()
{
    for ( unsigned i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            cout << "FizzBuzz ";
        else if ( i % 3 == 0)
            cout << "Fizz ";
        else if ( i % 5 == 0)
            cout << "Buzz ";
        else
        {
            cout << i << " ";
        }
        
    }
    cout << endl;
}

void recur_FizzBuzz()
{
    static int i = 1;
    if(i <= 100)
    {
        if(i % 5 == 0 && i % 3 != 0)
        {
            cout << "Buzz ";
            i++;
            return recur_FizzBuzz();
        }
        else if(i % 3 == 0 && i % 5 != 0)
        {
            cout << "Fizz ";
            i++;
            return recur_FizzBuzz();
        }
            
        else if (i % 3 == 0 && i % 5 == 0)
        {
            cout << "FizzBuzz ";
            i++;
            return recur_FizzBuzz();
        }
        
        else
        {
            cout << i << " ";
            i++;
            return recur_FizzBuzz();
        }
    }
}

int main()
{
    cout << "=================FizzBuzz================\n";
    FizzBuzz();
    cout << "===============recurFizzBuzz============\n";
    recur_FizzBuzz();
    return 0;
}
