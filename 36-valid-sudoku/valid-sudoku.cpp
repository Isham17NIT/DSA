class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        //row check
        for(int i=0;i<9;i++)
        {
            vector<bool> visited(9,false);
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.' && visited[board[i][j]-'0'-1])
                    return false;
                if(board[i][j]!='.')
                    visited[board[i][j]-'0'-1]=true;
            }
        }
        //col check
        for(int j=0;j<9;j++)
        {
            vector<bool> visited(9,false);
            for(int i=0;i<9;i++)
            {
                if(board[i][j]!='.' && visited[board[i][j]-'0'-1])
                    return false;
                if(board[i][j]!='.')
                    visited[board[i][j]-'0'-1]=true;
            }
        }
        //grid check
        vector<vector<int>> gridStart = {{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
        for(int k=0;k<9;k++)
        {
            vector<bool> visited(9,false);
            int row=gridStart[k][0];
            int col=gridStart[k][1];
            for(int i=row;i<row+3;i++)
            {
                for(int j=col;j<col+3;j++)
                {
                    if(board[i][j]!='.' && visited[board[i][j]-'0'-1])
                        return false;
                    if(board[i][j]!='.')
                        visited[board[i][j]-'0'-1]=true;
                }
            }
        }
        return true;
    }
};