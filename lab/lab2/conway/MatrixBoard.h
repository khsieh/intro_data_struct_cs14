/* The finite board has its size fixed at whatever the initial input size was
   Spaces that do not fit within the board are always EMPTY.
   
   This class is provided fully implemented.
*/

class MatrixBoard : public GameBoard
{
protected:
    vector <vector<Square> > board;
    
    virtual int minrow() { return 0; };
    virtual int maxrow() { return board.size(); };
    virtual int mincol() { return 0; };
    virtual int maxcol() { return board[0].size(); };
    
    /* getter and setter for each square */
    virtual Square getsquare(int i, int j)
    {
        if (i>0 && j>0 && i<rows() && j<cols())
            return board[i][j];
        return EMPTY;
    }

    virtual void setsquare(int i, int j, Square s)
    {
        if (i>0 && j>0 && i<rows() && j<cols())
            board[i][j]=s;
    }

public:
    virtual ~MatrixBoard() {};
        
    /* loads a board from a file
    */
    void loadBoard(string file)
    {
        ifstream fin(file.c_str(),ifstream::in);
        
        vector<vector<Square> > ret;
        while (fin) {
            string linestr;
            getline(fin,linestr);
            vector<GameBoard::Square> lineboard;
            for (unsigned i=0; i<linestr.size(); i++) {
                if (linestr[i]==' ') 
                    lineboard.push_back(EMPTY);
                else
                    lineboard.push_back(FULL);
            }
            if (lineboard.size()>0)
                ret.push_back(lineboard);
        }
        board=ret;
    }
};
