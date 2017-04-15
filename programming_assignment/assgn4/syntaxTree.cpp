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

#include "syntaxTree.h"
#include <iostream>
#include <sstream>
#include <list>
#include <string>
#include <queue>
#include <stack>

using namespace std;

SyntaxTree::SyntaxTree()
:operation(""), data(0)
{}

SyntaxTree::SyntaxTree(string str)
{
    loadTree(str);
}

//that useful function from lab
size_t SyntaxTree::findMatchingParen(string str, size_t start)
{
    int parens=0;
    for (unsigned i=start; i<str.size(); i++) {
        if (str[i]=='(') parens++;
        if (str[i]==')') parens--;
        if (parens==0) return i;
    }
    return string::npos;
}

void SyntaxTree::loadTree(string &equation)
{
    //~ int openParen = equation.find('(') + 1;
    //~ int closeParen = findMatchingParen(equation, openParen);
    //~ equation = equation.substr(openParen, closeParen);
    //~ cout << equation << endl;
    
    //remove the outter most parentheses
    equation = equation.substr(1, equation.size()-2);
    
    stringstream stream(equation);
    string tempStr;
    SyntaxTree* tempTree;
    
    //parent
    stream >> tempStr;
    operation = tempStr;
    //~ cout << tempStr << endl;
    //get children
    while(stream)
    {
        stream >> tempStr;
        if(tempStr.at(0) == '(')
        {
            string tempStr2;
            
            tempStr2 += tempStr;
            tempStr2 += " ";
            while(tempStr.at(tempStr.size()-1) != ')')
            {
                stream >> tempStr; //operator
                tempStr2 += tempStr;
                tempStr2 += " ";
            }
            stream >> tempStr;
            tempStr2 += tempStr;
            
            tempTree = new SyntaxTree(tempStr2);
        }
        else
        {
            tempTree = new SyntaxTree();
            stringstream ss(tempStr);
            ss >> tempTree -> data;
        }
        
        children.push_back(tempTree);
    }
}

bool isValid(string equation)
{
    if (equation[0]!='(' || equation[equation.size()-1]!=')') 
        return false;
    
    stringstream ss(equation);
    string str;
    
    while(ss)
    {
        ss >> str;
        if(str[0] == '(')
            str = str.substr(1,str.size()-1);
        if(str[str.size()-1] == ')')
            str = str.substr(0,str.size()-2);
        if(str != "+" && str != "-" &&
           str != "*" && str != "/" &&
           str != "(" && str != ")" &&
           str != " " && isdigit(str.at(0)) )
           {
               if(str != "equals" && str != "greater" &&
                  str != "less" && str != "if")
               {
                   return false;
               }
           }
    }
    return true;
}

double SyntaxTree::evaluateTree()
{
    return evaluateHelper(this);
}

double SyntaxTree::evaluateHelper(SyntaxTree* st)
{
    double result = st -> data;
    
    if(st->operation == "+")
    {
        //cout << "Is it going in hereeee???" << endl;
        if(children.size() == 1)
            return children.front()->data;
        if(children.size() == 0)
        {
            cerr << "Error: Invalid \n";
            return -9999999999;
        }
        else
        {
            list<SyntaxTree*> :: iterator i;
            for(i = children.begin(); i != children.end(); i++)
            {
                if(*i)
                {
                    if( (*i) -> operation == "")
                        result += (*i) -> data;
                    else
                        result += evaluateHelper(*i);
                }
            }
            result -= children.back()-> data;
            return result;
        }
    }
    else if(st->operation == "-")
    {
        if(children.size() == 1)
            return children.front()->data;
        if(children.size() == 0)
        {
            cerr << "Error: Invalid \n";
            return -9999999999;
        }
        else
        {
            list<SyntaxTree*> :: iterator i;
            for(i = children.begin(); i != children.end(); i++)
            {
                if(*i)
                {
                    if( (*i) -> operation == "")
                        result -= (*i) -> data;
                    else
                        result -= evaluateHelper(*i);
                }
            }
            result += children.back()-> data;
            return result;
        }
    }
    else if(st->operation == "/")
    {
        if(children.size() == 1)
            return children.front()->data;
        if(children.size() == 0)
        {
            cerr << "Error: Invalid \n";
            return -9999999999;
        }
        else
        {
            list<SyntaxTree*> :: iterator i = children.begin();
            if(*i)
                result = children.front() -> data;
            for(i++; i != children.end(); i++)
            {
                if(*i)
                {
                    if( (*i) -> operation == "")
                        result = result / (*i) -> data;
                    else
                        result = result / evaluateHelper(*i);
                }
            }
            result *= children.back()-> data;
            return result;
        }
    }
    else if(st->operation == "*")
    {
        if(children.size() == 1)
            return children.front()->data;
        if(children.size() == 0)
        {
            cerr << "Error: Invalid \n";
            return -99999999999;
        }
        else
        {
            list<SyntaxTree*> :: iterator i;
            for(i = children.begin(); i != children.end(); i++)
            {
                if(*i)
                {
                    if( (*i) -> operation == "")
                        result *= (*i) -> data;
                    else
                        result *= evaluateHelper(*i);
                }
            }
            result = result / children.back()->data;
            return result;
        }
    }
    //============================================================//
    //~ else if(st->operation == "greater")
    //~ {
        //~ if(children.size() != 2)
        //~ {
            //~ cerr << "Error: Invalid \n";
            //~ return -9999999999;
        //~ }
        //~ else
        //~ {
            //~ 
        //~ }
    //~ }
    //~ else if(st->operation == "less")
    //~ {
        //~ if(children.size() != 2)
        //~ {
            //~ cerr << "Error: Invalid \n";
            //~ return -9999999999;
        //~ }
    //~ }
    //~ else if(st->operation == "equals")
    //~ {
        //~ if(children.size() != 2)
        //~ {
            //~ cerr << "Error: Invalid \n";
            //~ return -9999999999;
        //~ }
    //~ }
    //~ else if(st->operation == "if")
    //~ {
        //~ if(children.size() != 2)
        //~ {
            //~ cerr << "Error: Invalid \n";
            //~ return -9999999999;
        //~ }
    //~ }
    //=========================================================
    else if(st->children.size() == 0)
    {
        return st-> data;
    }
    else
        cerr << "Invalid!!\n";
        return -999999999999;
}
