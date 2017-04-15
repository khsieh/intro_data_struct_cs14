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

#ifndef _WORD_LADDER_H_
#define _WORD_LADDER_H_

#include <list>
#include <queue>
#include <stack>

using namespace std;

class WordLadder
{
    private:
        list <string> dict;
            //list of string to store the dictionary
        queue <stack <string> >  Q; 
            //queue of stack to keep track of the wordLadder to output
    public:
        WordLadder(const string& listFile);
        void outputLadder(const string&start, const string &end);
        
        //myHelper functions
        bool wordDiff(const string &w1, const string &w2);
        void print(const queue <stack <string> > &Q);
        void list_test();
    
};

#endif //_WORD_LADDER_H_
