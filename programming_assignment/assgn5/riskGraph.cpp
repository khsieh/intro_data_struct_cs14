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
// Assignment: <assignment 005>
//
// I hereby certify that the code in this file
// is ENTIRELY my own original work.
//=================================================================

#include <map>
#include <queue>
#include <stack>
#include <fstream>
#include <sstream>
#include <iostream>

#include "riskGraph.h"

using namespace std;

Graph::~Graph()
{
    map<string, Country*>::iterator i;
    for(i = Globe.begin(); i != Globe.end(); i++)
    {
        delete (i->second);
    }
}


void Graph::loadGlobe()
{
    string check;
    ifstream file("risk-board.graph");
    list <string> linkList;
    
    while(!file.eof())
    {
        file >> check;
        if( check == "node")
        {
            string name, t, nodeString;
            territory color;
            unsigned long int weight;
            
            getline(file,nodeString);
            stringstream ss(nodeString);
            ss >> name;
            while(name.at(name.size()-1) != '"')
            {
                string tempN;
                ss >> tempN;
                name += " ";
                name += tempN;
            }
            
            ss >> weight;
            ss >> t;
            //~ cout << name << endl;
            
            if(t  == "yellow")
                color = yellow;
            else if(t  == "green")
                color = green;
            else if(t  == "purple")
                color = purple;
            else if(t  == "blue")
                color = blue;
                
            name = name.substr(1,name.size()-2);
            
            Country *tempCountry = new Country(name, weight, color);
            Globe.insert( pair<string,Country*>(name, tempCountry) );
        }
        else
        {
            string countryLink;
            getline(file,countryLink);
            linkList.push_back(countryLink);
        }
    }
    
    list<string> :: iterator i;
    for(i = linkList.begin(); i != linkList.end(); i++)
    {
        string toLink;
        
        toLink = *i;
        string countryA, countryB;
        
        stringstream ss2(toLink);
        
        ss2 >> countryA;
        //~ cout << "A: " << countryA << endl;
        if(countryA.at(countryA.size()-1 ) != '"')
        {
            string temp;
            while(ss2 >> temp)
            {
                countryA += " ";
                countryA += temp;
                if(temp.find('"') != string :: npos)
                {
                    break;
                    //~ cerr << "dfasdfsaaaaaaa" << endl;
                }
                
            }
        }
                
        countryA = countryA.substr(1,countryA.size()-2);
        //~ cout << countryA << endl;
        
        ss2 >> countryB;
        //~ cout << countryB << endl;
        if(countryB.at(countryB.size()-1 ) != '"')
        {
            string temp;
            while(ss2 >> temp)
            {
                countryB += " ";
                countryB += temp;
                if(temp.find('"') != string :: npos)
                {
                    break;
                    //~ cerr << "dfasdfsaaaaaaa" << endl;
                }
                
            }
        }
                
        countryB = countryB.substr(1,countryB.size()-2);
        //~ cout << countryB << endl;
        
        Country* x = Globe.find(countryA) -> second;
        Country* y = Globe.find(countryB) -> second;
        x -> neighbors.push_back(y);
        
    }
}

//~ const double WALKING_DIST_TO_MORDOR = -1;

void Graph::shortestPath(const string & start, const string & goal)
{
    map<Country*, Country*> previous;
    
    map<string, Country* > :: iterator i;
    for(i = Globe.begin(); i != Globe.end(); i++)
    {          
        if( i -> first == start)
            i -> second -> distance = 0;
        else
            i -> second -> distance = -1;
    }
    
    queue< Country* > Q;
    
    while(!Q.empty())
    {
        Country* current = Q.front();
        Q.pop();
        list< Country*> :: iterator i;
        for(i = current->neighbors.begin(); 
            i !=  current->neighbors.end(); i++)
        {
            unsigned long int d = current->distance + (*i) -> landWeight;
            
            if(current->distance > d)
            {
                current->distance = d;
                Q.push( *i );     
                (*i) -> previous = current;
            }
        }
    }
    
    map<string, Country*>::iterator final = Globe.find(goal);
    
    stack<string> route;
    route.push(goal);
    
    Country* step = final-> second -> previous;
    string tempStr = step -> name;
    while(tempStr != start)
    {
        route.push(tempStr);
        step = step -> previous;
        tempStr = step -> name;
    }
    route.push(start);
    
    while(!route.empty())
    {
        cout << route.top() << endl;
        route.pop();
    }
}

void Graph::print() {
    for ( map<string,Country*>::iterator i = Globe.begin(); i != Globe.end(); ++i ) {
        cout << i->second->name << endl;
        
        for ( list<Country*>::iterator j = i->second->neighbors.begin(); j != i->second->neighbors.end(); ++j ) {
            cout << "- " << (*j)->name << endl;
        }
    }
}
