class Solution 
{
public:
    int countNegatives(vector<vector<int>>& grid) 
    {
        int r=grid.size(), c=grid[0].size();
        int ans=0, i=r-1, j=0;
        while(i>=0 && j>=0 && j<c)
        {
            if(grid[i][j] < 0)
            {
                ans+=(c-j);
                i--;
            }
            else
                j++;
        }
        return ans;
    }
};