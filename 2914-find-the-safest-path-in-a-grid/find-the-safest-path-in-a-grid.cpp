class Solution {
private:
    int rows[4] = {-1,0,1,0};
    int cols[4] = {0,1,0,-1};
    struct Cell{
        int r,c,d;
        Cell(int i,int j,int dis){
            r = i;
            c = j;
            d = dis;
        }
    };
    bool isValid(int i,int j,int r,int c,vector<vector<bool>>&visited)
    {
        return i>=0 && i<r && j>=0 && j<c && !visited[i][j];
    }
    bool existsPath(int dis,vector<vector<int>>& grid)
    {
        if(dis==0) //there is always a path with distance 0--->coz there is at least 1 thief
            return true;
        if(grid[0][0]<dis || grid[grid.size()-1][grid.size()-1]<dis)
            return false;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid.size(),false));
        queue<Cell> q;
        q.push(Cell(0,0,grid[0][0]));
        visited[0][0] = true;
        while(!q.empty())
        {
            Cell curr = q.front();
            q.pop();
            for(int j=0;j<4;j++)
            {
                int newRow = curr.r + rows[j];
                int newCol = curr.c + cols[j];
                if(isValid(newRow,newCol,grid.size(),grid.size(),visited))
                {
                    if(grid[newRow][newCol]<dis) //cannot take this cell in p
                        continue;
                    if(newRow==grid.size()-1 && newCol==grid.size()-1)
                        return true;
                    visited[newRow][newCol] = true;
                    q.push(Cell(newRow,newCol,grid[newRow][newCol]));
                }
            }
        }
        return false;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        int x = grid.size();
        vector<vector<bool>> visited(x,vector<bool>(x,false));
        queue<Cell> q;
        int minDis = 0, maxDis = 0;
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(grid[i][j]==1){
                    q.push(Cell(i,j,0));
                    grid[i][j] = 0;
                    visited[i][j] = true;
                }
            }
        }
        // calculate manhattan distance of nearest thief from each cell
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Cell curr = q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int newRow = curr.r + rows[j];
                    int newCol = curr.c + cols[j];
                    if(isValid(newRow,newCol,x,x,visited)){
                        visited[newRow][newCol] = true;
                        grid[newRow][newCol] = curr.d + 1;
                        q.push(Cell(newRow, newCol, curr.d+1));
                        maxDis = max(maxDis, curr.d+1);
                    }
                }
            }
        }
        int low=0, high=maxDis;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(existsPath(mid,grid))
                low=mid+1;
            else
                high=mid-1;
        }
        return high;
    }
};