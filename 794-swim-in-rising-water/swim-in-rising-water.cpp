class Solution {
private:
    vector<vector<int>> dirs={{-1,0},{0,1},{1,0},{0,-1}};
    bool isValid(int i,int j, int n, vector<vector<bool>> &visited)
    {
        if(i<0 || j<0 || i>=n || j>=n || visited[i][j])
            return false;
        return true;
    }
    bool isPossible(vector<vector<int>> &grid, int time, vector<vector<bool>> &visited)
    {
        int n=grid.size();
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=true;
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            if(curr.first==n-1 && curr.second==n-1)
                return true;
            for(int k=0;k<4;k++)
            {
                int newRow=curr.first+dirs[k][0];
                int newCol=curr.second+dirs[k][1];
                if(isValid(newRow, newCol, n, visited) && grid[newRow][newCol]<=time)
                {
                    visited[newRow][newCol]=true;
                    q.push({newRow, newCol});
                }
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int low=grid[0][0], high=n*n-1;
        int ans=INT_MAX;
        while(low<=high) 
        {
            int mid=(low+high)>>1;
            vector<vector<bool>> visited(n,vector<bool>(n,false));
            if(isPossible(grid,mid,visited))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};