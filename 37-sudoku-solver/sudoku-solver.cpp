class Solution 
{
private:
    bool bitCheck(int num,int mask)
    {
        return (num & mask) ? false : true;
    }
    bool findSolution(vector<vector<char>>& board,int i,int j,vector<int> &rows,vector<int> &cols,vector<int> &grids)
    {
        if(i==9 && j==0) //solution found
            return true;
        if(board[i][j]!='.')
        {
            if(j<8)
                return findSolution(board,i,j+1,rows,cols,grids);
            else
                return findSolution(board,i+1,0,rows,cols,grids);
        }
        // else
        for(int k=1;k<=9;k++)
        {
            int mask = (1 << (k-1));
            int gridNum = (i/3)*3 + (j/3);
            if(bitCheck(rows[i],mask) && bitCheck(cols[j],mask) && bitCheck(grids[gridNum],mask))
            {
                board[i][j] = k+'0';
                rows[i] |= mask;
                cols[j] |= mask;
                grids[gridNum] |= mask;

                int nextRow = i, nextCol=j+1;
                if(j==8)
                {
                    nextRow = i+1;
                    nextCol = 0;
                }
                if(findSolution(board,nextRow,nextCol,rows,cols,grids))
                    return true;

                // backtrack
                board[i][j] = '.';
                rows[i] &= ~mask;
                cols[j] &= ~mask;
                grids[gridNum] &= ~mask;
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        vector<int> rows(9,0);
        vector<int> cols(9,0);
        vector<int> grids(9,0);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    int n = board[i][j]-'0';
                    int mask = (1 << (n-1));
                    rows[i] |= mask;
                    cols[j] |= mask;
                    int gridNo = (i/3) * 3 + (j/3);
                    grids[gridNo] |= mask;
                }
            }
        }
        findSolution(board,0,0,rows,cols,grids);
        return;
    }
};