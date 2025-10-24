class Solution {
private:
    vector<vector<int>> dirs={{-1,0},{0,1},{1,0},{0,-1}};
    bool isPossible(int i,int j,vector<vector<int>> &grid, int time, vector<vector<bool>> &visited)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size() || visited[i][j] || grid[i][j]>time)
            return false;
        if(i==grid.size()-1 && j==grid.size()-1) //dest
            return true;
        visited[i][j]=true;
        for(int k=0;k<4;k++)
        {
            if(isPossible(i+dirs[k][0], j+dirs[k][1], grid, time, visited))
                return true;
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
            if(isPossible(0,0,grid,mid,visited))
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