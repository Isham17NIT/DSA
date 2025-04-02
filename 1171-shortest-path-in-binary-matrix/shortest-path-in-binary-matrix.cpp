class Solution {
private:
    int rows[8]={-1,0,1,0,-1,1,1,-1};
    int cols[8]={0,1,0,-1,1,1,-1,-1};
    bool isValid(int i,int j, int n)
    {
        return i>=0 && j>=0 && i<n && j<n;
    }
    int applyBFS(vector<vector<int>>& grid)
    {
        int n=grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n,false));
        vector<vector<int>> distance(n,vector<int>(n,0));

        queue<pair<int,int>> q; 
        q.push({0,0});
        distance[0][0]=1;
        visited[0][0]=true;

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            if(p.first==n-1 && p.second==n-1)
                return distance[n-1][n-1];
            for(int i=0;i<8;i++)
            {
                int newRow=p.first+rows[i];
                int newCol=p.second+cols[i];
                if(isValid(newRow,newCol,n) && !visited[newRow][newCol] && grid[newRow][newCol]==0)
                {
                    q.push({newRow,newCol});
                    visited[newRow][newCol]=true;
                    distance[newRow][newCol] = distance[p.first][p.second] + 1;
                }
            }
        }
        return -1;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        return applyBFS(grid);
    }
};