#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

/*
given a string with a bunch of parenthesis, and a position of an opening parenthesis,
findMatchingParen returns the location of the corresponding closing parenthesis.

NOTE: str[start] MUST be equal to '(' for this function to work correctly
*/
size_t findMatchingParen(string str, size_t start)
{
    int parens=0;
    for (unsigned i=start; i<str.size(); i++) {
        if (str[i]=='(') parens++;
        if (str[i]==')') parens--;
        if (parens==0) return i;
    }
    return string::npos;
}

/*
A binary tree class.  You must convert this class so that any node can have an 
arbitrary number of branches.
*/
template <typename T> class Tree
{
private:
    T data;
    list <Tree<T>*> subtrees;
    //~ Tree<T>* left;
    //~ Tree<T>* right;

    /*
    loads a tree from a string.  All trees are enclosed in parenthesis.  The first "word" inside 
    the parenthesis is the data stored at the root.  Everything else must be enclosed in parentheses
    and are subtrees.
    */
    void loadTree(string str)
    {
        // by default, we do not have any subtrees
        //~ left=NULL;
        //~ right=NULL;
        //~ Tree<T>* nulltree = NULL;
        //~ subtrees.push_back(nulltree);

        // our tree format says every tree must be enclosed in parentheses.  Let's verify it.
        if (str[0]!='(' || str[str.size()-1]!=')') {
            cerr << "error in loadTree(): string \"" << str << "\" not enclosed in parenthesis." << endl;
            return;
        }
        
        // removes the parentheses from the string
        str=str.substr(1,str.size()-2);

        // create a stream and load the root's data point
        stringstream stream(str);
        stream >> data;
        
        
        while(str.find('(') != string::npos && str.find(')') != string::npos)
        {
            int firstOpenParen = str.find('(');
            int firstCloseParen = findMatchingParen(str, firstOpenParen);
            if(firstOpenParen != string::npos && firstCloseParen != string::npos)
            {
                string newstr = str.substr(firstOpenParen,firstCloseParen - firstOpenParen +1);
                Tree<T> * subtree_ptr = new Tree<T> (newstr);
                subtrees.push_back(subtree_ptr);
                str=str.substr(firstCloseParen + 1);
            }
        }
        
        //~ // get left subtree        
        //~ int firstOpenParen=str.find('(');
        //~ int firstCloseParen=findMatchingParen(str,firstOpenParen);
        //~ if (firstOpenParen != string::npos && firstCloseParen != string::npos) {
            //~ string leftstr=str.substr(firstOpenParen,firstCloseParen-firstOpenParen+1);
            //~ left = new Tree<T>(leftstr);
        //~ }
//~ 
        //~ // get right subtree
        //~ int secondOpenParen=str.find('(',firstCloseParen);
        //~ int secondCloseParen=findMatchingParen(str,secondOpenParen);
        //~ if (secondOpenParen != string::npos && secondCloseParen != string::npos) {
            //~ string rightstr=str.substr(secondOpenParen,secondCloseParen-secondOpenParen+1);
            //~ right = new Tree<T>(rightstr);
        //~ }
    }

public:
    Tree(string t) {loadTree(t);}
    
    ~Tree() 
    {
        typename list <Tree <T> *>:: iterator i; 
        for(i = subtrees.begin(); i != subtrees.end(); i++)
        {
            if(*i)
                delete (*i);
        }   
    }
    
    string depthFirst()
    {
        stringstream ret;
        ret << data << " ";
        typename list <Tree <T> *>:: iterator i; 
        for(i = subtrees.begin(); i != subtrees.end(); i++)
        {
            if(*i)
                ret << (*i)-> depthFirst();
        }   
        //~ if (left) ret << left->depthFirst();
        //~ if (right) ret << right->depthFirst();
        return ret.str();
    }
    
    string breadthFirst()
    {
        queue <Tree <T>* > Q;
        stringstream ret;
        
        Q.push(this);
        
        ret << data << " ";
        
        typename list <Tree <T>* > :: iterator i;
        
        while(!Q.empty())
        {
            Tree *tmpTree = Q.front();
            Q.pop();
            
            for(i = tmpTree -> subtrees.begin(); i != tmpTree -> subtrees.end(); i++)
            {
                Q.push(*i);
                ret << (*i) -> data << " ";
            }
        }
        
        return ret.str();
    }
};

/*
Test cases!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Awesome!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
int main()
{
    // these will print fine
    cout << endl;
    cout << "binary trees:" << endl << "--------------" << endl;
    
    Tree<string> t1("(me (mom (grandma) (grandpa)  ) (dad (granny) (grandad) ) )");
    cout << "t1.depth=" << t1.depthFirst() << endl;
    cout << "t1.breadth=" << t1.breadthFirst() << endl << endl;

    Tree<int> t2("(1 (2) (3 (4) (5)))");
    cout << "t2.depth=" << t2.depthFirst() << endl;
    cout << "t2.breadth=" << t2.breadthFirst() << endl << endl;
        
    // these need a more flexible tree
    cout << endl;
    cout << "bigger trees:" << endl<< "--------------" << endl;
    
    Tree<string> t3("(root (sub1 (subsub1) (subsub2) (subsub3)) (sub2) (sub3) (sub4) (sub5) )");
    cout << "t3.depth=" << t3.depthFirst() << endl;
    cout << "t3.breadth=" << t3.breadthFirst() << endl << endl;
    
    Tree<char> t4("(a (b (c) (d) (e)) (f) (g (h) (i) (j)) )");
    cout << "t4=" << t4.depthFirst() << endl;
    cout << "t4.breadth=" << t4.breadthFirst() << endl << endl;
    
    // not valid trees
    cout << endl;
    cout << "invalid trees:" << endl << "--------------" << endl;
    Tree<int> t_error1("(1 (2) (3 (4) (5 ");
    cout << "t_error1.depth=" << t_error1.depthFirst() << endl;
    cout << "t_error1.breadth=" << t_error1.breadthFirst() << endl << endl;

    Tree<char> t_error2("(1 1 1)");
    cout << "t_error2.depth=" << t_error2.depthFirst() << endl;
    cout << "t_error2.breadth=" << t_error2.breadthFirst() << endl << endl;
}
