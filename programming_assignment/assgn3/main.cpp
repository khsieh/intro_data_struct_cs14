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
// Assignment: <assignment 003>
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

#include <iostream>
#include <string>
#include "map.h"

//~ template <typename K, typename V>
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        cerr <<"Invalid number of arguments: Please enter Dictionary name.\n";
        cerr <<"i.e. ./a.out Latin.txt\n";
    }
    else
    {
        string dict_str = argv[1];
        Map<string, string> *m = new Map<string,string>;
        m -> loadFromFile(dict_str);
        
        string to_find;
        while(cin >> to_find)
        {
            cout << m->lookup(to_find) << endl;
        }
        
        //~ m -> insert("ATHHHH", "KABAMM");
        //~ m -> insert("AAHHHH", "KABAMM");
        //~ m -> insert("BALALA", "AHHHH");
        //~ m -> insert("CROLOLOL", "LOLOLOL");
        //~ m -> insert("A", "LOLOLOL");
        //~ m -> insert("CefecsadgL", "LOLOLOL");
        //~ m -> insert("DADSFAD" , "OTL");
        //~ m -> printMap();
        //~ cout << endl;
        //~ cout << "Height: " << m-> height() << endl;
        //~ cout << "Balance Factor: " << m -> balanceFactor() << endl;
        //~ cout << "Size: " << m-> size() << endl;
        //~ cout << "Is Member: " << m -> isMember("A") << endl;
        //~ cout << "Look Up: " << m -> lookup("A") << endl;
        //~ cout << "Closest: " << m -> closestKey("B") << endl;
        //~ cout << "Similar: " << m -> lookupSimilar("B") << endl;
        //~ 
        //~ m -> erase("CROLOLOL");
        
        //~ m -> saveToFile("newDict.txt");
    }
    return 0;
}
