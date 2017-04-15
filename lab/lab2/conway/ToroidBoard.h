/* A toroid is a board that loops forever.  As soon as you go off the right 
   side of the screen, you reappear on the other side.  We can implement this
   feature by changing the get/setsquare functions only.
*/

class ToroidBoard : public MatrixBoard
{
public:
    virtual ~ToroidBoard() {};
    
    virtual Square getsquare(int i, int j)
    {
        // TODO: implement function
        
        if(i < 0)
            i = i + rows();
        if(j < 0)
            j = j + cols();
        if(i >= rows())
            i = i - rows();
        if(j >= cols())
            j = j -cols();
             
        return board[i][j];
        
        
        
        //~ if (i>0 && j>0 && i<rows() && j<cols())
            //~ return board[i][j];
            
        //~ if(i == rows() || j == cols() )
        //~ {
            //~ if(i == rows() && j != cols()  )
                //~ i = minrow();
            //~ 
            //~ if(i != rows() && j == cols() )
                //~ j = mincol();
            //~ 
            //~ if(i == rows() && j == cols() )
            //~ {
                //~ i = minrow();
                //~ j = mincol();
            //~ }
            //~ return board[i][j];
        //~ }
        
        //~ return EMPTY;
    }

    virtual void setsquare(int i, int j, Square s)
    {
        // TODO: implement function
        
        if(i < 0)
            i = i + rows();
        if(j < 0)
            j = j + cols();
        if(i >= rows())
            i = i - rows();
        if(j >= cols())
            j = j -cols();
            
        board[i][j] = s;
    }
};
