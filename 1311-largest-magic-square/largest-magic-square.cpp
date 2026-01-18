class Solution {
private:
    bool isMagicSquare(int x, int y, int m, int n, int len, vector<vector<int>>& rowPrefixSum, vector<vector<int>>& colPrefixSum, vector<vector<int>>& grid)
    {
        int rowSum = y==0 ? rowPrefixSum[x][y+len-1] : rowPrefixSum[x][y+len-1] - rowPrefixSum[x][y-1];
        int colSum = x==0 ? colPrefixSum[x+len-1][y] : colPrefixSum[x+len-1][y] - colPrefixSum[x-1][y];

        int diag1Sum=0, diag2Sum=0;
        for(int i=0;i<len;i++)
        {
            diag1Sum += grid[x+i][y+i];
            diag2Sum += grid[x+i][y+len-1-i];
        }
        if(rowSum!=colSum || rowSum!=diag1Sum || rowSum!=diag2Sum)
            return false;

        for(int i=1;i<len;i++) // rowNum or colNum
        {
            int currRowSum = y==0 ? rowPrefixSum[x+i][y+len-1] : rowPrefixSum[x+i][y+len-1] - rowPrefixSum[x+i][y-1];
            int currColSum = x==0 ? colPrefixSum[x+len-1][y+i] : colPrefixSum[x+len-1][y+i] - colPrefixSum[x-1][y+i];
        
            if(currRowSum!=rowSum || currColSum!=rowSum)
                return false;
        }
        return true;
    }
    bool hasMagicSquare(int m, int n, int len, vector<vector<int>>& rowPrefixSum, vector<vector<int>>& colPrefixSum, vector<vector<int>>& grid)
    {
        // len means we have to look for square of side = len
        for(int i=0;i<=m-len;i++)
        {
            for(int j=0;j<=n-len;j++)
            {
                if(isMagicSquare(i, j, m, n, len, rowPrefixSum, colPrefixSum, grid))
                    return true;
            }
        }
        return false;
    }
public:
    int largestMagicSquare(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rowPrefixSum(m, vector<int>(n, 0));
        vector<vector<int>> colPrefixSum(m, vector<int>(n, 0));

        for(int i=0;i<m;i++)  // O(m*n)
        {
            for(int j=0;j<n;j++)
            {
                rowPrefixSum[i][j] = j==0 ? grid[i][j] : grid[i][j] + rowPrefixSum[i][j-1]; 
                colPrefixSum[i][j] = i==0 ? grid[i][j] : grid[i][j] + colPrefixSum[i-1][j];
            }
        }

        // check all squares in the matrix and find the largest one
        for(int i=min(m, n);i>=2;i--) 
        {
            if(hasMagicSquare(m, n, i, rowPrefixSum, colPrefixSum, grid))
                return i;
        }
        return 1;
    }
};