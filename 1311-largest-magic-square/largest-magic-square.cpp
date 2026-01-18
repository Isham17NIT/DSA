class Solution {
private:
    bool isMagicSquare(vector<vector<int>>& grid, int x, int y, int len)
    {
        int rowSum=0, colSum=0;
        int diag1Sum=0, diag2Sum=0;
        for(int i=0;i<len;i++)
        {
            rowSum += grid[x][y+i];
            colSum += grid[x+i][y];
            diag1Sum += grid[x+i][y+i];
            diag2Sum += grid[x+i][y+len-1-i];
        }
        if(rowSum!=colSum || rowSum!=diag1Sum || rowSum!=diag2Sum)
            return false;

        for(int i=1;i<len;i++) // rowNum or colNum
        {
            int currRowSum=grid[x+i][y], currColSum=grid[x][y+i];
            for(int j=1;j<len;j++)
            {
                currRowSum += grid[x+i][y+j];
                currColSum += grid[x+j][y+i];
            }
            if(currRowSum!=rowSum || currColSum!=rowSum)
                return false;
        }
        return true;
    }
    bool hasMagicSquare(vector<vector<int>>& grid, int m, int n, int len)
    {
        // len means we have to look for square of side = len
        for(int i=0;i<=m-len;i++)
        {
            for(int j=0;j<=n-len;j++)
            {
                if(isMagicSquare(grid, i, j, len))
                    return true;
            }
        }
        return false;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) 
    {
        int ans = 1;
        int m = grid.size(), n = grid[0].size();

        // check all squares in the matrix and find the largest one
        for(int i=min(m, n);i>=2;i--)
        {
            if(hasMagicSquare(grid, m, n, i))
                return i;
        }
        return ans;
    }
};