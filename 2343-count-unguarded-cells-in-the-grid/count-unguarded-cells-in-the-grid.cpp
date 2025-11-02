class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        int marked=0;
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(vector<int> v : guards)
        {
            grid[v[0]][v[1]]=1; //guard
        }
        for(vector<int> v : walls)
        {
            grid[v[0]][v[1]]=2; // wall
        }
        // if a cell has a guard then we won't mark it
        //first proceed columnwise
        for(vector<int> v : guards)
        {
            int row=v[0], col=v[1];
            for(int i=row-1;i>=0;i--)
            {
                //in case of wall, no further going, in case of guard, above guard will handle
                if(grid[i][col]==2 || grid[i][col]==1)
                    break;
                else if(grid[i][col]!=-1){
                    grid[i][col]=-1; 
                    marked++;
                }
            }
            for(int i=row+1;i<m;i++)
            {
                //in case of wall, no further going, in case of guard, above guard will handle
                if(grid[i][col]==2 || grid[i][col]==1)
                    break;
                else if(grid[i][col]!=-1){
                    grid[i][col]=-1; 
                    marked++;
                }
            }
        }
        //then proceed rowwise
        for(vector<int> v : guards)
        {
            int row=v[0], col=v[1];
            for(int i=col-1;i>=0;i--)
            {
                //in case of wall, no further going; in case of guard, left guard will handle
                if(grid[row][i]==2 || grid[row][i]==1)
                    break;
                else if(grid[row][i]!=-1){
                    grid[row][i]=-1; 
                    marked++;
                }
            }
            for(int i=col+1;i<n;i++)
            {
                if(grid[row][i]==2 || grid[row][i]==1)
                    break;
                else if(grid[row][i]!=-1){
                    grid[row][i]=-1; 
                    marked++;
                }
            }
        }
        return m*n - marked - walls.size() - guards.size();
    }
};