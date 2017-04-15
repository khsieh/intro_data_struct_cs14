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

#ifndef _MAP_CPP_
#define _MAP_CPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <string>
#include "map.h"

//========================CONSTRUCTORS=========================//
//default constructor
template <typename K, typename V>
Map<K,V>::Map()
:left(NULL), right(NULL)
{}
//constructor with K and V parameters
template <typename K, typename V>
Map<K,V>::Map(const K &k, const V &v)
:key(k),value(v),left(NULL), right(NULL)
{}
//==========================BIG THREE==========================//
//DESTRUCTOR
template <typename K, typename V>
Map<K,V>::~Map()
{
    clear();
}
//COPY CONSTRUCTOR map m(const &m);
template <typename K, typename V>
Map<K,V>::Map(const Map &m)
{
    this -> key = m.key;
    this -> value = m.value;
    this -> left = m.left;
    this -> right = m.right;
}
//COPY ASSIGN OPERATOR map1 = map2;
template <typename K, typename V>
Map<K,V>& Map<K,V>::operator = (const Map &m)
{
    this -> key = m.key;
    this -> value = m.value;
    this -> left = m.left;
    this -> right = m.right;
    return *this;
}

//============================IO==============================//

/**You will use the file format of the "Internet Dictionary Project"**/
template <typename K, typename V>
void Map<K,V>::loadFromFile(std::string file)
{
    ifstream input;
    string line;
    K word;
    V def;
    
    input.open(file.c_str());
    while(!input.eof())
    {
        while(getline(input,line) )
        {
            if(line.at(0) != '#')
            {
                word = line.substr(0,line.find('\t'));
                def = line.substr(line.find('\t') + 1, line.size() - 1);
                //~ cout << word << "\t" << def << endl;
                insert(word, def);
            }
        }
    }
    input.close();
}

template <typename K, typename V>
void Map<K,V>::saveToFile(std::string file)
{
    ofstream save_file;
    save_file.open(file.c_str());    
    
    saveHelper(save_file);
    
    save_file.close();
}

template <typename K, typename V>
void Map<K,V>::saveHelper(ofstream & file)
{
    file << key << "\t" << value << endl;
    if(right) right -> saveHelper(file);
    if(left)  left  -> saveHelper(file);
}

//===========================MUTATORS==========================//

/**adds (K,V) into the map, overwriting the previous value if it exists**/
template <typename K, typename V>
void Map<K,V>::insert (const K &k, const V &v)
{
    
    if(key == "" && value =="")
    {
        key = k;
        value = v;
        return;
    }
    if(k == key)
    {
        //same key
        value += "\n";
        value += v;
    }
    else if(k > key)
    {
        if(right)
            right -> insert(k,v);
        else
            right = new Map(k,v);   
    }
    else if( k < key)
    {
        if(left)
            left -> insert(k,v);
        else
            left = new Map(k,v);
    }
    
    balanceSub();
}

/** erases (K,V) from the map **/
template <typename K, typename V>
void Map<K,V>::erase (const K &k)
{
    if(k == key)
    {
        if( (left && !right) || (right && !left) )
        {
            if(left && !right)
            {
                //reconnect
                Map <string, string> *newNode = left;
                delete this;
                *this = newNode;
            }
            else
            {
                //reconnect
                Map <string, string> *newNode = right;
                delete this;
                *this = *newNode;
            }
        }
        
        if(right && left)
        {
            //delete and balance
            Map<string,string> *right_sub = right;
            Map<string,string> *tempNode = NULL;
            Map<string,string> *newRoot = NULL;
            
            while(right_sub->left->left)
            {
                right_sub = right_sub->left;
            }
            
            if(right_sub ->left ->right)
            {
                newRoot = right_sub -> left -> right;
            }
            
            tempNode = right_sub;
            right_sub = right_sub -> left;
            
            tempNode -> left = NULL;
            
            right_sub -> left = this -> left;
            right_sub -> right = this ->right;
            
            *this = *right_sub;
            
            if(newRoot)
                tempNode -> left = newRoot;
            
            return;
        }
    }
    
    else if(k > key && right)
    {
        if(right -> key == k && !right->left && !right->right)
        {
            delete right;
            right = NULL;
            return;
        }
        return right -> erase(k);
    }
    else if(k < key && left)
    {
        if(left -> key == k && !left->left && !left->right)
        {
            delete left;
            left = NULL;
            return;
        }
        return left -> erase(k);
    }
    else
        return;
    
}


template <typename K, typename V>
void Map<K,V>::clear()
{
    if(right)
    {
        right -> clear();
        delete right;
        right = NULL;
    }
    if(left)
    {
        left -> clear();
        delete left;
        left = NULL;
    }
    if(!right && !left)
        delete *this;
    
}

//==========================ACCESSORS==========================//


template <typename K, typename V>
int Map<K,V>::size() const
{
    int s = 0;
    if(right)
        s += right -> size();
    if(left)
        s += left -> size();
    if(!right && !left)
        return 1;
    s++;
    return s;
}

template <typename K, typename V>
int Map<K,V>::height() const
{
    int right_h = 0;
    int left_h = 0;
    
    if(right)
    {
        right_h += right->height();
        //cout << right_h << endl;
        right_h++;
    }
    if(left) 
    {
        left_h += left->height();
        //cout << left_h << endl;
        left_h++;
    }
    
    if(!right && !left)
        return 1;
    
    if(left_h > right_h)
        return left_h;
    else
        return right_h;
    
}


template <typename K, typename V>
int Map<K,V>::balanceFactor() const
{
    int left_h = 0;
    int right_h = 0;
    
    if(left)
        left_h = left -> height();
        
    if(right)
        right_h = right -> height();
    
    return left_h - right_h;
}


template <typename K, typename V>
bool Map<K,V>::isMember (const K &k)
{
    if(k == key)
        return true;
    if(k > key && right)
        return right -> isMember(k);
    if(k < key && left)
        return left -> isMember(k);
    return false;
}

template <typename K, typename V>
V Map<K,V>::lookup (const K &k) const
{
    if(k == key)
        return value;
    if(k > key && right)
        return right -> lookup(k);
    if(k < key && left)
        return left -> lookup(k);
    
    cerr << "Error: This Key Does Not Exist.\nAbort\n";
    exit(1);
}

template <typename K, typename V>
K Map<K,V>::closestKey(const K&k) const
{
    if(k == key)
    {
        return k;
    }
    else if( k > key && right)
    {
        return right -> closestKey(k);
    }
    else if( k < key && left)
    {
        return left -> closestKey(k);
    }
    else
        return key;
}

//==========================MY HELPER===========================//

template <typename K, typename V>
void Map<K,V>::balanceSub()
{
    if(this -> balanceFactor() > 1)
    {
        //rotate left
        if(this -> left -> balanceFactor() > 0)
        {
            //LL
            rotateLL();
        }
        else
        {
            //LR
            rotateLR();
        }
    }
    else if(this -> balanceFactor() < -1)
    {
        //rotate right
        if(this -> right -> balanceFactor() > 0)
        {
            //RL
            rotateRL();
        }
        else
        {
            //RR
            rotateRR();
        }
    }
}


template <typename K, typename V>
void Map<K,V>::rotateLL()
{
    K tempK = key;
    V tempV = value;
    Map<K,V> *tempChild = right;
    key = left -> key;
    value = left -> value;
    right = left -> right;
    left -> key = tempK;
    left -> value =tempV;
    left -> right = tempChild;
    
    Map<K,V> *tempChild2 = right;
    right = left;
    left = left -> left;
    right -> left = tempChild2;
}
template <typename K, typename V>
void Map<K,V>::rotateLR()
{
    left -> rotateRR();
    rotateLL();
}
template <typename K, typename V>
void Map<K,V>::rotateRR()
{
    K tempK = key;
    V tempV = value;
    Map<K,V> *tempChild = left;
    key = right -> key;
    value = right -> value;
    left = right -> left;
    right -> key = tempK;
    right -> value = tempV;
    right -> left = tempChild;
    
    Map<K,V>* tempChild2 = left;
    left = right;
    right = right -> right;
    left -> right = tempChild2;
}
template <typename K, typename V>
void Map<K,V>::rotateRL()
{
    right -> rotateLL();
    rotateRR();
}
//==========================DISPLAY=============================//

template <typename K, typename V>
void Map<K,V> :: printMap() 
{
    int i = 0;

    helper(i);
}

template <typename K, typename V>
void Map<K,V>::helper( int level ) 
{
    cout << key << endl;

    if ( left ) 
    {
        for ( int i = 0; i < level; ++i )
            cout << "--";
        cout << "L-";
        left -> helper( level+1 );
    }
    
    if ( right ) 
    {
        for ( int i = 0; i < level; ++i )
            cout << "--";
        cout << "R-";
        right -> helper( level+1);
    }
}

#endif 
