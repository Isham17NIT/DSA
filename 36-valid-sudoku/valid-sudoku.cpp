class Solution 
{
public:
    int getGridNumber(int r,int c)
    {
        return r*3 + c;
    }
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<short> row(9,0);
        vector<short> col(9,0);
        vector<short> grid(9,0);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    int bitmask = 1 << (board[i][j]-'0'-1); //0 based indexing

                    int k=getGridNumber(i/3,j/3);

                    if(row[i] & bitmask || col[j] & bitmask || grid[k] & bitmask)
                        return false;
                    
                    //mark the current number as visited
                    row[i] |= bitmask;
                    col[j] |= bitmask;
                    grid[k] |= bitmask;
                }                
            }
        }
        return true;
    }
};