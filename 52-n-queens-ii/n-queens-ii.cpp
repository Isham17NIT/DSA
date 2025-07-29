class Solution {
private:
    int isSafe(int i,int j,int n,vector<vector<int>> &board)
    {
        //check in col
        for(int k=0;k<i;k++)
        {
            if(board[k][j]==1)
                return false;
        }
        //check in upper left diagonal
        for(int x=i-1,y=j-1;x>=0 && y>=0;x--,y--)
        {
            if(board[x][y]==1)
                return false;
        }
        //check in upper right diagonal
        for(int x=i-1, y=j+1;x>=0 && y<n;x--,y++)
        {
            if(board[x][y]==1)
                return false;
        }
        return true;
    }
    //place the queens row wise
    void placeQueens(int row,int n,int &ans,vector<vector<int>> &board)
    {
        if(row==n) //all queens placed
        {
            ans+=1;
            return;
        }
        //check in which columns can the queen be placed
        for(int j=0;j<n;j++)
        {
            if(isSafe(row,j,n,board))
            {
                board[row][j]=1; //place the queen
                placeQueens(row+1,n,ans,board);
                board[row][j]=0; //backtrack
            }
        }
    }
public:
    int totalNQueens(int n) 
    {
        int ans=0;
        vector<vector<int>> board(n,vector<int>(n,0));
        placeQueens(0,n,ans,board);
        return ans;
    }
};