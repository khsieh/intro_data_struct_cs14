
// these are ANSI terminal control codes;
// see: https://en.wikipedia.org/wiki/Conway's_Game_of_Life#Rules for more info
string clearscreen = "\n\n\033[2J\033[1;1H";
string redbg = "\x1b[41m";
string blackbg = "\x1b[40m";
string graybg = "\x1b[47m";

/* The GameBoard class provides an interface to the Game of Life.  Every variant of the game
   is a child class.  The variants unique behavior is achieved by overriding GameBoard's 
   functionality.  Notice that GameBoard contains no member variables to represent the Game's
   state.  It will be up to the derived class to select which data structures to use to
   best implement game state.
*/
class GameBoard
{
protected:
    enum Square { EMPTY, FULL };

    /* prints a single square to the screen using the ANSI coloring
       FULL squares are red, EMPTY squares gray.
    */
    static void printSquare(Square s)
    {
        char out=' ';
        if (s==FULL)
            cout << redbg << out << blackbg;
        else
            cout << graybg << out << blackbg;
    }
    
    /* how many neighbors does the cell have?
    */
    int countneighbors(unsigned i,unsigned j)
    {
        unsigned neighbors=0;
        if (getsquare(i-1,j-1)==FULL) neighbors++;
        if (getsquare(i-1,j  )==FULL) neighbors++;
        if (getsquare(i-1,j+1)==FULL) neighbors++;
        if (getsquare(i  ,j-1)==FULL) neighbors++;
        //if (getsquare(i  ,j  )==FULL) neighbors++; don't count yourself!
        if (getsquare(i  ,j+1)==FULL) neighbors++;
        if (getsquare(i+1,j-1)==FULL) neighbors++;
        if (getsquare(i+1,j  )==FULL) neighbors++;
        if (getsquare(i+1,j+1)==FULL) neighbors++;
        return neighbors;
    }

    /* rows / cols */
    virtual int minrow() = 0;
    virtual int maxrow() = 0;
    virtual int mincol() = 0;
    virtual int maxcol() = 0;
    
    int rows() { return maxrow()-minrow(); }
    int cols() { return maxcol()-mincol(); }
    
public:
    virtual ~GameBoard() {};

    /* print the board */
    void print()
    {
        for (int i=minrow(); i<maxrow(); i++) {
            for (int j=mincol(); j<maxcol(); j++)
                printSquare(getsquare(i,j));
            cout << endl;
        }
    }
    
    /* steps through a single round of the game then prints the new board
       see https://en.wikipedia.org/wiki/Conway's_Game_of_Life#Rules for detailed rules
    */
    void iterate()
    {
        vector <vector <int> > neighborCount;
        
        // TODO: first determine how many neighbors each square has
        for(int i = 0; i < maxrow(); i++)
        {
            vector <int> neighbors;
            for(int j = 0; j < maxcol(); j++)
            {
                int neighborNum = countneighbors(i, j);
                neighbors.push_back(neighborNum);
            }
            neighborCount.push_back(neighbors);
        }
        
        // TODO: then update the board according to the rules
        for(unsigned i = 0; i < neighborCount.size(); i++)
        {
            for(unsigned j = 0; j < neighborCount.at(i).size(); j++)
            {
                int nCount = neighborCount.at(i).at(j);
                
                if( nCount < 2 && getsquare(i,j) == FULL)
                    setsquare(i,j,EMPTY);
                    
                else if(nCount >= 2 && nCount <= 3 && getsquare(i,j) == FULL)
                    setsquare(i,j,FULL);
                    
                else if(nCount > 3 && getsquare(i,j) == FULL)
                    setsquare(i,j,EMPTY);
                    
                else if(nCount == 3 && getsquare(i,j) == EMPTY)
                    setsquare(i,j,FULL);
            }
        }
    }
    
    /* loads an initial board position from a file */
    virtual void loadBoard(string file) = 0;

    /* getters/setters */
    virtual Square getsquare(int i, int j) = 0;
    virtual void setsquare(int i, int j, Square) = 0;
};
