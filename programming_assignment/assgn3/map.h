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

#ifndef _MAP_H_
#define _MAP_H_

#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

template <typename K, typename V>
class Map
{
    private:
        K key;
        V value;
        
        Map<K,V> *left, *right;

    public:
        //========================CONSTRUCTORS=========================//
        //default constructor
        Map();//*
        //constructor with K and V parameters
        Map(const K &k, const V &v);//*
        //==========================BIG THREE==========================//
        //DESTRUCTOR
        ~Map();//*
        
        //COPY CONSTRUCTOR map m(const &m);
        Map(const Map &m);//*
        
        //COPY ASSIGN OPERATOR map1 = map2;
        Map& operator = (const Map &m);//*
        
        //============================IO==============================//
        
        /**You will use the file format of the "Internet Dictionary Project"**/
        void loadFromFile(std::string file); //* 
        
        void saveToFile(std::string file);
        //===========================MUTATORS==========================//

        /**adds (K,V) into the map, overwriting the previous value if it exists**/
        void insert (const K &k, const V &v); //*
        
        /** erases (K,V) from the map **/
        void erase (const K&);
        
        /** erases all elements from the map **/
        void clear();//*

        //==========================ACCESSORS==========================//
        
        /** returns the number of (K,V) pairs stored in the map **/
        int size() const;//*

        /** returns the height of the tree **/
        int height() const;//*
        
        /** returns the tree's balance factor **/
        int balanceFactor() const;//*
        
        /** return true if K is a valid key, false otherwise **/
        bool isMember (const K&);//*
        
        /** returns the V associated with K; if K is not a valid key, 
         * then print an error and abort the program **/
        V lookup (const K&) const;//*
        
        /** returns the key that is most similar to the key passed in **/
        K closestKey(const K&) const;//*
        
        /** returns the value of the key that is most similar to the key passed in.
         * Like lookup, but never aborts **/
        V lookupSimilar (const K &k) const { return lookup(closestKey(k)); }//*
        
        //==========================MY HELPER===========================//
        /** to check if a node is AVL balanced **/
        void balanceSub();//*
        void saveHelper(ofstream & file);
        void rotateLL();
        void rotateLR();
        void rotateRR();
        void rotateRL();
        
        
        //==========================DISPLAY=============================//
        void printMap();//*
        void helper( int level );//*
};

#include "map.cpp"
#endif //_MAP_H_
