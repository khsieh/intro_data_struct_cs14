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

#ifndef _SYNTAX_TREE_H_
#define _SYNTAX_TREE_H_

#include <list>
#include <string>

using namespace std;

class SyntaxTree
{
    private:
        string operation;
        double data;
        list <SyntaxTree*> children;
    public:
        SyntaxTree();
        SyntaxTree(string str);
        size_t findMatchingParen(string str, size_t start);
        void loadTree(string &equation);
        bool isValid(string equation);
        double evaluateTree();
        double evaluateHelper(SyntaxTree* st);
        
};

#endif
