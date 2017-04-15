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
// Assignment: <assignment 004>
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

#include <iostream>
#include "syntaxTree.h"

using namespace std;

int main()
{
    string equation;
    
    while(true)
    {
        cout << "> ";
        getline(cin,equation);
        SyntaxTree* sTree = new SyntaxTree(equation);
        cout << sTree -> evaluateTree() << endl;
    }
    return 0;
}

