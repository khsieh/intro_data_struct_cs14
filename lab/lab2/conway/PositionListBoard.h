/* This game board does not keep track of the whole game board.  Instead, it 
   keeps track only of the full positions.  If there are only a small number of 
   full squares, this will save a lot of space.  The tradeoff is that it can be
   have slower run times.
   
   This class uses the default implementation of iterate(), which is horribly 
   inefficient.  The derived class EfficientPositionListBoard is much better.
*/

class PositionListBoard : public GameBoard
{
    struct Position
    {
        int x,y;
    };
    
    typedef list<Position> Positions; // why is this a list and not a vector?
    Positions posL;
    
public:
        
    /* loads an initial board position from a file */
    virtual void loadBoard(string file)
    {
        ifstream fin(file.c_str(),ifstream::in);        
        for (int row=0; fin; row++) {
            string linestr;
            getline(fin,linestr);
            for (unsigned col=0; col<linestr.size(); col++) {
                if (linestr[col]!=' ') {
                    Position tmpnode = {col,row};
                    posL.push_back(tmpnode);
                }
            }
        }   
    }

    /* rows/cols */
    virtual int minrow()
    {
        int miny=0; //numeric_limits<int>::max();
        for (Positions::iterator i=posL.begin(); i!=posL.end(); i++) {
            if (i->y<miny)
                miny=i->y;
        }
        return miny;
    }
    
    virtual int maxrow()
    {
        int maxy=numeric_limits<int>::min();
        for (Positions::iterator i=posL.begin(); i!=posL.end(); i++) {
            if (i->y>maxy)
                maxy=i->y;
        }
        return maxy+2;
    }

    virtual int mincol()
    {
        int minx=0;//numeric_limits<int>::max();
        for (Positions::iterator i=posL.begin(); i!=posL.end(); i++) {
            if (i->x<minx)
                minx=i->x;
        }
        return minx;
    }

    virtual int maxcol()
    {
        int maxx=numeric_limits<int>::min();
        for (Positions::iterator i=posL.begin(); i!=posL.end(); i++) {
            if (i->x>maxx)
                maxx=i->x;
        }
        return maxx+2;
    }

    /* getters/setters */
    virtual Square getsquare(int y, int x)
    { 
        for(Positions::iterator i = posL.begin(); i!= posL.end(); i++)
        {
            if(i->x == x && i->y == y)
                return FULL;
        }
        
        return EMPTY;
    }
    
    virtual void setsquare(int y, int x, Square s)
    {
        bool found = false;
        for (Positions::iterator i = posL.begin(); i!=posL.end(); i++)
        {
            if(i->x == x && i->y == y)
            {
                found = true;
                if(s == EMPTY)
                {
                    i = posL.erase(i);
                }
            }
        }
        
        if(s == FULL && found != true)
        {
            Position newcell = {x, y};
            posL.push_back(newcell);
        }
    }
};
