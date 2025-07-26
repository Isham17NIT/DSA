class Solution 
{
private:
    int rows[4]={-1,0,1,0};
    int cols[4]={0,1,0,-1};
    bool isValid(int i,int j,int m,int n,vector<vector<char>>& board,vector<vector<bool>> &visited)
    {
        return i>=0 && i<m && j>=0 && j<n && !visited[i][j] && board[i][j]=='O';
    }
    void bfs(int i,int j,int m,int n,vector<vector<char>>& board,vector<vector<bool>> &visited)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]=true;
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int newRow=p.first+rows[k];
                int newCol=p.second+cols[k];
                if(isValid(newRow,newCol,m,n,board,visited)){
                    q.push({newRow,newCol});
                    visited[newRow][newCol]=true;
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) 
    {
        int m=board.size(), n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            if(!visited[i][0] && board[i][0]=='O')
                bfs(i,0,m,n,board,visited);
            if(!visited[i][n-1] && board[i][n-1]=='O')
                bfs(i,n-1,m,n,board,visited);
        }
        for(int i=1;i<n-1;i++)
        {
            if(!visited[0][i] && board[0][i]=='O')
                bfs(0,i,m,n,board,visited);
            if(!visited[m-1][i] && board[m-1][i]=='O')
                bfs(m-1,i,m,n,board,visited);
        }
        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(!visited[i][j])
                    board[i][j]='X';
            }
        }
    }
};