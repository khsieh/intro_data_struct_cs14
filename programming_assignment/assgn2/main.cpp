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
// Assignment: <assignment 002>
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

#include <list>
#include <stack>
#include <queue>
#include <iostream>
#include "wordLadder.h"

using namespace std;

//lower helper function
void lower(string & str)
{
    for(unsigned i = 0; i < str.size(); i++)
    {
        str.at(i) = tolower(str.at(i));
    }
}

int main(int argc, char *argv[]) //taking in extra argument when execute
{
    //check for number of arguments
    //if #of argument is not 4 return error message and exit
    if(argc != 4)
    {
        cerr << "Invalid number of arguments, cannot execute program.\n"
             << "Please enter Dictionary name, start word, end word\n"
             << "i.e. ./a.out dictName tally hello\n";
        exit(1);
    }
    //if #of argument is 4 then execute wordladder class
    else
    {
        string start_str, end_str, dict_str;
        
        start_str = argv[2];
        end_str = argv[3];
        dict_str = argv[1];
        
        lower(start_str);
        lower(end_str);
        lower(dict_str);
        
        WordLadder ladder = WordLadder(dict_str);
        ladder.outputLadder(start_str, end_str);
    }
    return 0;
}
