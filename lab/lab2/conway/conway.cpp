#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <unistd.h>

using namespace std;

#include "GameBoard.h"
#include "MatrixBoard.h"
#include "ToroidBoard.h"
#include "PositionListBoard.h"
//~ #include "EfficientPositionListBoard.h"
//~ #include "PositionGridBoard.h"

///////////////////////////////////////////////////////////////////////////////
// main()

int main(int argc, char** argv)
{    
    //~ MatrixBoard g;
    //~ ToroidBoard g;
    //~ PositionListBoard g;
    char command;
    
    cout << "Enter Which GameBoard To Use:\n"
         << "MatrixBoard (m) ToroidBoard (t) PositionList(l)\n";
    do{
        cin >> command;
        
        if(command != 't' && command != 'm' && command != 'l')
            cout << "invalid choice, please enter another: ";
        else 
            break;
    }while(cin);

    // if no arguments, display usage info
    if (argc==1) {
        cerr<< "usage: "<< argv[0] << " filename [sleep]" << endl;
        return 0;
    }
    
    int sleep=500000;
    if (argc==3) {
        stringstream ss;
        ss<<argv[2];
        ss>>sleep;
    }
    
    if(command == 'm')
    {
        MatrixBoard g;
        //load board
        g.loadBoard(argv[1]);
        //game loop
        while (1)
        {
            cout << clearscreen;
            g.iterate();
            g.print();
            usleep(sleep);
        }
    }
    
    else if(command == 't')
    {
        ToroidBoard g;
        //load board
        g.loadBoard(argv[1]);
        //game loop
        while (1)
        {
            cout << clearscreen;
            g.iterate();
            g.print();
            usleep(sleep);
        }
    }
    
    else if(command == 'l')
    {
        PositionListBoard g;
        //load board
        g.loadBoard(argv[1]);
        //game loop
        while (1)
        {
            cout << clearscreen;
            g.iterate();
            g.print();
            usleep(sleep);
        }
    }
    
   return 0;
}
