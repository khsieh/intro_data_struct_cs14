/* This board stores the matrix explicitly, but it does so using a multi-way linked list.
   This lets us efficiently dynamically grow and shrink the board to be the appropriate size.
*/

class PositionGridBoard : public GameBoard
{
    enum Direction { North, South, East, West };
    
    struct Position
    {
        Position *neighbors[4];
        Square val;
    };
    
    Position origin;    
    
    /* when a boundary is reached, call this function to extend the boundary in that direction;
       it must maintain the property that the board is a rectangle!
    */
    void extendBoard(Direction)
    {
        // TODO: implement function
    }
    
    /* shrinks the board into the minimum bounding rectangle that will cover the pieces
    */
    void shrinkBoard()
    {
        // TODO: implement function
    }
    
public:
    PositionGridBoard();
    virtual ~PositionGridBoard();
    
    virtual int rows()
    {
        // TODO: implement function
    }
    
    virtual int cols()
    {
        // TODO: implement function
    }
    
    /* getter and setter for each square */
    virtual Square getsquare(int i, int j)
    {
        // TODO: implement function
    }
    
    virtual void setsquare(int i, int j, Square s)
    {
        // TODO: implement function
    }
    
    /* loads a board from a file
    */
    void loadBoard(string file)
    {
        // TODO: implement function
    }
};
