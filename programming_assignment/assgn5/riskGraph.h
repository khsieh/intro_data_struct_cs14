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
#ifndef _RISK_GRAPH_H_
#define _RISK_GRAPH_H_

#include <map>
#include <list>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

enum territory{green, yellow, purple, blue};

struct Country
{
    string name;
    unsigned long int landWeight;
    unsigned long int distance;
    territory color;
    
    list< Country* > neighbors;
    Country* previous;
    
    Country(string n, unsigned long int w, territory c)
    :name(n), landWeight(w), color(c)
    {}
};

class Graph
{
  private:
    map<string, Country*> Globe;
    
  public:
    ~Graph();
    //stroe node to be made in one list
    // edge to be made in one list
    //make node using struct and thorw in map
    // go through and assign the neighbors
    void loadGlobe();
    //use the Dijkstra's Algorithm to find the shortest path
    void shortestPath(const string &, const string &);
    void print();
};

#endif //_RISK_GRAPH_H_
