class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0] || grid[m-1][n-1])
            return 0;

        vector<int> prevRow(n,0);
        prevRow[0]=1;
        for(int j=1;j<n;j++)
        {
            if(grid[0][j]) //obstacle
                break;
            prevRow[j] = 1;
        }
        for(int i=1;i<m;i++)
        {
            vector<int> currRow(n,0);
            if(!grid[i][0] && prevRow[0]==1)
                currRow[0] = 1;
            for(int j=1;j<n;j++)
            {
                if(grid[i][j])
                    currRow[j] = 0;
                else
                    currRow[j] = currRow[j-1] + prevRow[j];
            }
            prevRow=currRow;
        }
        return prevRow[n-1];
    }
};