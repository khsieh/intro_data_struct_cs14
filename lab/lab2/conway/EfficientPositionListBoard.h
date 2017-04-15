/* This game board re-implements the iterate function so that it is more efficient
   when used on position lists.
*/

class EfficientPositionListBoard : public PositionListBoard 
{    
public:
        
    /* steps through a single round of the game then prints the new board
       see https://en.wikipedia.org/wiki/Conway's_Game_of_Life#Rules for detailed rules
    */
    void iterate()
    {
        //counting all the neighbors of the alive cells
        vector <vector <int> > neighborCount;
        for (Positions::iterator i = posL.begin(); i!=posL.end(); i++)
        {
            int curx = i -> x;
            int cury = i -> y;
            int neighbors = countneighbor(curx,cury);
            
            neighborCount[curx][cury] = neighbors;
        }
        
        //UPDATE TO_BE_ALIVE list
        Positions TBAlive;//, TBDead;
        //TBAlive
        for (Positions::iterator i = PosL.begin(); i!= posL.end(); i++)
        {
            int curx = i -> x;
            int curt = i -> y;
            if(neighborCount[curx][cury] == 2 || 
               neighborCount[curx][cury] == 3)
               {
                   Position newcell = {curx, cury};
                   TBAlive.push_back(newcell);
               }
            
            if(curx != 0 && cury != 0)
            {
               if(countneighbor(curx-1,cury  ) == 3)
               {
                   Position newcell = {curx-1,cury};
                   TBAlive.push_back(newcell);
               }
               if(countneighbor(curx-1,cury+1) == 3)
               {
                   Position newcell = {curx-1,cury+1};
                   TBAlive.push_back(newcell);
               }
               if(countneighbor(curx  ,cury-1) == 3)
               {
                   Position newcell = {curx,cury-1};
                   TBAlive.push_back(newcell);
               }
               if(countneighbor(curx-1,cury-1) == 3)
               {
                   Position newcell = {curx-1,cury-1};
                   TBAlive.push_back(newcell);
               }
               
               if(countneighbor(curx  ,cury+1) == 3)
               {
                   Position newcell = {curx,cury+1};
                   TBAlive.push_back(newcell);
               }
               if(countneighbor(curx+1,cury-1) == 3)
               {
                   Position newcell = {curx+1,cury-1};
                   TBAlive.push_back(newcell);
               }
               if(countneighbor(curx+1,cury  ) == 3)
               {
                   Position newcell = {curx+1,cury};
                   TBAlive.push_back(newcell);
               }
               if(countneighbor(curx+1,cury+1) == 3)
               {
                   Position newcell = {curx+1,cury+1};
                   TBAlive.push_back(newcell);
               }
               
           }
        }
        PosL = TBAlive;
        
        //Update TBDead list
        //~ for(Position::iterator i = PosL.begin(); i!=PosL.end(); i++)
        //~ {
            //~ int curx = i -> x;
            //~ int cury = i -> y;
            //~ if(neighborCount[curx][cury] < 2 || neighborCount[curx][cury] > 3)
            //~ {
                //~ Position newcell = {curx, cury};
                //~ TBDead.push_back(newcell);
            //~ }
            //~ 
        //~ }
        
    }
};
