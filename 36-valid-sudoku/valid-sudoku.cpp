class Solution 
{
private:
    int getGridNum(int i,int j)
    {
        return 3*(i/3) + (j/3);
    }
    bool validate(int num,vector<int> rows,vector<int> cols,vector<int> grids,int rowNo,int colNo,int gridNo)
    {
        int mask=(1<<(num-1));
        if(rows[rowNo] & mask)
            return false;
        else if(cols[colNo] & mask)
            return false;
        else if(grids[gridNo] & mask)
            return false;
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        vector<int> rows(9,0);
        vector<int> cols(9,0);
        vector<int> grids(9,0);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                int num=board[i][j]-'0';
                int gridNum=getGridNum(i,j);
                if(!validate(num,rows,cols,grids,i,j,gridNum))
                    return false;
                int mask=(1<<(num-1));
                rows[i] |= mask;
                cols[j] |= mask;
                grids[gridNum] |= mask;
            }
        }
        return true;
    }
};