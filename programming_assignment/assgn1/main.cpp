// Course: CS 14 Spring 2013
//
// First name: <KEVIN>
// Last name: <HSIEH>
// Course username: <khsie003>
// Email address: <khsie003@ucr.edu>
//
// Lecture section: <001>
// Lab section: <022>
// TA: <Santosh Sangalad>
//
// Assignment: <assignment 001>
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class STACK
{
    private:
        vector <double> v;
        unsigned vcap;
    public:
        STACK();
        void push(double n);
        double pop();
        unsigned vecSize();
        
};

STACK::STACK()
:v(),vcap(20)
{}

void STACK::push(double n)
{
    if( v.size() < vcap)
    {
        v.push_back(n);
    }
}

double STACK::pop()
{
    double temp = v.at(v.size() -1);
    v.pop_back();
    return temp;
}

unsigned STACK::vecSize()
{
    return v.size();
}


int main()
{
    string input;
    string check;
    
    while(cin)
    {
        STACK stackdata;
        bool fail = false;
        
        cout << "> ";
        getline(cin,input);
        stringstream equation(input);
        
        while(equation.rdbuf()->in_avail() != 0)
        {
            equation >> check;
            
            if(check == "^D")
                exit(1);
            
            int zero = check.find('0');
            int one = check.find('1');
            int two = check.find('2');
            int three = check.find('3');
            int four = check.find('4');
            int five = check.find('5');
            int six = check.find('6');
            int seven = check.find('7');
            int eight = check.find('8');
            int nine = check.find('9');
            
            if(zero  == -1 && one   == -1 &&
               two   == -1 && three == -1 &&
               four  == -1 && five  == -1 &&
               six   == -1 && seven == -1 &&
               eight == -1 && nine  == -1 &&
               check != "+" && check != "-" && check != "*" && 
               check != "/" && check != "%")
               {
                    cout << "Error: invalid token\n";
                    fail = true;
               }
            
            //check for intergers
            if(check != "+" && check != "-" && check != "*" && 
               check != "/" && check != "%")
            {
                stringstream convert(check);
                double n;
                convert >> n;
                stackdata.push(n);
            }
            
            //check for operations
            else if(check == "+" || check == "-" || check == "*" || 
                    check == "/" || check == "%")
            {
                if(stackdata.vecSize() >= 2)
                {
                    if(check == "+")
                    {
                        double temp = stackdata.pop();
                        double temp2 = stackdata.pop();
                        temp += temp2;
                        stackdata.push(temp);
                    }
                    
                    else if(check == "-")
                    {
                        double temp = stackdata.pop();
                        double temp2 = stackdata.pop();
                        
                        temp2 -= temp;
                        stackdata.push(temp2);
                    }
                    
                    else if(check == "/")
                    {
                        double temp = stackdata.pop();
                        double temp2 = stackdata.pop();
                        
                        temp2 = temp2 / temp;
                        stackdata.push(temp2);
                    }
                    
                    else if(check == "*")
                    {
                        double temp = stackdata.pop();
                        double temp2 = stackdata.pop();
                        
                        temp *= temp2;
                        stackdata.push(temp);

                    }
                    
                    //extra credit
                    else if(check == "%")
                    {
                        int temp = static_cast <int> (stackdata.pop());
                        int temp2 = static_cast <int> (stackdata.pop());
                        
                        
                        int r = temp2 % temp;
                        
                        //~ if(r < 0)
                            //~ r += temp;
                        stackdata.push(r);
                    }
                }
                
                else
                {
                    cout << "Error: not enough parameters\n";
                    fail = true;
                }

            }
        }
        
        if(stackdata.vecSize() == 1 && !fail)
            cout << stackdata.pop() << endl;
        else if(stackdata.vecSize() > 1 && !fail)
        {
            cout << "Error: not enough operators\n";
        }
    }
    
    return 0;
}
