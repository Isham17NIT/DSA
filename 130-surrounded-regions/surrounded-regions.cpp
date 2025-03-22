class Solution 
{
public:
    int rows[4]={-1,0,1,0};
    int cols[4]={0,1,0,-1};
    bool isValid(int i,int j,int m,int n,vector<vector<bool>> &visited,vector<vector<char>>& board)
    {
        return i>=0 && i<m && j>=0 && j<n && !visited[i][j] && board[i][j]=='O';
    }
    void dfsVisit(vector<vector<char>>& board,int i,int j,int m,int n,vector<vector<bool>> &visited)
    {
        visited[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int newRow=i+rows[k];
            int newCol=j+cols[k];
            if(isValid(newRow,newCol,m,n,visited,board))
                dfsVisit(board,newRow,newCol,m,n,visited);
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        //first row
        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O' && !visited[0][j])
                dfsVisit(board,0,j,m,n,visited);
        }
        //last row
        for(int j=0;j<n;j++)
        {
            if(board[m-1][j]=='O' && !visited[m-1][j])
                dfsVisit(board,m-1,j,m,n,visited);
        }
        //first col
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O' && !visited[i][0])
                dfsVisit(board,i,0,m,n,visited);
        }
        //last col
        for(int i=0;i<m;i++)
        {
            if(board[i][n-1]=='O' && !visited[i][n-1])
                dfsVisit(board,i,n-1,m,n,visited);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j] && board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        return;
    }
};