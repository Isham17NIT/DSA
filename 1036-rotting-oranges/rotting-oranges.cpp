class Solution {
public:
    int rows[4]={-1,0,1,0};
    int cols[4]={0,1,0,-1};
    bool isValid(int newRow,int newCol,int m,int n,vector<vector<int>> &time,vector<vector<int>>& grid)
    {
        return newRow>=0 && newRow<m && newCol>=0 && newCol<n && grid[newRow][newCol]==1 && time[newRow][newCol]==-1;
    }
    void bfs(vector<vector<int>>& grid,int m,int n,queue<pair<int,int>> &rotten,int &fresh,int &ans,vector<vector<int>> &time)
    {
        while(!rotten.empty() && fresh>0)
        {
            pair<int,int> p=rotten.front();
            rotten.pop();
            for(int i=0;i<4;i++)
            {
                int newRow=p.first + rows[i];
                int newCol=p.second + cols[i];
                if(isValid(newRow,newCol,m,n,time,grid)) //make it rotten
                {
                    rotten.push({newRow,newCol});
                    time[newRow][newCol]=time[p.first][p.second]+1;
                    ans=max(ans,time[newRow][newCol]);
                    fresh--;
                }                    
            }
        }
        return;
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int fresh=0, ans=0;
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>> rotten;
        vector<vector<int>> time(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2) //rotten orange
                {
                    pair<int,int> p = {i,j};
                    rotten.push(p);
                    time[i][j]=0;
                }
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(fresh==0)
            return 0;
        if(rotten.empty())
            return -1;

        bfs(grid,m,n,rotten,fresh,ans,time);

        return fresh>0 ? -1 : ans;
    }
};