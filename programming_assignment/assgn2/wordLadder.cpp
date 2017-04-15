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
#include <fstream>
#include "wordLadder.h"

using namespace std;

/**
 * constructor of the WordLadder
 * stores every word in the dictionary to the list
 */
WordLadder::WordLadder(const string& listFile)
{
    string line;
    ifstream dictfile(listFile.c_str());
    
        while(dictfile >> line)
        {
            dict.push_back(line);
        }
        dictfile.close();
    
}

/**
 * implementing the algorithm
 */ 
void WordLadder::outputLadder(const string&start, const string &end)
{
    //check if start and end is the same
    //return start if true;
    if(start == end)
    {
        cout << start << endl;
        return;
    }
    
    stack <string> S;
    S.push(start);
    Q.push(S);
    while(!Q.empty())
    {
        list<string> :: iterator i;
        for(i = dict.begin(); i != dict.end(); i++)
        {
            if( wordDiff( *i, Q.front().top() ) )
            {
                if(*i == end)
                {
                    print(Q);
                    cout << end << endl;
                    return;
                }
                
                stack <string> newS = Q.front();
                newS.push( *i );
                Q.push(newS);
                dict.erase(i);
                i--;
            }
        }
        Q.pop();
    }
}

//helper
/**
 * print out the front stack of the Queue of stacks
 */ 
void WordLadder::print(const queue <stack <string> > &Q)
{
    stack <string> flipS = Q.front();
    stack <string> printS;
    
    while(!flipS.empty())
    {
        printS.push(flipS.top() );
        flipS.pop();
    }
    
    //stack<string> :: iterator i;
    while(!printS.empty())
    {
        cout << printS.top() << " ";
        printS.pop();
    }
}

//helper
/**
 * return true if the two words only have one char in difference
 * return false otherwise
 */
bool WordLadder::wordDiff(const string &w1, const string &w2)
{
    int diffCount = 0;
    for(unsigned i = 0; i < 5; i++)
    {
        if(w1.at(i) != w2.at(i))
            diffCount++;
    }
    if (diffCount == 1)
        return true;
    else
        return false;
}

//helper
/**
 * test if the dict list stores all strings
 */
void WordLadder::list_test()
{
    list<string>::iterator i;
    for (i = dict.begin(); i != dict.end(); i++)
    {
        cout << *i << endl;
    }
    
}
