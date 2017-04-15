#include <iostream>
#include <vector>

using namespace std;

template <class T>
class STACK
{
    private:
        vector<T> v;
        unsigned int v_cap;
    public:
        //C'tor
        STACK()
        :v(), v_cap(10)
        {}
        
        //PUSH
        void push(T t)
        {
            /**
            if(v.empty())
                v.push_back(t);
            else
            {
                for (unsigned i = v.size(); i > 0; i--)
                {
                    v[i] = v[i - 1];
                }
                
                v[0] = t;
            }
            */ 
            
            if( v.size() < v_cap)
            {
                v.push_back(t);
            }
        }
        
        //POP
        void pop()
        {
            /**
            if(v.empty())
                return;
            for (unsigned i = 0; i < v.size(); i++)
            {
                v[i] = v[i+1];
            }
            
            v.pop_back();
            */
            v.pop_back();
        }
        
        //PRINT VECTOR
        void print_v()
        {
            if(v.empty())
            {
                cout << "stack vector is empty" << endl;
                return;
            }
            for(unsigned i = 0; i < v.size(); i++)
            {
                cout << v.at(i) << " ";
            }
            cout << endl;
            
        }
};

int main()
{
    cout << "=========ex2========" << endl;
    
    STACK<int> s;
    
    s.push(12);
    s.print_v();
    s.push(11);
    s.print_v();
    s.push(10);
    s.print_v();
    s.pop();
    s.print_v();
    
    return 0;
}
